#include "stakekit_plugin.h"

void handle_finalize(void *parameters) {
    ethPluginFinalize_t *msg = (ethPluginFinalize_t *) parameters;
    plugin_parameters_t *context = (plugin_parameters_t *) msg->pluginContext;

    msg->uiType = ETH_UI_TYPE_GENERIC;

    if (context->valid) {
        switch (context->selectorIndex) {
            case CLAIM_SELF_APECOIN:
                msg->numScreens = 0;
                break;
            case CLAIM_TOKENS:
                msg->numScreens = 1;
                context->decimals_sent = 0;
                strlcpy(context->ticker_sent, DEFAULT_TICKER, sizeof(context->ticker_sent));
                break;
            case STAKE:
                msg->numScreens = 1;
                context->decimals_sent = DEFAULT_DECIMAL;
                strlcpy(context->ticker_sent,
                        STAKEWISE_STAKED_ETH2_TICKER,
                        sizeof(context->ticker_sent));
                break;
            case DEPOSIT_SELF_APECOIN:
                msg->numScreens = 1;
                context->decimals_sent = DEFAULT_DECIMAL;
                strlcpy(context->ticker_sent, APE_TICKER, sizeof(context->ticker_sent));
                break;
            case WITHDRAW_SELF_APECOIN:
                msg->numScreens = 1;
                context->decimals_received = DEFAULT_DECIMAL;
                strlcpy(context->ticker_received, APE_TICKER, sizeof(context->ticker_received));
                break;
            case SWAP_TO:
                msg->numScreens = 1;
                context->decimals_received = DEFAULT_DECIMAL;
                strlcpy(context->ticker_received,
                        ROCKET_POOL_ETH_TICKER,
                        sizeof(context->ticker_received));
                break;
            case SUBMIT_MATIC_LIDO:
            case REQUEST_WITHDRAW:
                msg->numScreens = 2;
                context->decimals_sent = DEFAULT_DECIMAL;
                strlcpy(context->ticker_sent, MATIC_TICKER, sizeof(context->ticker_sent));
                break;
            case SWAP_FROM:
                msg->numScreens = 2;
                context->decimals_received = DEFAULT_DECIMAL;
                strlcpy(context->ticker_received, WETH_TICKER, sizeof(context->ticker_received));
                context->decimals_sent = DEFAULT_DECIMAL;
                strlcpy(context->ticker_sent, ROCKET_POOL_ETH_TICKER, sizeof(context->ticker_sent));
                break;
            default:
                msg->numScreens = 1;
                break;
        }

        msg->result = ETH_PLUGIN_RESULT_OK;
    } else {
        PRINTF("Context not valid\n");
        msg->result = ETH_PLUGIN_RESULT_FALLBACK;
    }
}
