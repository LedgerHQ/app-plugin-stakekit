#include "stakekit_plugin.h"

// Called once to init.
void handle_init_contract(void *parameters) {
    ethPluginInitContract_t *msg = (ethPluginInitContract_t *) parameters;

    if (msg->interfaceVersion != ETH_PLUGIN_INTERFACE_VERSION_LATEST) {
        msg->result = ETH_PLUGIN_RESULT_UNAVAILABLE;
        return;
    }

    if (msg->pluginContextLength < sizeof(plugin_parameters_t)) {
        msg->result = ETH_PLUGIN_RESULT_ERROR;
        return;
    }

    plugin_parameters_t *context = (plugin_parameters_t *) msg->pluginContext;
    memset(context, 0, sizeof(*context));
    context->valid = 1;

    // Determine a function to call
    size_t i;
    for (i = 0; i < NUM_STAKEKIT_SELECTORS; i++) {
        if (memcmp((uint8_t *) PIC(STAKEKIT_SELECTORS[i]), msg->selector, SELECTOR_SIZE) == 0) {
            context->selectorIndex = i;
            break;
        }
    }

    if (i == NUM_STAKEKIT_SELECTORS) {
        // Selector was not found
        msg->result = ETH_PLUGIN_RESULT_ERROR;
        return;
    }

    // Set `next_param` to be the first field we expect to parse.
    switch (context->selectorIndex) {
        case DEPOSIT_SELF_APECOIN:
        case SUBMIT_MATIC_LIDO:
        case REQUEST_WITHDRAW:
        case CLAIM_TOKENS:
        case BUY_VOUCHER:
        case SELL_VOUCHER_NEW:
        case ENTER:
        case LEAVE:
        case UNLOCK:
        case AVALANCHE_REQUEST_UNLOCK:
        case AVALANCHE_REDEEM_2:
        case AVALANCHE_REDEEM_OVERDUE_SHARES_2:
        case PARASPACE_WITHDRAW:
        case YEARN_VAULT_DEPOSIT_2:
        case YEARN_VAULT_DEPOSIT_3:
        case YEARN_VAULT_WITHDRAW_2:
        case YEARN_VAULT_WITHDRAW_3:
        case ANGLE_WITHDRAW:
            context->next_param = AMOUNT_SENT;
            break;
        case WITHDRAW_SELF_APECOIN:
            context->next_param = AMOUNT_RECEIVED;
            break;
        case CLAIM_SELF_APECOIN:
        case STAKE:
        case CREATE_ACCOUNT:
        case LOCK:
        case WITHDRAW_REWARDS:
        case AVALANCHE_SUBMIT:
        case AVALANCHE_REDEEM_1:
        case AVALANCHE_REDEEM_OVERDUE_SHARES_1:
        case YEARN_VAULT_DEPOSIT_1:
        case YEARN_VAULT_WITHDRAW_1:
            context->next_param = NONE;
            break;
        case SUBMIT_ETH_LIDO:
        case PARASPACE_DEPOSIT:
        case GRT_DELEGATE:
        case GRT_UNDELEGATE:
        case GRT_WITHDRAW_DELEGATED:
        case COMET_CLAIM:
        case VOTE:
        case REVOKE_ACTIVE:
            context->next_param = RECIPIENT;
            break;
        case MORPHO_SUPPLY_1:
        case MORPHO_SUPPLY_2:
        case MORPHO_SUPPLY_3:
        case COMET_SUPPLY:
        case TRANSFER_OUT:
        case AAVE_SUPPLY:
            context->next_param = TOKEN_SENT;
            break;
        case MORPHO_WITHDRAW_1:
        case MORPHO_WITHDRAW_2:
        case COMET_WITHDRAW:
            context->next_param = TOKEN_RECEIVED;
            break;
        case SWAP_TO:
        case SWAP_FROM:
            context->skip = 3;
            context->next_param = AMOUNT_RECEIVED;
            break;
        case UNSTAKE_CLAIM_TOKENS_NEW:
            context->next_param = UNBOUND_NONCE;
            break;
        case LIDO_REQUEST_WITHDRAWALS:
            // Skipping the _amounts parameter offset (constant)
            context->skip = 1;
            context->next_param = RECIPIENT;
            break;
        case LIDO_CLAIM_WITHDRAWALS:
            // Skipping the _requestIds parameter offset (constant)
            context->skip = 1;
            context->next_param = SAVE_OFFSET;
            break;
        default:
            PRINTF("Missing selectorIndex\n");
            msg->result = ETH_PLUGIN_RESULT_ERROR;
            return;
    }

    msg->result = ETH_PLUGIN_RESULT_OK;
}
