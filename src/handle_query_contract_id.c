#include "stakekit_plugin.h"

// Function to display the method name on the device.
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
        case AVALANCHE_SUBMIT:
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
        case MORPHO_SUPPLY_1:
        case MORPHO_SUPPLY_2:
        case MORPHO_SUPPLY_3:
        case COMET_SUPPLY:
        case AAVE_SUPPLY:
            strlcpy(msg->version, "Supply", msg->versionLength);
            break;
        case MORPHO_WITHDRAW_1:
        case MORPHO_WITHDRAW_2:
        case PARASPACE_WITHDRAW:
        case COMET_WITHDRAW:
        case YEARN_VAULT_WITHDRAW_1:
        case YEARN_VAULT_WITHDRAW_2:
        case YEARN_VAULT_WITHDRAW_3:
        case VIC_WITHDRAW:
            strlcpy(msg->version, "Withdraw", msg->versionLength);
            break;
        case PARASPACE_DEPOSIT:
        case YEARN_VAULT_DEPOSIT_1:
        case YEARN_VAULT_DEPOSIT_2:
        case YEARN_VAULT_DEPOSIT_3:
            strlcpy(msg->version, "Deposit", msg->versionLength);
            break;
        case GRT_DELEGATE:
            strlcpy(msg->version, "Delegate", msg->versionLength);
            break;
        case GRT_UNDELEGATE:
            strlcpy(msg->version, "Undelegate", msg->versionLength);
            break;
        case GRT_WITHDRAW_DELEGATED:
            strlcpy(msg->version, "Withdraw Delegated", msg->versionLength);
            break;
        case ENTER:
            strlcpy(msg->version, "Enter", msg->versionLength);
            break;
        case LEAVE:
            strlcpy(msg->version, "Leave", msg->versionLength);
            break;
        case COMET_CLAIM:
            strlcpy(msg->version, "Claim", msg->versionLength);
            break;
        case TRANSFER_OUT:
            strlcpy(msg->version, "Transfer Out", msg->versionLength);
            break;
        case CREATE_ACCOUNT:
            strlcpy(msg->version, "Create Account", msg->versionLength);
            break;
        case LOCK:
            strlcpy(msg->version, "Lock", msg->versionLength);
            break;
        case UNLOCK:
            strlcpy(msg->version, "Unlock", msg->versionLength);
            break;
        case VOTE:
        case VIC_VOTE:
            strlcpy(msg->version, "Vote", msg->versionLength);
            break;
        case REVOKE_ACTIVE:
            strlcpy(msg->version, "Revoke Active", msg->versionLength);
            break;
        case WITHDRAW_REWARDS:
            strlcpy(msg->version, "Withdraw Rewards", msg->versionLength);
            break;
        case UNSTAKE_CLAIM_TOKENS_NEW:
            strlcpy(msg->version, "Unstake Claim Tokens New", msg->versionLength);
            break;
        case AVALANCHE_REQUEST_UNLOCK:
            strlcpy(msg->version, "Request Unlock", msg->versionLength);
            break;
        case AVALANCHE_REDEEM_1:
        case AVALANCHE_REDEEM_2:
            strlcpy(msg->version, "Redeem", msg->versionLength);
            break;
        case AVALANCHE_REDEEM_OVERDUE_SHARES_1:
        case AVALANCHE_REDEEM_OVERDUE_SHARES_2:
            strlcpy(msg->version, "Redeem Overdue Shares", msg->versionLength);
            break;
        case ANGLE_WITHDRAW:
            strlcpy(msg->version, "Withdraw", msg->versionLength);
            break;
        case LIDO_REQUEST_WITHDRAWALS:
            strlcpy(msg->version, "Request Withdrawals", msg->versionLength);
            break;
        case LIDO_CLAIM_WITHDRAWALS:
            strlcpy(msg->version, "Claim Withdrawals", msg->versionLength);
            break;
        case VIC_RESIGN:
            strlcpy(msg->version, "Resign", msg->versionLength);
            break;
        case VIC_UNVOTE:
            strlcpy(msg->version, "Unvote", msg->versionLength);
            break;
        default:
            PRINTF("Selector Index :%d not supported\n", context->selectorIndex);
            msg->result = ETH_PLUGIN_RESULT_ERROR;
            return;
    }

    msg->result = ETH_PLUGIN_RESULT_OK;
}