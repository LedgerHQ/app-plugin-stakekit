#include "stakekit_plugin.h"

// Set UI for the "Send" screen.
static void set_send_ui(ethQueryContractUI_t *msg, plugin_parameters_t *context) {
    switch (context->selectorIndex) {
        case DEPOSIT_SELF_APECOIN:
        case SWAP_FROM:
        case SUBMIT_MATIC_LIDO:
        case REQUEST_WITHDRAW:
        case BUY_VOUCHER:
        case SELL_VOUCHER_NEW:
        case MORPHO_SUPPLY_1:
        case MORPHO_SUPPLY_2:
        case MORPHO_SUPPLY_3:
        case PARASPACE_DEPOSIT:
        case GRT_DELEGATE:
        case ENTER:
        case LEAVE:
        case COMET_SUPPLY:
        case TRANSFER_OUT:
        case AAVE_SUPPLY:
        case PARASPACE_WITHDRAW:
        case YEARN_VAULT_DEPOSIT_2:
        case YEARN_VAULT_DEPOSIT_3:
        case YEARN_VAULT_WITHDRAW_2:
        case YEARN_VAULT_WITHDRAW_3:
            strlcpy(msg->title, "Send", msg->titleLength);
            break;
        case CLAIM_TOKENS:
            strlcpy(msg->title, "Token ID", msg->titleLength);
            break;
        case UNLOCK:
        case VOTE:
            strlcpy(msg->title, "Gold Amount", msg->titleLength);
            break;
        case REVOKE_ACTIVE:
            strlcpy(msg->title, "Votes", msg->titleLength);
            break;
        case AVALANCHE_REQUEST_UNLOCK:
            strlcpy(msg->title, "Shares", msg->titleLength);
            break;
        case AVALANCHE_REDEEM_2:
        case AVALANCHE_REDEEM_OVERDUE_SHARES_2:
            strlcpy(msg->title, "Index", msg->titleLength);
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
        case MORPHO_WITHDRAW_1:
        case MORPHO_WITHDRAW_2:
        case COMET_WITHDRAW:
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
    switch (context->selectorIndex) {
        case SUBMIT_MATIC_LIDO:
        case REQUEST_WITHDRAW:
        case SUBMIT_ETH_LIDO:
        case MORPHO_WITHDRAW_1:
        case MORPHO_WITHDRAW_2:
        case TRANSFER_OUT:
        case AAVE_SUPPLY:
        case YEARN_VAULT_DEPOSIT_3:
        case YEARN_VAULT_WITHDRAW_3:
            strlcpy(msg->title, "Recipient", msg->titleLength);
            break;
        case MORPHO_SUPPLY_1:
        case MORPHO_SUPPLY_3:
        case PARASPACE_DEPOSIT:
            strlcpy(msg->title, "Sender", msg->titleLength);
            break;
        case GRT_DELEGATE:
            strlcpy(msg->title, "Delegate to", msg->titleLength);
            break;
        case GRT_UNDELEGATE:
            strlcpy(msg->title, "Undelegate to", msg->titleLength);
            break;
        case GRT_WITHDRAW_DELEGATED:
            strlcpy(msg->title, "From", msg->titleLength);
            break;
        case COMET_CLAIM:
            strlcpy(msg->title, "Owner", msg->titleLength);
            break;
        case VOTE:
        case REVOKE_ACTIVE:
            strlcpy(msg->title, "Validator Group", msg->titleLength);
            break;
        default:
            PRINTF("Unhandled selector Index: %d\n", context->selectorIndex);
            msg->result = ETH_PLUGIN_RESULT_ERROR;
            return;
    }

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

static void set_recipient_2_ui(ethQueryContractUI_t *msg, plugin_parameters_t *context) {
    switch (context->selectorIndex) {
        case COMET_CLAIM:
            strlcpy(msg->title, "Comet Protocol", msg->titleLength);
            break;
        case VOTE:
        case REVOKE_ACTIVE:
            strlcpy(msg->title, "Lesser Group", msg->titleLength);
            break;
        default:
            PRINTF("Unhandled selector Index: %d\n", context->selectorIndex);
            msg->result = ETH_PLUGIN_RESULT_ERROR;
            return;
    }

    // Prefix the address with `0x`.
    msg->msg[0] = '0';
    msg->msg[1] = 'x';

    // We need a random chainID for legacy reasons with `getEthAddressStringFromBinary`.
    // Setting it to `0` will make it work with every chainID :)
    uint64_t chainid = 0;

    // Get the string representation of the address stored in `context->beneficiary`. Put it in
    // `msg->msg`.
    getEthAddressStringFromBinary(
        context->contract_address_sent,
        msg->msg + 2,  // +2 here because we've already prefixed with '0x'.
        msg->pluginSharedRW->sha3,
        chainid);
}

static void set_recipient_3_ui(ethQueryContractUI_t *msg, plugin_parameters_t *context) {
    switch (context->selectorIndex) {
        case VOTE:
        case REVOKE_ACTIVE:
            strlcpy(msg->title, "Greater Group", msg->titleLength);
            break;
        default:
            PRINTF("Unhandled selector Index: %d\n", context->selectorIndex);
            msg->result = ETH_PLUGIN_RESULT_ERROR;
            return;
    }

    // Prefix the address with `0x`.
    msg->msg[0] = '0';
    msg->msg[1] = 'x';

    // We need a random chainID for legacy reasons with `getEthAddressStringFromBinary`.
    // Setting it to `0` will make it work with every chainID :)
    uint64_t chainid = 0;

    // Get the string representation of the address stored in `context->beneficiary`. Put it in
    // `msg->msg`.
    getEthAddressStringFromBinary(
        context->contract_address_received,
        msg->msg + 2,  // +2 here because we've already prefixed with '0x'.
        msg->pluginSharedRW->sha3,
        chainid);
}

// Set UI for smart contract address screen.
static void set_smart_contract_ui(ethQueryContractUI_t *msg, plugin_parameters_t *context) {
    switch (context->selectorIndex) {
        case CLAIM_SELF_APECOIN:
        case CREATE_ACCOUNT:
        case LOCK:
        case WITHDRAW_REWARDS:
        case AVALANCHE_SUBMIT:
        case AVALANCHE_REDEEM_1:
        case AVALANCHE_REDEEM_OVERDUE_SHARES_1:
        case YEARN_VAULT_DEPOSIT_1:
        case YEARN_VAULT_WITHDRAW_1:
            strlcpy(msg->title, "Smart Contract", msg->titleLength);
            break;
        default:
            PRINTF("Unhandled selector Index: %d\n", context->selectorIndex);
            msg->result = ETH_PLUGIN_RESULT_ERROR;
            return;
    }

    // Prefix the address with `0x`.
    msg->msg[0] = '0';
    msg->msg[1] = 'x';

    // We need a random chainID for legacy reasons with `getEthAddressStringFromBinary`.
    // Setting it to `0` will make it work with every chainID :)
    uint64_t chainid = 0;

    // Get the string representation of the address stored in `context->beneficiary`. Put it in
    // `msg->msg`.
    getEthAddressStringFromBinary(
        msg->pluginSharedRO->txContent->destination,
        msg->msg + 2,  // +2 here because we've already prefixed with '0x'.
        msg->pluginSharedRW->sha3,
        chainid);
}

// Set UI for unbound nonce boolean screen.
static void set_unbound_nonce_ui(ethQueryContractUI_t *msg, plugin_parameters_t *context) {
    switch (context->selectorIndex) {
        case UNSTAKE_CLAIM_TOKENS_NEW:
            strlcpy(msg->title, "Unbound Nonce", msg->titleLength);
            break;
        default:
            PRINTF("Unhandled selector Index: %d\n", context->selectorIndex);
            msg->result = ETH_PLUGIN_RESULT_ERROR;
            return;
    }
    if (context->unbound_nonce == 0) {
        strlcpy(msg->msg, "False", msg->msgLength);
    } else {
        strlcpy(msg->msg, "True", msg->msgLength);
    }
}

// Set UI for "Warning" screen.
static void set_warning_ui(ethQueryContractUI_t *msg,
                           const plugin_parameters_t *context __attribute__((unused))) {
    strlcpy(msg->title, "WARNING", msg->titleLength);
    strlcpy(msg->msg, "Unknown token", msg->msgLength);
}

static screens_t get_screen_amount_sent(ethQueryContractUI_t *msg,
                                        plugin_parameters_t *context __attribute__((unused))) {
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

static screens_t get_screen_amount_sent_recipient(ethQueryContractUI_t *msg,
                                                  plugin_parameters_t *context
                                                  __attribute__((unused))) {
    switch (msg->screenIndex) {
        case 0:
            return SEND_SCREEN;
        case 1:
            return RECIPIENT_SCREEN;
        default:
            return ERROR;
    }
}

static screens_t get_screen_supply(ethQueryContractUI_t *msg,
                                   plugin_parameters_t *context __attribute__((unused))) {
    bool token_sent_found = context->tokens_found & TOKEN_SENT_FOUND;

    switch (msg->screenIndex) {
        case 0:
            if (token_sent_found) {
                return SEND_SCREEN;
            } else {
                return WARN_SCREEN;
            }
        case 1:
            if (token_sent_found) {
                return RECIPIENT_SCREEN;
            } else {
                return SEND_SCREEN;
            }
        case 2:
            if (token_sent_found) {
                return ERROR;
            } else {
                return RECIPIENT_SCREEN;
            }
        default:
            return ERROR;
    }
}

static screens_t get_screen_morpho_withdraw(ethQueryContractUI_t *msg,
                                            plugin_parameters_t *context __attribute__((unused))) {
    bool token_received_found = context->tokens_found & TOKEN_RECEIVED_FOUND;

    switch (msg->screenIndex) {
        case 0:
            if (token_received_found) {
                return RECEIVE_SCREEN;
            } else {
                return WARN_SCREEN;
            }
        case 1:
            if (token_received_found) {
                return RECIPIENT_SCREEN;
            } else {
                return RECEIVE_SCREEN;
            }
        case 2:
            if (token_received_found) {
                return ERROR;
            } else {
                return RECIPIENT_SCREEN;
            }
        default:
            return ERROR;
    }
}

static screens_t get_screen_comet_claim(ethQueryContractUI_t *msg,
                                        plugin_parameters_t *context __attribute__((unused))) {
    switch (msg->screenIndex) {
        case 0:
            return RECIPIENT_SCREEN;
        case 1:
            return RECIPIENT_2_SCREEN;
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

static screens_t get_screen_recipient(ethQueryContractUI_t *msg,
                                      plugin_parameters_t *context __attribute__((unused))) {
    switch (msg->screenIndex) {
        case 0:
            return RECIPIENT_SCREEN;
        default:
            return ERROR;
    }
}

static screens_t get_screen_smart_contract_address(ethQueryContractUI_t *msg,
                                                   plugin_parameters_t *context
                                                   __attribute__((unused))) {
    switch (msg->screenIndex) {
        case 0:
            return SMART_CONTRACT_SCREEN;
        default:
            return ERROR;
    }
}

static screens_t get_screen_vote_revoke(ethQueryContractUI_t *msg,
                                        plugin_parameters_t *context __attribute__((unused))) {
    switch (msg->screenIndex) {
        case 0:
            return RECIPIENT_SCREEN;
        case 1:
            return SEND_SCREEN;
        case 2:
            return RECIPIENT_2_SCREEN;
        case 3:
            return RECIPIENT_3_SCREEN;
        default:
            return ERROR;
    }
}

static screens_t get_screen_unstake_claim(ethQueryContractUI_t *msg,
                                          plugin_parameters_t *context __attribute__((unused))) {
    switch (msg->screenIndex) {
        case 0:
            return UNBOUND_NONCE_SCREEN;
        default:
            return ERROR;
    }
}

// Helper function that returns the enum corresponding to the screen that should be displayed.
static screens_t get_screen(ethQueryContractUI_t *msg,
                            plugin_parameters_t *context __attribute__((unused))) {
    switch (context->selectorIndex) {
        case DEPOSIT_SELF_APECOIN:
        case CLAIM_TOKENS:
        case BUY_VOUCHER:
        case SELL_VOUCHER_NEW:
        case ENTER:
        case LEAVE:
        case UNLOCK:
        case AVALANCHE_REQUEST_UNLOCK:
        case AVALANCHE_REDEEM_2:
        case AVALANCHE_REDEEM_OVERDUE_SHARES_2:
            return get_screen_amount_sent(msg, context);
        case WITHDRAW_SELF_APECOIN:
        case SWAP_TO:
        case COMET_WITHDRAW:
            return get_screen_receive(msg, context);
        case GRT_UNDELEGATE:
        case GRT_WITHDRAW_DELEGATED:
            return get_screen_recipient(msg, context);
        case SUBMIT_ETH_LIDO:
            return get_screen_submit_eth_lido(msg, context);
        case SUBMIT_MATIC_LIDO:
        case REQUEST_WITHDRAW:
        case PARASPACE_DEPOSIT:
        case PARASPACE_WITHDRAW:
        case GRT_DELEGATE:
        case YEARN_VAULT_DEPOSIT_2:
        case YEARN_VAULT_DEPOSIT_3:
        case YEARN_VAULT_WITHDRAW_2:
        case YEARN_VAULT_WITHDRAW_3:
            return get_screen_amount_sent_recipient(msg, context);
        case MORPHO_SUPPLY_1:
        case MORPHO_SUPPLY_2:
        case MORPHO_SUPPLY_3:
        case COMET_SUPPLY:
        case TRANSFER_OUT:
        case AAVE_SUPPLY:
            return get_screen_supply(msg, context);
        case SWAP_FROM:
            return get_screen_amount_sent_receive(msg, context);
        case STAKE:
            return get_screen_value_sent(msg, context);
        case MORPHO_WITHDRAW_1:
        case MORPHO_WITHDRAW_2:
            return get_screen_morpho_withdraw(msg, context);
        case COMET_CLAIM:
            return get_screen_comet_claim(msg, context);
        case CLAIM_SELF_APECOIN:
        case CREATE_ACCOUNT:
        case LOCK:
        case WITHDRAW_REWARDS:
        case AVALANCHE_SUBMIT:
        case AVALANCHE_REDEEM_1:
        case AVALANCHE_REDEEM_OVERDUE_SHARES_1:
        case YEARN_VAULT_DEPOSIT_1:
        case YEARN_VAULT_WITHDRAW_1:
            return get_screen_smart_contract_address(msg, context);
        case VOTE:
        case REVOKE_ACTIVE:
            return get_screen_vote_revoke(msg, context);
        case UNSTAKE_CLAIM_TOKENS_NEW:
            return get_screen_unstake_claim(msg, context);
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
        case RECIPIENT_2_SCREEN:
            set_recipient_2_ui(msg, context);
            break;
        case RECIPIENT_3_SCREEN:
            set_recipient_3_ui(msg, context);
            break;
        case SMART_CONTRACT_SCREEN:
            set_smart_contract_ui(msg, context);
            break;
        case UNBOUND_NONCE_SCREEN:
            set_unbound_nonce_ui(msg, context);
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
