#include <stdbool.h>
#include "stakekit_plugin.h"

// Set UI for the "Send" screen.
// Each methods sets the title and the message to be displayed on the screen.
static bool set_send_ui(ethQueryContractUI_t *msg, plugin_parameters_t *context) {
    switch (context->selectorIndex) {
        case DEPOSIT_SELF_APECOIN:
        case SWAP_FROM:
        case SUBMIT_MATIC_LIDO:
        case REQUEST_WITHDRAW:
        case BUY_VOUCHER:
        case BUY_VOUCHER_POL:
        case SELL_VOUCHER_NEW:
        case SELL_VOUCHER_NEW_POL:
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
        case VIC_WITHDRAW:
            strlcpy(msg->title, "Index", msg->titleLength);
            break;
        case ANGLE_WITHDRAW:
            strlcpy(msg->title, "Assets", msg->titleLength);
            break;
        case LIDO_REQUEST_WITHDRAWALS:
            if (context->nb_requests >= 2) {
                strlcpy(msg->title, "Total Amounts", msg->titleLength);
            } else {
                strlcpy(msg->title, "Amount", msg->titleLength);
            }
            break;
        case LIDO_CLAIM_WITHDRAWALS:
            strlcpy(msg->title, "Request ID", msg->titleLength);
            break;
        case VIC_UNVOTE:
            strlcpy(msg->title, "Cap", msg->titleLength);
            break;
        case CLAIM:
            strlcpy(msg->title, "Request Number", msg->titleLength);
            break;
        case DELEGATE:
            strlcpy(msg->title, "Vote Power", msg->titleLength);
            break;
        default:
            PRINTF("Unhandled selector Index: %d\n", context->selectorIndex);
            return false;
    }

    // Convert to string.
    if (!amountToString(context->amount_sent,
                        INT256_LENGTH,
                        context->decimals_sent,
                        context->ticker_sent,
                        msg->msg,
                        msg->msgLength)) {
        return false;
    }
    PRINTF("AMOUNT SENT: %s\n", msg->msg);
    return true;
}

// Same as the "set_send_ui" function. However the value is extracted from the pluginSharedRO.
static bool set_send_value_ui(ethQueryContractUI_t *msg, plugin_parameters_t *context) {
    switch (context->selectorIndex) {
        case STAKE:
            strlcpy(msg->title, "Send", msg->titleLength);
            break;
        default:
            PRINTF("Unhandled selector Index: %d\n", context->selectorIndex);
            return false;
    }

    if (msg->pluginSharedRO == NULL) {
        PRINTF("Error: msg->pluginSharedRO is NULL\n");
        return false;
    }
    if (msg->pluginSharedRO->txContent == NULL) {
        PRINTF("Error: msg->pluginSharedRO->txContent is NULL\n");
        return false;
    }

    // Convert to string.
    if (!amountToString(msg->pluginSharedRO->txContent->value.value,
                        msg->pluginSharedRO->txContent->value.length,
                        context->decimals_sent,
                        context->ticker_sent,
                        msg->msg,
                        msg->msgLength)) {
        return false;
    }
    PRINTF("AMOUNT SENT: %s\n", msg->msg);
    return true;
}

// Set UI for "Send 2" screen.
// Each methods sets the title and the message to be displayed on the screen.
static bool set_send_2_ui(ethQueryContractUI_t *msg, plugin_parameters_t *context) {
    switch (context->selectorIndex) {
        case LIDO_CLAIM_WITHDRAWALS:
            strlcpy(msg->title, "Request ID", msg->titleLength);
            break;
        default:
            PRINTF("Unhandled selector Index: %d\n", context->selectorIndex);
            msg->result = ETH_PLUGIN_RESULT_ERROR;
            return false;
    }

    amountToString(context->contract_address,  // Location of the 2nd request ID.
                   ADDRESS_LENGTH,
                   context->decimals_sent,
                   context->ticker_sent,
                   msg->msg,
                   msg->msgLength);
    return true;
}

