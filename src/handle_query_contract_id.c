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
            strlcpy(msg->version, "Submit", msg->versionLength);
            break;
        default:
            PRINTF("Selector Index :%d not supported\n", context->selectorIndex);
            msg->result = ETH_PLUGIN_RESULT_ERROR;
            return;
    }

    msg->result = ETH_PLUGIN_RESULT_OK;
}