#include "stakekit_plugin.h"

void handle_finalize(void *parameters) {
    ethPluginFinalize_t *msg = (ethPluginFinalize_t *) parameters;
    plugin_parameters_t *context = (plugin_parameters_t *) msg->pluginContext;

    msg->uiType = ETH_UI_TYPE_GENERIC;

    // Initialize the decimals and ticker to default value.
    context->decimals_sent = DEFAULT_DECIMAL;
    strlcpy(context->ticker_sent, DEFAULT_TICKER, sizeof(context->ticker_sent));
    context->decimals_received = DEFAULT_DECIMAL;
    strlcpy(context->ticker_received, DEFAULT_TICKER, sizeof(context->ticker_received));

    if (context->valid) {
        switch (context->selectorIndex) {
            case CLAIM_SELF_APECOIN:
                msg->numScreens = 0;
                break;
            case COMET_CLAIM:
                msg->numScreens = 2;
                break;
            case MORPHO_SUPPLY_1:
            case MORPHO_SUPPLY_3:
            case TRANSFER_OUT:
                msg->numScreens = 2;
                msg->tokenLookup1 = context->contract_address_sent;
                break;
            case MORPHO_SUPPLY_2:
            case COMET_SUPPLY:
                msg->numScreens = 1;
                msg->tokenLookup1 = context->contract_address_sent;
                break;
            case MORPHO_WITHDRAW_1:
            case COMET_WITHDRAW:
                msg->numScreens = 1;
                msg->tokenLookup2 = context->contract_address_received;
                break;
            case MORPHO_WITHDRAW_2:
                msg->numScreens = 2;
                msg->tokenLookup2 = context->contract_address_received;
                break;
            case CLAIM_TOKENS:
            case SELL_VOUCHER_NEW:
                msg->numScreens = 1;
                context->decimals_sent = 0;
                break;
            case ENTER:
                msg->numScreens = 1;
                strlcpy(context->ticker_sent, SUSHI_TICKER, sizeof(context->ticker_sent));
                break;
            case LEAVE:
                msg->numScreens = 1;
                strlcpy(context->ticker_sent, XSUSHI_TICKER, sizeof(context->ticker_sent));
                break;
            case STAKE:
                msg->numScreens = 1;
                strlcpy(context->ticker_sent,
                        STAKEWISE_STAKED_ETH2_TICKER,
                        sizeof(context->ticker_sent));
                break;
            case DEPOSIT_SELF_APECOIN:
                msg->numScreens = 1;
                strlcpy(context->ticker_sent, APE_TICKER, sizeof(context->ticker_sent));
                break;
            case WITHDRAW_SELF_APECOIN:
            case PARASPACE_WITHDRAW:
                msg->numScreens = 1;
                strlcpy(context->ticker_received, APE_TICKER, sizeof(context->ticker_received));
                break;
            case SWAP_TO:
                msg->numScreens = 1;
                strlcpy(context->ticker_received,
                        ROCKET_POOL_ETH_TICKER,
                        sizeof(context->ticker_received));
                break;
            case SUBMIT_MATIC_LIDO:
            case REQUEST_WITHDRAW:
                msg->numScreens = 2;
                strlcpy(context->ticker_sent, MATIC_TICKER, sizeof(context->ticker_sent));
                break;
            case BUY_VOUCHER:
                msg->numScreens = 1;
                strlcpy(context->ticker_sent, MATIC_TICKER, sizeof(context->ticker_sent));
                break;
            case SWAP_FROM:
                msg->numScreens = 2;
                strlcpy(context->ticker_received, WETH_TICKER, sizeof(context->ticker_received));
                strlcpy(context->ticker_sent, ROCKET_POOL_ETH_TICKER, sizeof(context->ticker_sent));
                break;
            case PARASPACE_DEPOSIT:
                msg->numScreens = 2;
                strlcpy(context->ticker_sent, APE_TICKER, sizeof(context->ticker_sent));
                break;
            case GRT_DELEGATE:
                msg->numScreens = 2;
                strlcpy(context->ticker_sent, GRT_TICKER, sizeof(context->ticker_sent));
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
