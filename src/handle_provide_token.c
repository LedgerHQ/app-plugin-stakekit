#include "stakekit_plugin.h"

static void network_token(plugin_parameters_t *context) {
    if (context->is_token_sent) {
        context->decimals_sent = WEI_TO_ETHER;
        context->tokens_found |= TOKEN_SENT_FOUND;
    } else {
        context->decimals_received = WEI_TO_ETHER;
        context->tokens_found |= TOKEN_RECEIVED_FOUND;
    }
}

void handle_provide_token(ethPluginProvideInfo_t *msg) {
    plugin_parameters_t *context = (plugin_parameters_t *) msg->pluginContext;
    PRINTF("Plugin provide tokens : 0x%p, 0x%p\n", msg->item1, msg->item2);

    if (ADDRESS_IS_NETWORK_TOKEN(context->contract_address)) {
        network_token(context);
    } else if (msg->item1 != NULL) {
        // The "Send" token address has been found.
        context->decimals_sent = msg->item1->token.decimals;
        strlcpy(context->ticker_sent,
                (char *) msg->item1->token.ticker,
                sizeof(context->ticker_sent));
        context->tokens_found |= TOKEN_SENT_FOUND;
    } else if (msg->item2 != NULL) {
        // The "Received" token address has been found.
        context->decimals_received = msg->item2->token.decimals;
        strlcpy(context->ticker_received,
                (char *) msg->item2->token.ticker,
                sizeof(context->ticker_received));
        context->tokens_found |= TOKEN_RECEIVED_FOUND;
    } else if (context->is_token_sent) {
        // CAL did not find the "Send" token and token is not ETH.
        context->decimals_sent = DEFAULT_DECIMAL;
        strlcpy(context->ticker_sent, DEFAULT_TICKER, sizeof(context->ticker_sent));
        // // We will need an additional screen to display a warning message.
        msg->additionalScreens++;
    } else {
        // CAL did not find the "Received" token and token is not ETH.
        context->decimals_received = DEFAULT_DECIMAL;
        strlcpy(context->ticker_received, DEFAULT_TICKER, sizeof(context->ticker_received));
        // // We will need an additional screen to display a warning message.
        msg->additionalScreens++;
    }

    msg->result = ETH_PLUGIN_RESULT_OK;
}