// Set UI for "Receive" screen.
// Each methods sets the title and the message to be displayed on the screen.
static bool set_receive_ui(ethQueryContractUI_t *msg, plugin_parameters_t *context) {
    switch (context->selectorIndex) {
        case WITHDRAW_SELF_APECOIN:
        case SWAP_TO:
        case SWAP_FROM:
        case MORPHO_WITHDRAW_1:
        case MORPHO_WITHDRAW_2:
        case COMET_WITHDRAW:
            strlcpy(msg->title, "Receive", msg->titleLength);
            break;
        case LIDO_CLAIM_WITHDRAWALS:
            strlcpy(msg->title, "Hint", msg->titleLength);
            break;
        case VIC_WITHDRAW:
            strlcpy(msg->title, "Block Number", msg->titleLength);
            break;
        default:
            PRINTF("Unhandled selector Index: %d\n", context->selectorIndex);
            return false;
    }

    // Convert to string.
    if (!amountToString(context->amount_received,
                        INT256_LENGTH,
                        context->decimals_received,
                        context->ticker_received,
                        msg->msg,
                        msg->msgLength)) {
        return false;
    }
    PRINTF("AMOUNT RECEIVED: %s\n", msg->msg);
    return true;
}

// Set UI for "Receive 2" screen.
// Each methods sets the title and the message to be displayed on the screen.
static bool set_receive_2_ui(ethQueryContractUI_t *msg, plugin_parameters_t *context) {
    switch (context->selectorIndex) {
        case LIDO_CLAIM_WITHDRAWALS:
            strlcpy(msg->title, "Hint", msg->titleLength);
            break;
        default:
            PRINTF("Unhandled selector Index: %d\n", context->selectorIndex);
            msg->result = ETH_PLUGIN_RESULT_ERROR;
            return false;
    }

    amountToString(context->recipient,  // Location of the 2nd hint.
                   ADDRESS_LENGTH,
                   context->decimals_sent,
                   context->ticker_sent,
                   msg->msg,
                   msg->msgLength);
    return true;
}

// Utility function to print an address to the UI.
static bool print_address(ethQueryContractUI_t *msg, uint8_t *address) {
    if (msg == NULL || msg->msgLength <= MIN_MSG_LENGTH) {
        return false;
    }
    // Prefix the address with `0x`.
    msg->msg[0] = '0';
    msg->msg[1] = 'x';

    // We need a random chainID for legacy reasons with `getEthAddressStringFromBinary`.
    // Setting it to `0` will make it work with every chainID :)
    uint64_t chainid = 0;

    // Get the string representation of the address stored in `context->beneficiary`. Put it in
    // `msg->msg`.
    return getEthAddressStringFromBinary(
        address,
        msg->msg + 2,  // +2 here because we've already prefixed with '0x'.
        chainid);
}

// Set UI for "Recipient" screen.
// Each methods sets the title and the message to be displayed on the screen.
static bool set_recipient_ui(ethQueryContractUI_t *msg, plugin_parameters_t *context) {
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
        case ANGLE_WITHDRAW:
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
        case LIDO_REQUEST_WITHDRAWALS:
            strlcpy(msg->title, "Owner", msg->titleLength);
            break;
        case VOTE:
        case REVOKE_ACTIVE:
            strlcpy(msg->title, "Validator Group", msg->titleLength);
            break;
        case VIC_VOTE:
        case VIC_RESIGN:
        case VIC_UNVOTE:
            strlcpy(msg->title, "Candidate", msg->titleLength);
            break;
        case CLAIM:
        case DELEGATE:
            strlcpy(msg->title, "Operator", msg->titleLength);
            break;
        case REDELEGATE:
            strlcpy(msg->title, "Old Operator", msg->titleLength);
            break;
        default:
            PRINTF("Unhandled selector Index: %d\n", context->selectorIndex);
            return false;
    }

    return print_address(msg, context->recipient);
}

