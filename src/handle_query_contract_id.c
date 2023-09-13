#include "stakekit_plugin.h"

void handle_query_contract_id(void *parameters) {
    ethQueryContractID_t *msg = (ethQueryContractID_t *) parameters;
    plugin_parameters_t *context = (plugin_parameters_t *) msg->pluginContext;

    strlcpy(msg->name, PLUGIN_NAME, msg->nameLength);

    switch (context->selectorIndex) {
        case CLAIM_SELF_APECOIN:
            strlcpy(msg->version, "Claim Self APE coin", msg->versionLength);
            break;
        case DEPOSIT_SELF_APECOIN:
            strlcpy(msg->version, "Deposit Self APE coin", msg->versionLength);
            break;
        case WITHDRAW_SELF_APECOIN:
            strlcpy(msg->version, "Withdraw Self APE coin", msg->versionLength);
            break;
        case SUBMIT_ETH_LIDO:
        case SUBMIT_MATIC_LIDO:
            strlcpy(msg->version, "Submit", msg->versionLength);
            break;
        case SWAP_TO:
            strlcpy(msg->version, "Swap To", msg->versionLength);
            break;
        case SWAP_FROM:
            strlcpy(msg->version, "Swap From", msg->versionLength);
            break;
        case STAKE:
            strlcpy(msg->version, "Stake", msg->versionLength);
            break;
        case REQUEST_WITHDRAW:
            strlcpy(msg->version, "Request Withdraw", msg->versionLength);
            break;
        case CLAIM_TOKENS:
            strlcpy(msg->version, "Claim Tokens", msg->versionLength);
            break;
        case BUY_VOUCHER:
            strlcpy(msg->version, "Buy Voucher", msg->versionLength);
            break;
        case SELL_VOUCHER_NEW:
            strlcpy(msg->version, "Sell Voucher New", msg->versionLength);
            break;
        default:
            PRINTF("Selector Index :%d not supported\n", context->selectorIndex);
            msg->result = ETH_PLUGIN_RESULT_ERROR;
            return;
    }

    msg->result = ETH_PLUGIN_RESULT_OK;
}