#include "stakekit_plugin.h"

static void handle_swap_from(ethPluginProvideParameter_t *msg, plugin_parameters_t *context) {
    switch (context->next_param) {
        case AMOUNT_RECEIVED:
            copy_parameter(context->amount_received, msg->parameter, INT256_LENGTH);
            context->next_param = AMOUNT_SENT;
            break;
        case AMOUNT_SENT:
            copy_parameter(context->amount_sent, msg->parameter, INT256_LENGTH);
            break;
        default:
            PRINTF("Param not supported\n");
            msg->result = ETH_PLUGIN_RESULT_ERROR;
            break;
    }
}

static void handle_amount_recipient(ethPluginProvideParameter_t *msg,
                                    plugin_parameters_t *context) {
    switch (context->next_param) {
        case AMOUNT_SENT:
            copy_parameter(context->amount_sent, msg->parameter, INT256_LENGTH);
            context->next_param = RECIPIENT;
            break;
        case RECIPIENT:
            copy_address(context->recipient, msg->parameter, ADDRESS_LENGTH);
            break;
        default:
            PRINTF("Param not supported\n");
            msg->result = ETH_PLUGIN_RESULT_ERROR;
            break;
    }
}

void handle_provide_parameter(void *parameters) {
    ethPluginProvideParameter_t *msg = (ethPluginProvideParameter_t *) parameters;
    plugin_parameters_t *context = (plugin_parameters_t *) msg->pluginContext;

    // We use `%.*H`: it's a utility function to print bytes. You first give
    // the number of bytes you wish to print (in this case, `PARAMETER_LENGTH`) and then
    // the address (here `msg->parameter`).
    PRINTF("plugin provide parameter: offset %d\nBytes: %.*H\n",
           msg->parameterOffset,
           PARAMETER_LENGTH,
           msg->parameter);

    msg->result = ETH_PLUGIN_RESULT_OK;
    if (context->skip) {
        // Skip this step and decrease skipping counter.
        context->skip--;
    } else {
        switch (context->selectorIndex) {
            case DEPOSIT_SELF_APECOIN:
            case CLAIM_TOKENS:
                copy_parameter(context->amount_sent, msg->parameter, INT256_LENGTH);
                break;
            case BUY_VOUCHER:
                copy_parameter(context->amount_sent, msg->parameter, INT256_LENGTH);
                context->skip = 1;
                break;
            case WITHDRAW_SELF_APECOIN:
            case SWAP_TO:
                copy_parameter(context->amount_received, msg->parameter, INT256_LENGTH);
                break;
            case SUBMIT_ETH_LIDO:
                copy_address(context->recipient, msg->parameter, ADDRESS_LENGTH);
                break;
            case CLAIM_SELF_APECOIN:
            case STAKE:
                break;
            case SUBMIT_MATIC_LIDO:
            case REQUEST_WITHDRAW:
                handle_amount_recipient(msg, context);
                break;
            case SWAP_FROM:
                handle_swap_from(msg, context);
                break;
            default:
                PRINTF("Selector Index %d not supported\n", context->selectorIndex);
                msg->result = ETH_PLUGIN_RESULT_ERROR;
                break;
        }
    }
}