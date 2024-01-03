#include "stakekit_plugin.h"

// Add two hex numbers and save the result in the first number.
static void hex_addition(uint8_t a[INT256_LENGTH], const uint8_t b[INT256_LENGTH]) {
    uint16_t carry = 0;
    for (int i = INT256_LENGTH - 1; i >= 0; i--) {
        uint16_t sum = a[i] + b[i] + carry;
        a[i] = (uint8_t)(sum & 0xFF);  // Keep only the lower 8 bits
        carry = (sum > 0xFF) ? 1 : 0;  // Update carry for the next iteration
    }
}

// Save two amounts in the context.
// The first amount is the amount received saved in amount_received.
// The second amount is the amount sent saved in amount_sent.
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

// Save 1 amount and 1 recipient in the context.
// The amount is the amount sent saved in amount_sent.
// The second param is the recipient saved in recipient.
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

// Save 1 amount and 2 addresses in the context.
// The amount_sent param is the asset amount saved in amount_sent.
// The recipient param is the recipient saved in recipient.
// The recipient_2 param is the owner saved in contract_address.
static void handle_angle_withdraw(ethPluginProvideParameter_t *msg, plugin_parameters_t *context) {
    switch (context->next_param) {
        case AMOUNT_SENT:
            copy_parameter(context->amount_sent, msg->parameter, INT256_LENGTH);
            context->next_param = RECIPIENT;
            break;
        case RECIPIENT:
            copy_address(context->recipient, msg->parameter, ADDRESS_LENGTH);
            context->next_param = RECIPIENT_2;
            break;
        case RECIPIENT_2:
            copy_address(context->contract_address, msg->parameter, ADDRESS_LENGTH);
            context->next_param = NONE;
            break;
        case NONE:
        default:
            PRINTF("Param not supported\n");
            msg->result = ETH_PLUGIN_RESULT_ERROR;
            break;
    }
}

