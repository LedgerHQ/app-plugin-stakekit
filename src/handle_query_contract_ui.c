#include "stakekit_plugin.h"

// Set UI for the "Send" screen.
static void set_send_ui(ethQueryContractUI_t *msg, plugin_parameters_t *context) {
    switch (context->selectorIndex) {
        case DEPOSIT_SELF_APECOIN:
        case SWAP_FROM:
        case SUBMIT_MATIC_LIDO:
            strlcpy(msg->title, "Send", msg->titleLength);
            break;
        default:
            PRINTF("Unhandled selector Index: %d\n", context->selectorIndex);
            msg->result = ETH_PLUGIN_RESULT_ERROR;
            return;
    }

    // Convert to string.
    amountToString(context->amount_sent,
                   INT256_LENGTH,
                   context->decimals_sent,
                   context->ticker_sent,
                   msg->msg,
                   msg->msgLength);
    PRINTF("AMOUNT SENT: %s\n", msg->msg);
}
static void set_send_value_ui(ethQueryContractUI_t *msg, plugin_parameters_t *context) {
    switch (context->selectorIndex) {
        case STAKE:
            strlcpy(msg->title, "Send", msg->titleLength);
            break;
        default:
            PRINTF("Unhandled selector Index: %d\n", context->selectorIndex);
            msg->result = ETH_PLUGIN_RESULT_ERROR;
            return;
    }

    // Convert to string.
    amountToString(msg->pluginSharedRO->txContent->value.value,
                   msg->pluginSharedRO->txContent->value.length,
                   context->decimals_sent,
                   context->ticker_sent,
                   msg->msg,
                   msg->msgLength);
    PRINTF("AMOUNT SENT: %s\n", msg->msg);
}

// Set UI for "Receive" screen.
static void set_receive_ui(ethQueryContractUI_t *msg, plugin_parameters_t *context) {
    switch (context->selectorIndex) {
        case WITHDRAW_SELF_APECOIN:
        case SWAP_TO:
        case SWAP_FROM:
            strlcpy(msg->title, "Receive", msg->titleLength);
            break;
        default:
            PRINTF("Unhandled selector Index: %d\n", context->selectorIndex);
            msg->result = ETH_PLUGIN_RESULT_ERROR;
            return;
    }

    // Convert to string.
    amountToString(context->amount_received,
                   INT256_LENGTH,
                   context->decimals_received,
                   context->ticker_received,
                   msg->msg,
                   msg->msgLength);
    PRINTF("AMOUNT RECEIVED: %s\n", msg->msg);
}

// Set UI for "Recipient" screen.
static void set_recipient_ui(ethQueryContractUI_t *msg, plugin_parameters_t *context) {
    strlcpy(msg->title, "Recipient", msg->titleLength);

    // Prefix the address with `0x`.
    msg->msg[0] = '0';
    msg->msg[1] = 'x';

    // We need a random chainID for legacy reasons with `getEthAddressStringFromBinary`.
    // Setting it to `0` will make it work with every chainID :)
    uint64_t chainid = 0;

    // Get the string representation of the address stored in `context->beneficiary`. Put it in
    // `msg->msg`.
    getEthAddressStringFromBinary(
        context->recipient,
        msg->msg + 2,  // +2 here because we've already prefixed with '0x'.
        msg->pluginSharedRW->sha3,
        chainid);
}

// Set UI for "Warning" screen.
static void set_warning_ui(ethQueryContractUI_t *msg,
                           const plugin_parameters_t *context __attribute__((unused))) {
    strlcpy(msg->title, "WARNING", msg->titleLength);
    strlcpy(msg->msg, "Unknown token", msg->msgLength);
}

static screens_t get_screen_deposit_self_apecoin(ethQueryContractUI_t *msg,
                                                 plugin_parameters_t *context
                                                 __attribute__((unused))) {
    switch (msg->screenIndex) {
        case 0:
            return SEND_SCREEN;
        default:
            return ERROR;
    }
}

