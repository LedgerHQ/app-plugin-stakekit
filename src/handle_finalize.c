#include "stakekit_plugin.h"

// Sets the deposit ticker as the token symbol
static bool set_ticker_deposit_for_mapped_token(plugin_parameters_t *context,
                                                ethPluginFinalize_t *msg) {
    for (size_t i = 0; i < NUM_SUPPORTED_SMART_CONTRACT; i++) {
        if (!memcmp(msg->pluginSharedRO->txContent->destination,
                    STAKEKIT_SUPPORTED_YEARN_VAULT[i].smart_contract,
                    ADDRESS_LENGTH)) {
            char ticker[TICKER_LEN];
            strlcpy(ticker,
                    (char *) STAKEKIT_SUPPORTED_YEARN_VAULT[i].token_symbol_deposit,
                    sizeof(ticker));
            strlcat(ticker, " ", sizeof(ticker));
            strlcpy(context->ticker_sent, (char *) ticker, sizeof(context->ticker_sent));
            context->decimals_sent = STAKEKIT_SUPPORTED_YEARN_VAULT[i].decimals_sent;
            context->tokens_found |= TOKEN_SENT_FOUND;
            return true;
        }
    }
    return false;
}
// Sets the withdraw ticker as the token symbol
static bool set_ticker_withdraw_for_mapped_token(plugin_parameters_t *context,
                                                 ethPluginFinalize_t *msg) {
    for (size_t i = 0; i < NUM_SUPPORTED_SMART_CONTRACT; i++) {
        if (!memcmp(msg->pluginSharedRO->txContent->destination,
                    STAKEKIT_SUPPORTED_YEARN_VAULT[i].smart_contract,
                    ADDRESS_LENGTH)) {
            char ticker[TICKER_LEN];
            strlcpy(ticker,
                    (char *) STAKEKIT_SUPPORTED_YEARN_VAULT[i].token_symbol_withdraw,
                    sizeof(ticker));
            strlcat(ticker, " ", sizeof(ticker));
            strlcpy(context->ticker_sent, (char *) ticker, sizeof(context->ticker_sent));
            context->decimals_sent = STAKEKIT_SUPPORTED_YEARN_VAULT[i].decimals_sent;
            context->tokens_found |= TOKEN_SENT_FOUND;
            return true;
        }
    }
    return false;
}

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
            case COMET_CLAIM:
                msg->numScreens = 2;
                msg->result = ETH_PLUGIN_RESULT_OK;
                break;
            case VOTE:
                msg->numScreens = 4;
                msg->result = ETH_PLUGIN_RESULT_OK;
                break;
            case REVOKE_ACTIVE:
                context->decimals_sent = 0;
                msg->numScreens = 4;
                msg->result = ETH_PLUGIN_RESULT_OK;
                break;
            case MORPHO_SUPPLY_1:
            case MORPHO_SUPPLY_3:
            case TRANSFER_OUT:
            case AAVE_SUPPLY:
                msg->numScreens = 2;
                msg->tokenLookup1 = context->contract_address;
                msg->result = ETH_PLUGIN_RESULT_OK;
                break;
            case MORPHO_SUPPLY_2:
            case COMET_SUPPLY:
                msg->numScreens = 1;
                msg->tokenLookup1 = context->contract_address;
                msg->result = ETH_PLUGIN_RESULT_OK;
                break;
            case MORPHO_WITHDRAW_1:
            case COMET_WITHDRAW:
                msg->numScreens = 1;
                msg->tokenLookup2 = context->contract_address;
                msg->result = ETH_PLUGIN_RESULT_OK;
                break;
            case MORPHO_WITHDRAW_2:
                msg->numScreens = 2;
                msg->tokenLookup2 = context->contract_address;
                msg->result = ETH_PLUGIN_RESULT_OK;
                break;
            case CLAIM_TOKENS:
            case SELL_VOUCHER_NEW:
            case AVALANCHE_REDEEM_2:
            case AVALANCHE_REDEEM_OVERDUE_SHARES_2:
                msg->numScreens = 1;
                context->decimals_sent = 0;
                msg->result = ETH_PLUGIN_RESULT_OK;
                break;
            case ENTER:
                msg->numScreens = 1;
                strlcpy(context->ticker_sent, SUSHI_TICKER, sizeof(context->ticker_sent));
                msg->result = ETH_PLUGIN_RESULT_OK;
                break;
            case LEAVE:
                msg->numScreens = 1;
                strlcpy(context->ticker_sent, XSUSHI_TICKER, sizeof(context->ticker_sent));
                msg->result = ETH_PLUGIN_RESULT_OK;
                break;
            case STAKE:
                msg->numScreens = 1;
                strlcpy(context->ticker_sent,
                        STAKEWISE_STAKED_ETH2_TICKER,
                        sizeof(context->ticker_sent));
                msg->result = ETH_PLUGIN_RESULT_OK;
                break;
            case DEPOSIT_SELF_APECOIN:
                msg->numScreens = 1;
                strlcpy(context->ticker_sent, APE_TICKER, sizeof(context->ticker_sent));
                msg->result = ETH_PLUGIN_RESULT_OK;
                break;
            case WITHDRAW_SELF_APECOIN:
                msg->numScreens = 1;
                strlcpy(context->ticker_received, APE_TICKER, sizeof(context->ticker_received));
                msg->result = ETH_PLUGIN_RESULT_OK;
                break;
            case SWAP_TO:
                msg->numScreens = 1;
                strlcpy(context->ticker_received,
                        ROCKET_POOL_ETH_TICKER,
                        sizeof(context->ticker_received));
                msg->result = ETH_PLUGIN_RESULT_OK;
                break;
            case SUBMIT_MATIC_LIDO:
            case REQUEST_WITHDRAW:
                msg->numScreens = 2;
                strlcpy(context->ticker_sent, MATIC_TICKER, sizeof(context->ticker_sent));
                msg->result = ETH_PLUGIN_RESULT_OK;
                break;
            case BUY_VOUCHER:
                msg->numScreens = 1;
                strlcpy(context->ticker_sent, MATIC_TICKER, sizeof(context->ticker_sent));
                msg->result = ETH_PLUGIN_RESULT_OK;
                break;
            case SWAP_FROM:
                msg->numScreens = 2;
                strlcpy(context->ticker_received, WETH_TICKER, sizeof(context->ticker_received));
                strlcpy(context->ticker_sent, ROCKET_POOL_ETH_TICKER, sizeof(context->ticker_sent));
                msg->result = ETH_PLUGIN_RESULT_OK;
                break;
            case PARASPACE_DEPOSIT:
                msg->numScreens = 2;
                strlcpy(context->ticker_sent, APE_TICKER, sizeof(context->ticker_sent));
                msg->result = ETH_PLUGIN_RESULT_OK;
                break;
            case GRT_DELEGATE:
                msg->numScreens = 2;
                strlcpy(context->ticker_sent, GRT_TICKER, sizeof(context->ticker_sent));
                msg->result = ETH_PLUGIN_RESULT_OK;
                break;
            case AVALANCHE_REQUEST_UNLOCK:
                msg->numScreens = 1;
                strlcpy(context->ticker_sent, STAKED_AVAX_TICKER, sizeof(context->ticker_sent));
                msg->result = ETH_PLUGIN_RESULT_OK;
                break;
            case YEARN_VAULT_DEPOSIT_2:
            case YEARN_VAULT_DEPOSIT_3:
                msg->numScreens = 1;
                if (context->selectorIndex == YEARN_VAULT_DEPOSIT_3) {
                    msg->numScreens++;
                }
                if (set_ticker_deposit_for_mapped_token(context, msg)) {
                    msg->result = ETH_PLUGIN_RESULT_OK;
                } else {
                    msg->result = ETH_PLUGIN_RESULT_ERROR;
                }
                break;
            case PARASPACE_WITHDRAW:
            case YEARN_VAULT_WITHDRAW_2:
            case YEARN_VAULT_WITHDRAW_3:
                msg->numScreens = 1;
                if (context->selectorIndex == YEARN_VAULT_WITHDRAW_3) {
                    msg->numScreens++;
                }
                if (set_ticker_withdraw_for_mapped_token(context, msg)) {
                    msg->result = ETH_PLUGIN_RESULT_OK;
                } else {
                    msg->result = ETH_PLUGIN_RESULT_ERROR;
                }
                break;
            default:
                msg->numScreens = 1;
                msg->result = ETH_PLUGIN_RESULT_OK;
                break;
        }
    } else {
        PRINTF("Context not valid\n");
        msg->result = ETH_PLUGIN_RESULT_FALLBACK;
    }
}