// Set UI for "Recipient 2" screen. When having more than one recipient.
// The recipient address is saved in the contract_address
// Each methods sets the title and the message to be displayed on the screen.
static bool set_recipient_2_ui(ethQueryContractUI_t *msg, plugin_parameters_t *context) {
    switch (context->selectorIndex) {
        case COMET_CLAIM:
            strlcpy(msg->title, "Comet Protocol", msg->titleLength);
            break;
        case VOTE:
        case REVOKE_ACTIVE:
            strlcpy(msg->title, "Lesser Group", msg->titleLength);
            break;
        case ANGLE_WITHDRAW:
            strlcpy(msg->title, "Owner", msg->titleLength);
            break;
        case REDELEGATE:
            strlcpy(msg->title, "New Operator", msg->titleLength);
            break;
        default:
            PRINTF("Unhandled selector Index: %d\n", context->selectorIndex);
            return false;
    }

    return print_address(msg, context->contract_address);
}

// Set UI for "Recipient 2" screen. When having more than two recipients.
// The recipient address is saved in the amount_received
// Each methods sets the title and the message to be displayed on the screen.
static bool set_recipient_3_ui(ethQueryContractUI_t *msg, plugin_parameters_t *context) {
    switch (context->selectorIndex) {
        case VOTE:
        case REVOKE_ACTIVE:
            strlcpy(msg->title, "Greater Group", msg->titleLength);
            break;
        default:
            PRINTF("Unhandled selector Index: %d\n", context->selectorIndex);
            return false;
    }

    return print_address(msg, context->amount_received);
}

// Set UI for smart contract address screen.
// Each methods sets the title and the message to be displayed on the screen.
static bool set_smart_contract_ui(ethQueryContractUI_t *msg, plugin_parameters_t *context) {
    switch (context->selectorIndex) {
        case CLAIM_SELF_APECOIN:
        case CREATE_ACCOUNT:
        case LOCK:
        case WITHDRAW_REWARDS:
        case WITHDRAW_REWARDS_POL:
        case AVALANCHE_SUBMIT:
        case AVALANCHE_REDEEM_1:
        case AVALANCHE_REDEEM_OVERDUE_SHARES_1:
        case YEARN_VAULT_DEPOSIT_1:
        case YEARN_VAULT_WITHDRAW_1:
            strlcpy(msg->title, "Smart Contract", msg->titleLength);
            break;
        default:
            PRINTF("Unhandled selector Index: %d\n", context->selectorIndex);
            return false;
    }

    if (msg->pluginSharedRO == NULL) {
        PRINTF("Error: msg->pluginSharedRO is NULL\n");
        return false;
    }
    if (msg->pluginSharedRO->txContent == NULL) {
        PRINTF("Error: msg->pluginSharedRO->txContent is NULL\n");
        return false;
    }

    return print_address(msg, msg->pluginSharedRO->txContent->destination);
}

// Set UI for unbound nonce boolean screen.
// Each methods sets the title and the message to be displayed on the screen.
static bool set_unbound_nonce_ui(ethQueryContractUI_t *msg, plugin_parameters_t *context) {
    switch (context->selectorIndex) {
        case UNSTAKE_CLAIM_TOKENS_NEW:
        case UNSTAKE_CLAIM_TOKENS_NEW_POL:
            strlcpy(msg->title, "Unbound Nonce", msg->titleLength);
            break;
        default:
            PRINTF("Unhandled selector Index: %d\n", context->selectorIndex);
            return false;
    }
    if (context->unbound_nonce == 0) {
        strlcpy(msg->msg, "False", msg->msgLength);
    } else {
        strlcpy(msg->msg, "True", msg->msgLength);
    }
    return true;
}

// Set UI for "Warning" screen.
static bool set_warning_ui(ethQueryContractUI_t *msg,
                           const plugin_parameters_t *context __attribute__((unused))) {
    strlcpy(msg->title, "WARNING", msg->titleLength);
    strlcpy(msg->msg, "Unknown token", msg->msgLength);
    return true;
}

// Set UI for "Vote Power" screen.
static bool set_delegate_vote_power_ui(ethQueryContractUI_t *msg,
                                       plugin_parameters_t *context __attribute__((unused))) {
    strlcpy(msg->title, "Vote Power", msg->titleLength);
    if (ADDRESS_IS_NULL(context->amount_sent)) {
        strlcpy(msg->msg, "False", msg->msgLength);
    } else {
        strlcpy(msg->msg, "True", msg->msgLength);
    }
    return true;
}