static screens_t get_screen_receive(ethQueryContractUI_t *msg,
                                    plugin_parameters_t *context __attribute__((unused))) {
    switch (msg->screenIndex) {
        case 0:
            return RECEIVE_SCREEN;
        default:
            return ERROR;
    }
}

static screens_t get_screen_submit_eth_lido(ethQueryContractUI_t *msg,
                                            plugin_parameters_t *context __attribute__((unused))) {
    switch (msg->screenIndex) {
        case 0:
            return RECIPIENT_SCREEN;
        default:
            return ERROR;
    }
}

static screens_t get_screen_submit_matic_lido(ethQueryContractUI_t *msg,
                                              plugin_parameters_t *context __attribute__((unused))) {
    switch (msg->screenIndex) {
        case 0:
            return SEND_SCREEN;
        case 1:
            return RECIPIENT_SCREEN;
        default:
            return ERROR;
    }
}

static screens_t get_screen_amount_sent_receive(ethQueryContractUI_t *msg,
                                                plugin_parameters_t *context
                                                __attribute__((unused))) {
    switch (msg->screenIndex) {
        case 0:
            return SEND_SCREEN;
        case 1:
            return RECEIVE_SCREEN;
        default:
            return ERROR;
    }
}

static screens_t get_screen_value_sent(ethQueryContractUI_t *msg,
                                       plugin_parameters_t *context __attribute__((unused))) {
    switch (msg->screenIndex) {
        case 0:
            return SEND_VALUE_SCREEN;
        default:
            return ERROR;
    }
}

// Helper function that returns the enum corresponding to the screen that should be displayed.
static screens_t get_screen(ethQueryContractUI_t *msg,
                            plugin_parameters_t *context __attribute__((unused))) {
    // Remove if not used from here
    bool token_sent_found = context->tokens_found & TOKEN_SENT_FOUND;
    bool token_received_found = context->tokens_found & TOKEN_RECEIVED_FOUND;

    bool both_tokens_found = token_received_found && token_sent_found;
    bool both_tokens_not_found = !token_received_found && !token_sent_found;
    // To here

    switch (context->selectorIndex) {
        case DEPOSIT_SELF_APECOIN:
            return get_screen_deposit_self_apecoin(msg, context);
        case WITHDRAW_SELF_APECOIN:
        case SWAP_TO:
            return get_screen_receive(msg, context);
        case SUBMIT_ETH_LIDO:
            return get_screen_submit_eth_lido(msg, context);
        case SUBMIT_MATIC_LIDO:
            return get_screen_submit_matic_lido(msg, context);
        case SWAP_FROM:
            return get_screen_amount_sent_receive(msg, context);
        case STAKE:
            return get_screen_value_sent(msg, context);
        default:
            return ERROR;
    }
    return ERROR;
}

void handle_query_contract_ui(void *parameters) {
    ethQueryContractUI_t *msg = (ethQueryContractUI_t *) parameters;
    plugin_parameters_t *context = (plugin_parameters_t *) msg->pluginContext;
    memset(msg->title, 0, msg->titleLength);
    memset(msg->msg, 0, msg->msgLength);
    msg->result = ETH_PLUGIN_RESULT_OK;

    screens_t screen = get_screen(msg, context);
    switch (screen) {
        case SEND_SCREEN:
            set_send_ui(msg, context);
            break;
        case SEND_VALUE_SCREEN:
            set_send_value_ui(msg, context);
            break;
        case RECEIVE_SCREEN:
            set_receive_ui(msg, context);
            break;
        case RECIPIENT_SCREEN:
            set_recipient_ui(msg, context);
            break;
        case WARN_SCREEN:
            set_warning_ui(msg, context);
            break;
        default:
            PRINTF("Received an invalid screenIndex %d\n", screen);
            msg->result = ETH_PLUGIN_RESULT_ERROR;
            return;
    }
}