// Save 1 amount and 1 recipient in the context.
// The first param is the recipient saved in recipient.
// The second param is the amount sent saved in amount_sent.
static void handle_recipient_amount_sent(ethPluginProvideParameter_t *msg,
                                         plugin_parameters_t *context) {
    switch (context->next_param) {
        case RECIPIENT:
            copy_address(context->recipient, msg->parameter, ADDRESS_LENGTH);
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

// Save 1 amount and 1 recipient and 1 token address in the context.
// The first param is the token address which help to fetch the token info later.
// The second param is the recipient saved in recipient.
// The third param is the amount sent saved in amount_sent.
static void handle_morpho_supply_1_3(ethPluginProvideParameter_t *msg,
                                     plugin_parameters_t *context) {
    switch (context->next_param) {
        case TOKEN_SENT:
            copy_address(context->contract_address, msg->parameter, ADDRESS_LENGTH);
            context->is_token_sent = true;
            context->next_param = RECIPIENT;
            break;
        case RECIPIENT:
            copy_address(context->recipient, msg->parameter, ADDRESS_LENGTH);
            context->next_param = AMOUNT_SENT;
            break;
        case AMOUNT_SENT:
            copy_parameter(context->amount_sent, msg->parameter, INT256_LENGTH);
            context->next_param = NONE;
            break;
        case NONE:
            break;
        default:
            PRINTF("Param not supported\n");
            msg->result = ETH_PLUGIN_RESULT_ERROR;
            break;
    }
}

// Save 1 amount and 1 token address in the context.
// The first param is the token address which help to fetch the token info later.
// The second param is the amount sent saved in amount_sent.
static void handle_morpho_supply_2(ethPluginProvideParameter_t *msg, plugin_parameters_t *context) {
    switch (context->next_param) {
        case TOKEN_SENT:
            copy_address(context->contract_address, msg->parameter, ADDRESS_LENGTH);
            context->is_token_sent = true;
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

// Save 1 amount and 1 token address in the context.
// The first param is the token address which help to fetch the token info later.
// The second param is the amount received saved in amount_received.
static void handle_morpho_withdraw_1(ethPluginProvideParameter_t *msg,
                                     plugin_parameters_t *context) {
    switch (context->next_param) {
        case TOKEN_RECEIVED:
            copy_address(context->contract_address, msg->parameter, ADDRESS_LENGTH);
            context->is_token_sent = false;
            context->next_param = AMOUNT_RECEIVED;
            break;
        case AMOUNT_RECEIVED:
            copy_parameter(context->amount_received, msg->parameter, INT256_LENGTH);
            context->next_param = NONE;
            break;
        case NONE:
            break;
        default:
            PRINTF("Param not supported\n");
            msg->result = ETH_PLUGIN_RESULT_ERROR;
            break;
    }
}

// Save 1 amount and 1 recipient and 1 token address in the context.
// The first param is the token address which help to fetch the token info later.
// The second param is the amount received saved in amount_received.
// The third param is the recipient saved in recipient.
static void handle_morpho_withdraw_2(ethPluginProvideParameter_t *msg,
                                     plugin_parameters_t *context) {
    switch (context->next_param) {
        case TOKEN_RECEIVED:
            copy_address(context->contract_address, msg->parameter, ADDRESS_LENGTH);
            context->is_token_sent = false;
            context->next_param = AMOUNT_RECEIVED;
            break;
        case AMOUNT_RECEIVED:
            copy_parameter(context->amount_received, msg->parameter, INT256_LENGTH);
            context->next_param = RECIPIENT;
            break;
        case RECIPIENT:
            copy_address(context->recipient, msg->parameter, ADDRESS_LENGTH);
            context->next_param = NONE;
            break;
        case NONE:
            break;
        default:
            PRINTF("Param not supported\n");
            msg->result = ETH_PLUGIN_RESULT_ERROR;
            break;
    }
}

// Save 2 recipients in the context.
// The first param is the recipient as we have 2 recipient and the storage has a
// limitation, we need to save it in another variable which is contract_address.
// The second param is the second recipient saved in recipient.
static void handle_comet_claim(ethPluginProvideParameter_t *msg, plugin_parameters_t *context) {
    switch (context->next_param) {
        case RECIPIENT:  // Put the Comet protocol address in contract_address
            copy_address(context->contract_address, msg->parameter, ADDRESS_LENGTH);
            context->next_param = RECIPIENT_2;
            break;
        case RECIPIENT_2:
            copy_address(context->recipient, msg->parameter, ADDRESS_LENGTH);
            context->next_param = NONE;
            break;
        case NONE:
            break;
        default:
            PRINTF("Param not supported\n");
            msg->result = ETH_PLUGIN_RESULT_ERROR;
            break;
    }
}

// Save 1 amount and 3 recipients in the context.
// The first param is the second recipient saved in recipient.
// The second param is the amount sent saved in amount_sent.
// The third and fourth param are the recipients as we have 3 recipient and the storage has a
// limitation, we need to save it in other variables which are contract_address and amount_received.
static void handle_vote_revoke(ethPluginProvideParameter_t *msg, plugin_parameters_t *context) {
    switch (context->next_param) {
        case RECIPIENT:
            copy_address(context->recipient, msg->parameter, ADDRESS_LENGTH);
            context->next_param = AMOUNT_SENT;
            break;
        case AMOUNT_SENT:
            copy_parameter(context->amount_sent, msg->parameter, INT256_LENGTH);
            context->next_param = RECIPIENT_2;
            break;
        case RECIPIENT_2:  // Put the lesser group address in contract_address
            copy_address(context->contract_address, msg->parameter, ADDRESS_LENGTH);
            if (ADDRESS_IS_NULL(context->contract_address)) {
                copy_address(context->contract_address, context->recipient, ADDRESS_LENGTH);
            }
            context->next_param = RECIPIENT_3;
            break;
        case RECIPIENT_3:  // Put the greater group address in amount_received
            copy_address(context->amount_received, msg->parameter, ADDRESS_LENGTH);
            if (ADDRESS_IS_NULL(context->amount_received)) {
                copy_address(context->amount_received, context->recipient, ADDRESS_LENGTH);
            }
            context->next_param = NONE;
            break;
        case NONE:
            break;
        default:
            PRINTF("Param not supported\n");
            msg->result = ETH_PLUGIN_RESULT_ERROR;
            break;
    }
}

// Save 1 amount and 1 recipient and 1 token address in the context.
// The first param is the token address which help to fetch the token info later.
// The second param is the amount sent saved in amount_sent.
// The third param is the recipient saved in recipient.
static void handle_aave_supply(ethPluginProvideParameter_t *msg, plugin_parameters_t *context) {
    switch (context->next_param) {
        case TOKEN_SENT:
            copy_address(context->contract_address, msg->parameter, ADDRESS_LENGTH);
            context->is_token_sent = true;
            context->next_param = AMOUNT_SENT;
            break;
        case AMOUNT_SENT:
            copy_parameter(context->amount_sent, msg->parameter, INT256_LENGTH);
            context->next_param = RECIPIENT;
            break;
        case RECIPIENT:
            copy_address(context->recipient, msg->parameter, ADDRESS_LENGTH);
            context->next_param = NONE;
            break;
        case NONE:
            break;
        default:
            PRINTF("Param not supported\n");
            msg->result = ETH_PLUGIN_RESULT_ERROR;
            break;
    }
}

static void handle_lido_request_withdrawal(ethPluginProvideParameter_t *msg,
                                           plugin_parameters_t *context) {
    switch (context->next_param) {
        case RECIPIENT:
            copy_address(context->recipient, msg->parameter, ADDRESS_LENGTH);
            context->next_param = ARRAY_LENGTH;
            break;
        case ARRAY_LENGTH:
            // Storing the number of elements in _amounts[] in nb_requests and unbound_nonce.
            if (!U2BE_from_parameter(msg->parameter, &(context->unbound_nonce))) {
                msg->result = ETH_PLUGIN_RESULT_ERROR;
                break;
            }
            context->nb_requests = context->unbound_nonce;
            context->next_param = AMOUNT_SENT;
            break;
        case AMOUNT_SENT:
            copy_parameter(context->amount_sent, msg->parameter, INT256_LENGTH);
            context->unbound_nonce--;
            if (context->unbound_nonce >= 1) {
                context->next_param = ADD_AMOUNT;
            } else {
                context->next_param = NONE;
            }
            break;
        // saves the following amounts in amount received and add it to the amount sent
        case ADD_AMOUNT:
            copy_parameter(context->amount_received, msg->parameter, INT256_LENGTH);
            hex_addition(context->amount_sent, context->amount_received);
            context->unbound_nonce--;
            if (context->unbound_nonce >= 1) {
                context->next_param = ADD_AMOUNT;
            } else {
                context->next_param = NONE;
            }
            break;
        case NONE:
            break;
        default:
            PRINTF("Param not supported\n");
            msg->result = ETH_PLUGIN_RESULT_ERROR;
            break;
    }
}

static void handle_lido_claim_withdrawal(ethPluginProvideParameter_t *msg,
                                         plugin_parameters_t *context) {
    switch (context->next_param) {
        case SAVE_OFFSET:
            // Storing the offset of the _hints[] array in unbound_nonce.
            if (!U2BE_from_parameter(msg->parameter, &(context->unbound_nonce))) {
                msg->result = ETH_PLUGIN_RESULT_ERROR;
                break;
            }
            context->next_param = ARRAY_LENGTH;
            break;
        case ARRAY_LENGTH:
            // Storing the number of elements in _hints[] array in nb_requests.
            context->nb_requests = msg->parameter[PARAMETER_LENGTH - sizeof(uint8_t)];
            context->next_param = AMOUNT_SENT;
            break;
        case AMOUNT_SENT:
            // Saving the first requestId in amount_sent.
            copy_parameter(context->amount_sent, msg->parameter, INT256_LENGTH);
            // If there are more than 1 requestId, we need to parse the next one. (max 2)
            if (context->nb_requests >= 2) {
                context->next_param = AMOUNT_SENT_2;
            } else {
                // Else go to _hints[] array.
                context->next_param = SKIP;
                context->offset = context->unbound_nonce;
            }
            break;
        case AMOUNT_SENT_2:
            // Saving the second requestId in contract_address.
            copy_address(context->contract_address, msg->parameter, ADDRESS_LENGTH);
            // Go to _hints[] array.
            context->next_param = SKIP;
            context->offset = context->unbound_nonce;
            break;
        case SKIP:
            // Skipping the number of elements in _hints[] array
            // The tx is reverted if _requestIds[] length is not the same as _hints[] length.
            context->next_param = AMOUNT_RECEIVED;
            break;
        case AMOUNT_RECEIVED:
            // Saving the first hint in amount_received.
            copy_parameter(context->amount_received, msg->parameter, INT256_LENGTH);
            // If there are more than 1 hint, we need to parse the next one. (max 2)
            if (context->nb_requests >= 2) {
                context->next_param = AMOUNT_RECEIVED_2;
            } else {
                // Else go to NONE.
                context->next_param = NONE;
            }
            break;
        case AMOUNT_RECEIVED_2:
            // Saving the second hint in recipient.
            copy_address(context->recipient, msg->parameter, ADDRESS_LENGTH);
            // Ignore the next hints
            context->next_param = NONE;
            break;
        case NONE:
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

    if (context->skip) {
        // Skip this step and decrease skipping counter.
        context->skip--;
    } else {
        if ((context->offset) && msg->parameterOffset != context->offset + SELECTOR_SIZE) {
            PRINTF("offset: %d, parameterOffset: %d\n", context->offset, msg->parameterOffset);
            return;
        }
        context->offset = 0;
        switch (context->selectorIndex) {
            case DEPOSIT_SELF_APECOIN:
            case CLAIM_TOKENS:
            case ENTER:
            case LEAVE:
            case UNLOCK:
            case AVALANCHE_REQUEST_UNLOCK:
            case AVALANCHE_REDEEM_2:
            case AVALANCHE_REDEEM_OVERDUE_SHARES_2:
            case PARASPACE_WITHDRAW:
            case YEARN_VAULT_DEPOSIT_2:
            case YEARN_VAULT_WITHDRAW_2:
                // Save the amount sent to the context.
                copy_parameter(context->amount_sent, msg->parameter, INT256_LENGTH);
                break;
            case BUY_VOUCHER:
            case SELL_VOUCHER_NEW:
                // Save the amount sent to the context and skip.
                copy_parameter(context->amount_sent, msg->parameter, INT256_LENGTH);
                context->skip = 1;
                break;
            case WITHDRAW_SELF_APECOIN:
            case SWAP_TO:
                // Save the amount received to the context.
                copy_parameter(context->amount_received, msg->parameter, INT256_LENGTH);
                break;
            case SUBMIT_ETH_LIDO:
                // Save the recipient to the context.
                copy_address(context->recipient, msg->parameter, ADDRESS_LENGTH);
                break;
            case GRT_WITHDRAW_DELEGATED:
                // Save the recipient to the context and skip.
                copy_address(context->recipient, msg->parameter, ADDRESS_LENGTH);
                context->skip = 1;
                break;
            case UNSTAKE_CLAIM_TOKENS_NEW:
                // Save the Unbound nonce boolean to the context.
                if (!U2BE_from_parameter(msg->parameter, &(context->unbound_nonce))) {
                    msg->result = ETH_PLUGIN_RESULT_ERROR;
                    break;
                }
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
                // No parameters to save.
                break;
            case SUBMIT_MATIC_LIDO:
            case REQUEST_WITHDRAW:
            case YEARN_VAULT_DEPOSIT_3:
            case YEARN_VAULT_WITHDRAW_3:
                handle_amount_recipient(msg, context);
                break;
            case SWAP_FROM:
                handle_swap_from(msg, context);
                break;
            case MORPHO_SUPPLY_1:
            case MORPHO_SUPPLY_3:
            case TRANSFER_OUT:
                handle_morpho_supply_1_3(msg, context);
                break;
            case MORPHO_WITHDRAW_1:
            case COMET_WITHDRAW:
                handle_morpho_withdraw_1(msg, context);
                break;
            case MORPHO_WITHDRAW_2:
                handle_morpho_withdraw_2(msg, context);
                break;
            case MORPHO_SUPPLY_2:
            case COMET_SUPPLY:
                handle_morpho_supply_2(msg, context);
                break;
            case PARASPACE_DEPOSIT:
            case GRT_DELEGATE:
            case GRT_UNDELEGATE:
                handle_recipient_amount_sent(msg, context);
                break;
            case COMET_CLAIM:
                handle_comet_claim(msg, context);
                break;
            case VOTE:
            case REVOKE_ACTIVE:
                handle_vote_revoke(msg, context);
                break;
            case AAVE_SUPPLY:
                handle_aave_supply(msg, context);
                break;
            case ANGLE_WITHDRAW:
                handle_angle_withdraw(msg, context);
                break;
            case LIDO_REQUEST_WITHDRAWALS:
                handle_lido_request_withdrawal(msg, context);
                break;
            case LIDO_CLAIM_WITHDRAWALS:
                handle_lido_claim_withdrawal(msg, context);
                break;
            default:
                PRINTF("Selector Index %d not supported\n", context->selectorIndex);
                msg->result = ETH_PLUGIN_RESULT_ERROR;
                break;
        }
    }
    msg->result = ETH_PLUGIN_RESULT_OK;
}