// Set UI for the methods needing a send screen.
static screens_t get_screen_amount_sent(ethQueryContractUI_t *msg,
                                        plugin_parameters_t *context __attribute__((unused))) {
    switch (msg->screenIndex) {
        case 0:
            return SEND_SCREEN;
        default:
            return ERROR;
    }
}

// Set UI for the methods needing a receive screen.
static screens_t get_screen_receive(ethQueryContractUI_t *msg,
                                    plugin_parameters_t *context __attribute__((unused))) {
    switch (msg->screenIndex) {
        case 0:
            return RECEIVE_SCREEN;
        default:
            return ERROR;
    }
}

// Set UI for the methods needing a send and recipient screens.
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

// Set UI for the methods needing a send and vote power screens.
static screens_t get_screen_delegate(ethQueryContractUI_t *msg,
                                     plugin_parameters_t *context __attribute__((unused))) {
    switch (msg->screenIndex) {
        case 0:
            return DELEGATE_VOTE_POWER_SCREEN;
        case 1:
            return RECIPIENT_SCREEN;
        default:
            return ERROR;
    }
}

// Set UI for the methods needing a send and vote power screens.
static screens_t get_screen_redelegate(ethQueryContractUI_t *msg,
                                       plugin_parameters_t *context __attribute__((unused))) {
    switch (msg->screenIndex) {
        case 0:
            return DELEGATE_VOTE_POWER_SCREEN;
        case 1:
            return RECIPIENT_SCREEN;
        case 2:
            return RECIPIENT_2_SCREEN;
        default:
            return ERROR;
    }
}

// Set UI for the methods needing a send and recipient screens.
// If the token is not found, we need an additional screen to display a warning message.
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

// Set UI for the methods needing a receive and recipient screens.
// If the token is not found, we need an additional screen to display a warning message.
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

// Set UI for the methods needing 2 recipients screens.
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

// Set UI for the methods needing a send and receive screens.
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

// Set UI for the methods needing a send Value screen.
static screens_t get_screen_value_sent(ethQueryContractUI_t *msg,
                                       plugin_parameters_t *context __attribute__((unused))) {
    switch (msg->screenIndex) {
        case 0:
            return SEND_VALUE_SCREEN;
        default:
            return ERROR;
    }
}

// Set UI for the methods needing a recipient screen.
static screens_t get_screen_recipient(ethQueryContractUI_t *msg,
                                      plugin_parameters_t *context __attribute__((unused))) {
    switch (msg->screenIndex) {
        case 0:
            return RECIPIENT_SCREEN;
        default:
            return ERROR;
    }
}

// Set UI for the methods needing a smart contract screen.
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

// Set UI for the Vote and Revoke methods.
// These methods need 4 screens.
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

// Set UI for the UnstakeClaim method.
// This method needs to display the unbound nonce boolean.
static screens_t get_screen_unstake_claim(ethQueryContractUI_t *msg,
                                          plugin_parameters_t *context __attribute__((unused))) {
    switch (msg->screenIndex) {
        case 0:
            return UNBOUND_NONCE_SCREEN;
        default:
            return ERROR;
    }
}

// Set UI for the Angle Protocol Withdraw method.
static screens_t get_screen_angle_withdraw(ethQueryContractUI_t *msg,
                                           plugin_parameters_t *context __attribute__((unused))) {
    switch (msg->screenIndex) {
        case 0:
            return SEND_SCREEN;
        case 1:
            return RECIPIENT_SCREEN;
        case 2:
            return RECIPIENT_2_SCREEN;
        default:
            return ERROR;
    }
}

