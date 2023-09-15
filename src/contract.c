#include "stakekit_plugin.h"

// Need more information about the interface for plugins? Please read the README.md!

static const uint8_t STAKEKIT_DEPOSIT_SELF_APECOIN_SELECTOR[SELECTOR_SIZE] = {0x9d,
                                                                              0xca,
                                                                              0xaf,
                                                                              0xb4};
static const uint8_t STAKEKIT_WITHDRAW_SELF_APECOIN_SELECTOR[SELECTOR_SIZE] = {0x7f,
                                                                               0x60,
                                                                               0xd3,
                                                                               0x38};
static const uint8_t STAKEKIT_CLAIM_SELF_APECOIN_SELECTOR[SELECTOR_SIZE] = {0x82, 0x79, 0xe7, 0x60};
static const uint8_t STAKEKIT_SUBMIT_ETH_LIDO_SELECTOR[SELECTOR_SIZE] = {0xa1, 0x90, 0x3e, 0xab};
static const uint8_t STAKEKIT_SWAP_TO_SELECTOR[SELECTOR_SIZE] = {0x55, 0x36, 0x2f, 0x4d};
static const uint8_t STAKEKIT_SWAP_FROM_SELECTOR[SELECTOR_SIZE] = {0xa8, 0x24, 0xae, 0x8b};
static const uint8_t STAKEKIT_STAKE_SELECTOR[SELECTOR_SIZE] = {0x3a, 0x4b, 0x66, 0xf1};
static const uint8_t STAKEKIT_SUBMIT_MATIC_LIDO_SELECTOR[SELECTOR_SIZE] = {0xf5, 0x32, 0xe8, 0x6a};
static const uint8_t STAKEKIT_REQUEST_WITHDRAW_SELECTOR[SELECTOR_SIZE] = {0xcc, 0xc1, 0x43, 0xb8};
static const uint8_t STAKEKIT_CLAIM_TOKENS_SELECTOR[SELECTOR_SIZE] = {0x46, 0xe0, 0x4a, 0x2f};
static const uint8_t STAKEKIT_BUY_VOUCHER_SELECTOR[SELECTOR_SIZE] = {0x6a, 0xb1, 0x50, 0x71};
static const uint8_t STAKEKIT_SELL_VOUCHER_NEW_SELECTOR[SELECTOR_SIZE] = {0xc8, 0x3e, 0xc0, 0x4d};
static const uint8_t STAKEKIT_MORPHO_SUPPLY_1_SELECTOR[SELECTOR_SIZE] = {0x0c, 0x0a, 0x76, 0x9b};
static const uint8_t STAKEKIT_MORPHO_SUPPLY_2_SELECTOR[SELECTOR_SIZE] = {0xf2, 0xb9, 0xfd, 0xb8};
static const uint8_t STAKEKIT_MORPHO_SUPPLY_3_SELECTOR[SELECTOR_SIZE] = {0xf6, 0x22, 0x56, 0xc7};
static const uint8_t STAKEKIT_MORPHO_WITHDRAW_1_SELECTOR[SELECTOR_SIZE] = {0xf3, 0xfe, 0xf3, 0xa3};
static const uint8_t STAKEKIT_MORPHO_WITHDRAW_2_SELECTOR[SELECTOR_SIZE] = {0x69, 0x32, 0x8d, 0xec};
static const uint8_t STAKEKIT_PARASPACE_DEPOSIT_SELECTOR[SELECTOR_SIZE] = {0x47, 0xe7, 0xef, 0x24};
static const uint8_t STAKEKIT_PARASPACE_WITHDRAW_SELECTOR[SELECTOR_SIZE] = {0x2e, 0x1a, 0x7d, 0x4d};
static const uint8_t STAKEKIT_GRT_DELEGATE_SELECTOR[SELECTOR_SIZE] = {0x02, 0x6e, 0x40, 0x2b};
static const uint8_t STAKEKIT_GRT_UNDELEGATE_SELECTOR[SELECTOR_SIZE] = {0x4d, 0x99, 0xdd, 0x16};
static const uint8_t STAKEKIT_GRT_WITHDRAW_DELEGATED_SELECTOR[SELECTOR_SIZE] = {0x51,
                                                                                0xa6,
                                                                                0x0b,
                                                                                0x02};
