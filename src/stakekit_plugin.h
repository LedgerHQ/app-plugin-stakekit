#pragma once

#include <string.h>
#include "eth_internals.h"
#include "eth_plugin_interface.h"

#define PLUGIN_NAME "StakeKit"

#define NUM_STAKEKIT_SELECTORS 54u

#define TICKER_LEN 30u

#define TOKEN_SENT_FOUND     1u
#define TOKEN_RECEIVED_FOUND 1u << 1u

#define NUM_SUPPORTED_SMART_CONTRACT 322u
typedef struct tokenSymbolAndDecimals_t {
    uint8_t smart_contract[ADDRESS_LENGTH];
    char token_symbol_deposit[TICKER_LEN];
    char token_symbol_withdraw[TICKER_LEN];
    uint8_t decimals_sent;
} tokenSymbolAndDecimals_t;
extern const tokenSymbolAndDecimals_t STAKEKIT_SUPPORTED_YEARN_VAULT[NUM_SUPPORTED_SMART_CONTRACT];

#define CHAIN_ID_LENGTH 1

extern const uint8_t NULL_ETH_ADDRESS[ADDRESS_LENGTH];

// Returns 1 if corresponding address is the address for the chain token (ETH, BNB, MATIC,...)
#define ADDRESS_IS_NETWORK_TOKEN(_addr) !memcmp(_addr, NULL_ETH_ADDRESS, ADDRESS_LENGTH)

// Returns 1 if corresponding address is NULL
#define ADDRESS_IS_NULL(_addr) !memcmp(_addr, NULL_ETH_ADDRESS, ADDRESS_LENGTH)

typedef enum {
    DEPOSIT_SELF_APECOIN,
    WITHDRAW_SELF_APECOIN,
    CLAIM_SELF_APECOIN,
    SUBMIT_ETH_LIDO,
    SWAP_TO,
    SWAP_FROM,
    STAKE,
    SUBMIT_MATIC_LIDO,
    REQUEST_WITHDRAW,
    CLAIM_TOKENS,
    BUY_VOUCHER,
    SELL_VOUCHER_NEW,
    MORPHO_SUPPLY_1,
    MORPHO_SUPPLY_2,
    MORPHO_SUPPLY_3,
    MORPHO_WITHDRAW_1,
    MORPHO_WITHDRAW_2,
    PARASPACE_DEPOSIT,
    PARASPACE_WITHDRAW,
    GRT_DELEGATE,
    GRT_UNDELEGATE,
    GRT_WITHDRAW_DELEGATED,
    ENTER,
    LEAVE,
    COMET_SUPPLY,
    COMET_WITHDRAW,
    COMET_CLAIM,
    TRANSFER_OUT,
    CREATE_ACCOUNT,
    LOCK,
    UNLOCK,
    VOTE,
    REVOKE_ACTIVE,
    AAVE_SUPPLY,
    WITHDRAW_REWARDS,
    UNSTAKE_CLAIM_TOKENS_NEW,
    AVALANCHE_SUBMIT,
    AVALANCHE_REQUEST_UNLOCK,
    AVALANCHE_REDEEM_1,
    AVALANCHE_REDEEM_2,
    AVALANCHE_REDEEM_OVERDUE_SHARES_1,
    AVALANCHE_REDEEM_OVERDUE_SHARES_2,
    YEARN_VAULT_DEPOSIT_1,
    YEARN_VAULT_DEPOSIT_2,
    YEARN_VAULT_DEPOSIT_3,
    YEARN_VAULT_WITHDRAW_1,
    YEARN_VAULT_WITHDRAW_2,
    YEARN_VAULT_WITHDRAW_3,
    ANGLE_WITHDRAW,
    LIDO_REQUEST_WITHDRAWALS,
    LIDO_CLAIM_WITHDRAWALS,
    VIC_VOTE,
    VIC_RESIGN,
    VIC_UNVOTE,
} selector_t;

extern const uint8_t *const STAKEKIT_SELECTORS[NUM_STAKEKIT_SELECTORS];

typedef enum {
    SEND_SCREEN,
    SEND_VALUE_SCREEN,
    RECEIVE_SCREEN,
    RECIPIENT_SCREEN,
    RECIPIENT_2_SCREEN,
    RECIPIENT_3_SCREEN,
    SMART_CONTRACT_SCREEN,
    UNBOUND_NONCE_SCREEN,
    WARN_SCREEN,
    SEND_2_SCREEN,
    RECEIVE_2_SCREEN,
    ERROR,
} screens_t;