// Set UI for the Lido ClaimWithdrawals method.
static screens_t get_screen_lido_claim_withdrawal(ethQueryContractUI_t *msg,
                                                  plugin_parameters_t *context
                                                  __attribute__((unused))) {
    switch (msg->screenIndex) {
        case 0:
            return SEND_SCREEN;
        case 1:
            return RECEIVE_SCREEN;
        case 2:
            return SEND_2_SCREEN;
        case 3:
            return RECEIVE_2_SCREEN;
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
        case BUY_VOUCHER_POL:
        case SELL_VOUCHER_NEW:
        case SELL_VOUCHER_NEW_POL:
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
        case SUBMIT_ETH_LIDO:
        case VIC_VOTE:
        case VIC_RESIGN:
            return get_screen_recipient(msg, context);
        case SUBMIT_MATIC_LIDO:
        case REQUEST_WITHDRAW:
        case PARASPACE_DEPOSIT:
        case PARASPACE_WITHDRAW:
        case GRT_DELEGATE:
        case YEARN_VAULT_DEPOSIT_2:
        case YEARN_VAULT_DEPOSIT_3:
        case YEARN_VAULT_WITHDRAW_2:
        case YEARN_VAULT_WITHDRAW_3:
        case LIDO_REQUEST_WITHDRAWALS:
        case VIC_UNVOTE:
        case CLAIM:
            return get_screen_amount_sent_recipient(msg, context);
        case DELEGATE:
            return get_screen_delegate(msg, context);
        case REDELEGATE:
            return get_screen_redelegate(msg, context);
        case MORPHO_SUPPLY_1:
        case MORPHO_SUPPLY_2:
        case MORPHO_SUPPLY_3:
        case COMET_SUPPLY:
        case TRANSFER_OUT:
        case AAVE_SUPPLY:
            return get_screen_supply(msg, context);
        case SWAP_FROM:
        case VIC_WITHDRAW:
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
        case WITHDRAW_REWARDS_POL:
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
        case UNSTAKE_CLAIM_TOKENS_NEW_POL:
            return get_screen_unstake_claim(msg, context);
        case ANGLE_WITHDRAW:
            return get_screen_angle_withdraw(msg, context);
        case LIDO_CLAIM_WITHDRAWALS:
            return get_screen_lido_claim_withdrawal(msg, context);
        default:
            return ERROR;
    }
    return ERROR;
}

// Set the UI according to the screen that needs to be displayed.
void handle_query_contract_ui(ethQueryContractUI_t *msg) {
    plugin_parameters_t *context = (plugin_parameters_t *) msg->pluginContext;
    bool ret = false;

    (void) memset(msg->title, 0, msg->titleLength);
    (void) memset(msg->msg, 0, msg->msgLength);
    screens_t screen = get_screen(msg, context);
    switch (screen) {
        case SEND_SCREEN:
            ret = set_send_ui(msg, context);
            break;
        case SEND_VALUE_SCREEN:
            ret = set_send_value_ui(msg, context);
            break;
        case RECEIVE_SCREEN:
            ret = set_receive_ui(msg, context);
            break;
        case RECIPIENT_SCREEN:
            ret = set_recipient_ui(msg, context);
            break;
        case RECIPIENT_2_SCREEN:
            ret = set_recipient_2_ui(msg, context);
            break;
        case RECIPIENT_3_SCREEN:
            ret = set_recipient_3_ui(msg, context);
            break;
        case SMART_CONTRACT_SCREEN:
            ret = set_smart_contract_ui(msg, context);
            break;
        case UNBOUND_NONCE_SCREEN:
            ret = set_unbound_nonce_ui(msg, context);
            break;
        case SEND_2_SCREEN:
            ret = set_send_2_ui(msg, context);
            break;
        case RECEIVE_2_SCREEN:
            ret = set_receive_2_ui(msg, context);
            break;
        case DELEGATE_VOTE_POWER_SCREEN:
            ret = set_delegate_vote_power_ui(msg, context);
            break;
        case WARN_SCREEN:
            ret = set_warning_ui(msg, context);
            break;
        default:
            PRINTF("Received an invalid screenIndex %d\n", screen);
            break;
    }
    msg->result = ret ? ETH_PLUGIN_RESULT_OK : ETH_PLUGIN_RESULT_ERROR;
}