static const uint8_t STAKEKIT_ENTER_SELECTOR[SELECTOR_SIZE] = {0xa5, 0x9f, 0x3e, 0x0c};
static const uint8_t STAKEKIT_LEAVE_SELECTOR[SELECTOR_SIZE] = {0x67, 0xdf, 0xd4, 0xc9};
static const uint8_t STAKEKIT_COMET_SUPPLY_SELECTOR[SELECTOR_SIZE] = {0xf2, 0xb9, 0xfd, 0xb8};
static const uint8_t STAKEKIT_COMET_WITHDRAW_SELECTOR[SELECTOR_SIZE] = {0xf3, 0xfe, 0xf3, 0xa3};
static const uint8_t STAKEKIT_COMET_CLAIM_SELECTOR[SELECTOR_SIZE] = {0xb7, 0x03, 0x4f, 0x7e};
static const uint8_t STAKEKIT_TRANSFER_OUT_SELECTOR[SELECTOR_SIZE] = {0xaa, 0x74, 0x15, 0xf5};
static const uint8_t STAKEKIT_CREATE_ACCOUNT_SELECTOR[SELECTOR_SIZE] = {0x9d, 0xca, 0x36, 0x2f};
static const uint8_t STAKEKIT_LOCK_SELECTOR[SELECTOR_SIZE] = {0xf8, 0x3d, 0x08, 0xba};
static const uint8_t STAKEKIT_UNLOCK_SELECTOR[SELECTOR_SIZE] = {0x61, 0x98, 0xe3, 0x39};

// Array of all the different StakeKit selectors.
const uint8_t *const STAKEKIT_SELECTORS[NUM_STAKEKIT_SELECTORS] = {
    STAKEKIT_DEPOSIT_SELF_APECOIN_SELECTOR,
    STAKEKIT_WITHDRAW_SELF_APECOIN_SELECTOR,
    STAKEKIT_CLAIM_SELF_APECOIN_SELECTOR,
    STAKEKIT_SUBMIT_ETH_LIDO_SELECTOR,
    STAKEKIT_SWAP_TO_SELECTOR,
    STAKEKIT_SWAP_FROM_SELECTOR,
    STAKEKIT_STAKE_SELECTOR,
    STAKEKIT_SUBMIT_MATIC_LIDO_SELECTOR,
    STAKEKIT_REQUEST_WITHDRAW_SELECTOR,
    STAKEKIT_CLAIM_TOKENS_SELECTOR,
    STAKEKIT_BUY_VOUCHER_SELECTOR,
    STAKEKIT_SELL_VOUCHER_NEW_SELECTOR,
    STAKEKIT_MORPHO_SUPPLY_1_SELECTOR,
    STAKEKIT_MORPHO_SUPPLY_2_SELECTOR,
    STAKEKIT_MORPHO_SUPPLY_3_SELECTOR,
    STAKEKIT_MORPHO_WITHDRAW_1_SELECTOR,
    STAKEKIT_MORPHO_WITHDRAW_2_SELECTOR,
    STAKEKIT_PARASPACE_DEPOSIT_SELECTOR,
    STAKEKIT_PARASPACE_WITHDRAW_SELECTOR,
    STAKEKIT_GRT_DELEGATE_SELECTOR,
    STAKEKIT_GRT_UNDELEGATE_SELECTOR,
    STAKEKIT_GRT_WITHDRAW_DELEGATED_SELECTOR,
    STAKEKIT_ENTER_SELECTOR,
    STAKEKIT_LEAVE_SELECTOR,
    STAKEKIT_COMET_SUPPLY_SELECTOR,
    STAKEKIT_COMET_WITHDRAW_SELECTOR,
    STAKEKIT_COMET_CLAIM_SELECTOR,
    STAKEKIT_TRANSFER_OUT_SELECTOR,
    STAKEKIT_CREATE_ACCOUNT_SELECTOR,
    STAKEKIT_LOCK_SELECTOR,
    STAKEKIT_UNLOCK_SELECTOR,
};

// Indicate the Ethereum chain ID
const uint8_t ETH_CHAIN_ID[CHAIN_ID_LENGTH] = {0x01};

// Indicate the BSC chain ID
const uint8_t BSC_CHAIN_ID[CHAIN_ID_LENGTH] = {0x38};

// Remove if not used
const uint8_t NULL_ETH_ADDRESS[ADDRESS_LENGTH] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