#define AMOUNT_SENT       0   // Amount sent by the user to the contract.
#define AMOUNT_SENT_2     1   // Second amount sent by the user to the contract.
#define AMOUNT_RECEIVED   2   // Amount received by the contract to the user.
#define AMOUNT_RECEIVED_2 3   // Second amount received by the contract to the user.
#define TOKEN_SENT        4   // Token sent by the contract to the user.
#define TOKEN_RECEIVED    5   // Token received by the contract to the user.
#define RECIPIENT         6   // Recipient address receiving the funds.
#define RECIPIENT_2       7   // Recipient address receiving the funds.
#define RECIPIENT_3       8   // Recipient address receiving the funds.
#define UNBOUND_NONCE     9   // Unbond nonce.
#define ARRAY_LENGTH      10  // Length of the array parameter.
#define ARRAY_LENGTH_2    11  // Length of the array parameter.
#define ADD_AMOUNT        12  // Amount to add to the current amount.
#define SAVE_OFFSET       13  // Offset of the array parameter.
#define SKIP              14  // To use when skipping a parameter after an offset skip.
#define NONE              15  // Placeholder variant to be set when parsing is done.

// Number of decimals used when the token wasn't found in the CAL.
#define DEFAULT_DECIMAL WEI_TO_ETHER

// Ticker used when the token wasn't found in the CAL.
#define DEFAULT_TICKER ""

// Ticker used for ETH.
#define ETH_TICKER "ETH"

// Ticker used for BSC.
#define BNB_TICKER "BNB"

// Ticker used for WETH.
#define WETH_TICKER "WETH"

// Ticker used for APE coin staking.
#define APE_TICKER "APE"

// Ticker used for rETH.
#define ROCKET_POOL_ETH_TICKER "rETH"

// Ticker used for rETH.
#define MATIC_TICKER "MATIC"

// Ticker used for GRT.
#define GRT_TICKER "GRT"

// Ticker used for SUSHI.
#define SUSHI_TICKER "SUSHI"

// Ticker used for xSUSHI.
#define XSUSHI_TICKER "xSUSHI"

// Ticker used for rETH.
#define STAKEWISE_STAKED_ETH2_TICKER "sETH2"

// Ticker used for Staked AVAX.
#define STAKED_AVAX_TICKER "sAVAX"

// Ticker used for Viction native token.
#define VIC_TICKER "VIC"

// Shared global memory with Ethereum app. Must be at most 5 * 32 bytes.
typedef struct plugin_parameters_t {
    uint8_t amount_sent[INT256_LENGTH];
    uint8_t amount_received[INT256_LENGTH];
    uint8_t contract_address[ADDRESS_LENGTH];
    uint8_t recipient[ADDRESS_LENGTH];
    char ticker_sent[TICKER_LEN];
    char ticker_received[MAX_TICKER_LEN];

    uint16_t offset;
    uint16_t unbound_nonce;
    uint8_t next_param;
    uint8_t tokens_found;
    uint8_t valid;
    uint8_t decimals_sent;
    uint8_t decimals_received;
    uint8_t selectorIndex;
    uint8_t skip;
    uint8_t nb_requests;
    bool is_token_sent;
} plugin_parameters_t;
// 32*2 + 2*20 + 11*1 + 30*1 = 145
// 1*9 + 2*2 = 13
// 13+145 = 158

// Piece of code that will check that the above structure is not bigger than 5 * 32.
// Do not remove this check.
_Static_assert(sizeof(plugin_parameters_t) <= (5 * 32), "Structure of parameters too big.");

void handle_provide_parameter(void *parameters);
void handle_query_contract_ui(void *parameters);
void handle_finalize(void *parameters);
void handle_init_contract(void *parameters);
void handle_provide_token(void *parameters);
void handle_query_contract_id(void *parameters);

static inline void printf_hex_array(const char *title __attribute__((unused)),
                                    size_t len __attribute__((unused)),
                                    const uint8_t *data __attribute__((unused))) {
    PRINTF(title);
    for (size_t i = 0; i < len; ++i) {
        PRINTF("%02x", data[i]);
    };
    PRINTF("\n");
}
