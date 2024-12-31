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
static const uint8_t STAKEKIT_VOTE_SELECTOR[SELECTOR_SIZE] = {0x58, 0x0d, 0x74, 0x7a};
static const uint8_t STAKEKIT_REVOKE_ACTIVE_SELECTOR[SELECTOR_SIZE] = {0x6e, 0x19, 0x84, 0x75};
static const uint8_t STAKEKIT_AAVE_SUPPLY_SELECTOR[SELECTOR_SIZE] = {0x61, 0x7b, 0xa0, 0x37};
static const uint8_t STAKEKIT_WITHDRAW_REWARDS_SELECTOR[SELECTOR_SIZE] = {0xc7, 0xb8, 0x98, 0x1c};
static const uint8_t STAKEKIT_UNSTAKE_CLAIM_TOKENS_NEW_SELECTOR[SELECTOR_SIZE] = {0xe9,
                                                                                  0x7f,
                                                                                  0xdd,
                                                                                  0xc2};
static const uint8_t STAKEKIT_AVALANCHE_SUBMIT_SELECTOR[SELECTOR_SIZE] = {0x5b, 0xcb, 0x2f, 0xc6};
static const uint8_t STAKEKIT_AVALANCHE_REQUEST_UNLOCK_SELECTOR[SELECTOR_SIZE] = {0xc9,
                                                                                  0xd2,
                                                                                  0xff,
                                                                                  0x9d};
static const uint8_t STAKEKIT_AVALANCHE_REDEEM_1_SELECTOR[SELECTOR_SIZE] = {0xbe, 0x04, 0x0f, 0xb0};
static const uint8_t STAKEKIT_AVALANCHE_REDEEM_2_SELECTOR[SELECTOR_SIZE] = {0xdb, 0x00, 0x6a, 0x75};
static const uint8_t STAKEKIT_AVALANCHE_REDEEM_OVERDUE_SHARES_1_SELECTOR[SELECTOR_SIZE] = {0x0d,
                                                                                           0x10,
                                                                                           0xd3,
                                                                                           0x2c};
static const uint8_t STAKEKIT_AVALANCHE_REDEEM_OVERDUE_SHARES_2_SELECTOR[SELECTOR_SIZE] = {0x0f,
                                                                                           0x7e,
                                                                                           0x20,
                                                                                           0x48};
static const uint8_t STAKEKIT_YEARN_VAULT_DEPOSIT_1_SELECTOR[SELECTOR_SIZE] = {0xd0,
                                                                               0xe3,
                                                                               0x0d,
                                                                               0xb0};
static const uint8_t STAKEKIT_YEARN_VAULT_DEPOSIT_2_SELECTOR[SELECTOR_SIZE] = {0xb6,
                                                                               0xb5,
                                                                               0x5f,
                                                                               0x25};
static const uint8_t STAKEKIT_YEARN_VAULT_DEPOSIT_3_SELECTOR[SELECTOR_SIZE] = {0x6e,
                                                                               0x55,
                                                                               0x3f,
                                                                               0x65};
static const uint8_t STAKEKIT_YEARN_VAULT_WITHDRAW_1_SELECTOR[SELECTOR_SIZE] = {0x3c,
                                                                                0xcf,
                                                                                0xd6,
                                                                                0x0b};
static const uint8_t STAKEKIT_YEARN_VAULT_WITHDRAW_2_SELECTOR[SELECTOR_SIZE] = {0x2e,
                                                                                0x1a,
                                                                                0x7d,
                                                                                0x4d};
static const uint8_t STAKEKIT_YEARN_VAULT_WITHDRAW_3_SELECTOR[SELECTOR_SIZE] = {0x00,
                                                                                0xf7,
                                                                                0x14,
                                                                                0xce};
static const uint8_t STAKEKIT_ANGLE_WITHDRAW_SELECTOR[SELECTOR_SIZE] = {0xb4, 0x60, 0xaf, 0x94};
static const uint8_t STAKEKIT_LIDO_REQUEST_WITHDRAWALS_SELECTOR[SELECTOR_SIZE] = {0xd6,
                                                                                  0x68,
                                                                                  0x10,
                                                                                  0x42};
static const uint8_t STAKEKIT_LIDO_CLAIM_WITHDRAWALS_SELECTOR[SELECTOR_SIZE] = {0xe3,
                                                                                0xaf,
                                                                                0xe0,
                                                                                0xa3};
static const uint8_t STAKEKIT_VIC_VOTE_SELECTOR[SELECTOR_SIZE] = {0x6d, 0xd7, 0xd8, 0xea};

static const uint8_t STAKEKIT_VIC_RESIGN_SELECTOR[SELECTOR_SIZE] = {0xae, 0x6e, 0x43, 0xf5};
static const uint8_t STAKEKIT_VIC_UNVOTE_SELECTOR[SELECTOR_SIZE] = {0x02, 0xaa, 0x9b, 0xe2};
static const uint8_t STAKEKIT_VIC_WITHDRAW_SELECTOR[SELECTOR_SIZE] = {0x44, 0x1a, 0x3e, 0x70};
static const uint8_t STAKEKIT_CLAIM_SELECTOR[SELECTOR_SIZE] = {0xaa, 0xd3, 0xec, 0x96};
static const uint8_t STAKEKIT_DELEGATE_SELECTOR[SELECTOR_SIZE] = {0x98, 0x2e, 0xf0, 0xa7};
static const uint8_t STAKEKIT_UNDELEGATE_SELECTOR[SELECTOR_SIZE] = {0x4d, 0x99, 0xdd, 0x16};
static const uint8_t STAKEKIT_REDELEGATE_SELECTOR[SELECTOR_SIZE] = {0x59, 0x49, 0x18, 0x71};
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
    STAKEKIT_VOTE_SELECTOR,
    STAKEKIT_REVOKE_ACTIVE_SELECTOR,
    STAKEKIT_AAVE_SUPPLY_SELECTOR,
    STAKEKIT_WITHDRAW_REWARDS_SELECTOR,
    STAKEKIT_UNSTAKE_CLAIM_TOKENS_NEW_SELECTOR,
    STAKEKIT_AVALANCHE_SUBMIT_SELECTOR,
    STAKEKIT_AVALANCHE_REQUEST_UNLOCK_SELECTOR,
    STAKEKIT_AVALANCHE_REDEEM_1_SELECTOR,
    STAKEKIT_AVALANCHE_REDEEM_2_SELECTOR,
    STAKEKIT_AVALANCHE_REDEEM_OVERDUE_SHARES_1_SELECTOR,
    STAKEKIT_AVALANCHE_REDEEM_OVERDUE_SHARES_2_SELECTOR,
    STAKEKIT_YEARN_VAULT_DEPOSIT_1_SELECTOR,
    STAKEKIT_YEARN_VAULT_DEPOSIT_2_SELECTOR,
    STAKEKIT_YEARN_VAULT_DEPOSIT_3_SELECTOR,
    STAKEKIT_YEARN_VAULT_WITHDRAW_1_SELECTOR,
    STAKEKIT_YEARN_VAULT_WITHDRAW_2_SELECTOR,
    STAKEKIT_YEARN_VAULT_WITHDRAW_3_SELECTOR,
    STAKEKIT_ANGLE_WITHDRAW_SELECTOR,
    STAKEKIT_LIDO_REQUEST_WITHDRAWALS_SELECTOR,
    STAKEKIT_LIDO_CLAIM_WITHDRAWALS_SELECTOR,
    STAKEKIT_VIC_VOTE_SELECTOR,
    STAKEKIT_VIC_RESIGN_SELECTOR,
    STAKEKIT_VIC_UNVOTE_SELECTOR,
    STAKEKIT_VIC_WITHDRAW_SELECTOR,
    STAKEKIT_CLAIM_SELECTOR,
    STAKEKIT_DELEGATE_SELECTOR,
    STAKEKIT_UNDELEGATE_SELECTOR,
    STAKEKIT_REDELEGATE_SELECTOR};

// Null address
const uint8_t NULL_ETH_ADDRESS[ADDRESS_LENGTH] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

// Array containing the yearn vault smart contracts supported by StakeKit Plugin
// each contain the token symbol and decimal
const tokenSymbolAndDecimals_t STAKEKIT_SUPPORTED_YEARN_VAULT[NUM_SUPPORTED_SMART_CONTRACT] = {
    {{0xc5, 0xc9, 0xfb, 0x62, 0x23, 0xa9, 0x89, 0x20, 0x8d, 0xf2,
      0x7d, 0xce, 0xe3, 0x3f, 0xc5, 0x9f, 0xf5, 0xc2, 0x6f, 0xff},
     "APE",
     "cAPE",
     18},
    {{0xfb, 0xef, 0x71, 0x36, 0x96, 0x46, 0x5d, 0xda, 0xb2, 0x97,
      0x16, 0x4c, 0x3b, 0x6a, 0x01, 0x22, 0xd9, 0x2a, 0x3b, 0xac},
     "DAI",
     "yvDAI",
     18},
    {{0x0a, 0x2f, 0x23, 0x4a, 0xd2, 0xe5, 0xe9, 0x04, 0x70, 0x67,
      0x90, 0x4a, 0x9d, 0x37, 0xd0, 0xcd, 0x02, 0xb8, 0x0d, 0x12},
     "WBTC",
     "yvWBTC",
     8},
    {{0xa6, 0x28, 0xc5, 0x4c, 0x85, 0x0f, 0xf1, 0x07, 0x7b, 0x5c,
      0x95, 0x44, 0x91, 0xd1, 0x9e, 0xcc, 0xe7, 0xe3, 0x21, 0xff},
     "WETH",
     "yvWETH",
     18},
    {{0x4c, 0x8b, 0x19, 0x58, 0xb0, 0x9b, 0x3b, 0xde, 0x71, 0x4f,
      0x68, 0x86, 0x4b, 0xcc, 0x3a, 0x74, 0xea, 0xf1, 0xa2, 0x3d},
     "USDC",
     "yvUSDC",
     6},
    {{0xc3, 0x28, 0xd8, 0x38, 0x83, 0xf5, 0xf9, 0x0e, 0x11, 0x08,
      0xd4, 0xdd, 0x7a, 0x18, 0xff, 0xca, 0x17, 0xae, 0x74, 0xd7},
     "sUSD",
     "yvsUSD",
     18},
    {{0x65, 0x34, 0x3f, 0x41, 0x4f, 0xfd, 0x6c, 0x97, 0xb0, 0xf6,
      0xad, 0xd3, 0x3d, 0x16, 0xf6, 0x84, 0x5a, 0xc2, 0x2b, 0xac},
     "DAI",
     "yvDAI",
     18},
    {{0x7e, 0xdf, 0x16, 0x07, 0x6e, 0x56, 0xfa, 0x4c, 0x11, 0x10,
      0x55, 0xfb, 0xa1, 0xff, 0x55, 0x56, 0xb8, 0x75, 0x7c, 0xfb},
     "WBTC",
     "yvWBTC",
     8},
    {{0x5b, 0x97, 0x75, 0x77, 0xeb, 0x8a, 0x48, 0x0f, 0x63, 0xe1,
      0x1f, 0xc6, 0x15, 0xd6, 0x75, 0x3a, 0xdb, 0x86, 0x52, 0xae},
     "WETH",
     "yvWETH",
     18},
    {{0xad, 0x17, 0xa2, 0x25, 0x07, 0x41, 0x91, 0xd5, 0xc8, 0xa3,
      0x7b, 0x50, 0xfd, 0xa1, 0xae, 0x27, 0x8a, 0x2e, 0xe6, 0xa2},
     "USDC",
     "yvUSDC",
     6},
    {{0x2a, 0x90, 0xf4, 0x79, 0x00, 0x2d, 0xaa, 0xe9, 0x93, 0x4c,
      0x3a, 0x70, 0xeb, 0xb6, 0xe8, 0xdb, 0xeb, 0x46, 0x29, 0x2b},
     "sUSD",
     "yvsUSD",
     18},
    {{0xb4, 0xe4, 0xcf, 0xa9, 0x97, 0x1c, 0x7e, 0x10, 0x69, 0x68,
      0x57, 0x71, 0xda, 0xb6, 0x1c, 0xa5, 0x6e, 0x72, 0xe5, 0xc3},
     "seth-f",
     "yvCurve-sETH",
     18},
    {{0x7d, 0x23, 0x82, 0xb1, 0xf8, 0xaf, 0x62, 0x12, 0x29, 0xd3,
      0x34, 0x64, 0x34, 0x05, 0x41, 0xdb, 0x36, 0x2b, 0x49, 0x07},
     "OP",
     "yvOP",
     18},
    {{0x16, 0x1e, 0x74, 0x11, 0xa2, 0x91, 0xcc, 0xaf, 0x37, 0x72,
      0x79, 0xfc, 0xe6, 0xa8, 0xc8, 0xd6, 0x89, 0xdb, 0xeb, 0xe8},
     "sAMM-USDC/sUSD",
     "yvVelo-USDC-sUSD",
     18},
    {{0xfa, 0xee, 0x21, 0xd0, 0xf0, 0xaf, 0x88, 0xee, 0x72, 0xbb,
      0x6d, 0x68, 0xe5, 0x4a, 0x90, 0xe6, 0xec, 0x26, 0x16, 0xde},
     "USDT",
     "yvUSDT",
     6},
    {{0x22, 0x68, 0x7c, 0xa7, 0x92, 0xa8, 0xcb, 0x5e, 0x16, 0x9a,
      0x77, 0xe0, 0x94, 0x9e, 0x71, 0xfe, 0x37, 0x14, 0x76, 0x04},
     "sAMM-USDC/DOLA",
     "yvVelo-USDC-DOLA",
     18},
    {{0x5e, 0x70, 0xe0, 0xed, 0xe4, 0x33, 0x73, 0xbd, 0x9c, 0xf4,
      0xbc, 0x85, 0x19, 0x9d, 0x42, 0x4a, 0xcf, 0x02, 0x41, 0xef},
     "sUSD3CRV-f",
     "yvCurve-sUSD",
     18},
    {{0x67, 0x59, 0x57, 0x46, 0x67, 0x89, 0x6a, 0x45, 0x33, 0x04,
      0x89, 0x79, 0x93, 0xd6, 0x1f, 0x00, 0xfd, 0xc7, 0x21, 0x4d},
     "MAI",
     "yvMAI",
     18},
    {{0x68, 0x2d, 0xf6, 0x12, 0x22, 0xa3, 0xfb, 0x64, 0xf3, 0xe8,
      0x8f, 0xef, 0x41, 0xce, 0x21, 0x49, 0x9a, 0xdc, 0xc6, 0x47},
     "sAMM-USDC/MAI",
     "yvVelo-USDC-MAI",
     18},
    {{0x88, 0xb4, 0x29, 0x35, 0x96, 0x65, 0xb8, 0x68, 0x5b, 0x74,
      0x31, 0xf5, 0xa0, 0xf6, 0xe8, 0xc7, 0x19, 0xbf, 0x49, 0xaa},
     "vAMMV2-USDC/VELO",
     "yvVelo-VELO-USDC-f",
     18},
    {{0x1b, 0x1d, 0x2e, 0xfb, 0x60, 0x45, 0x85, 0x1f, 0x8c, 0xcd,
      0xe2, 0x43, 0x69, 0x00, 0x3e, 0x0f, 0xf1, 0x57, 0x98, 0x0b},
     "sAMMV2-USDC/sUSD",
     "yvVelo-sUSD-USDC-f",
     18},
    {{0x1d, 0x49, 0xab, 0x5b, 0x03, 0x26, 0x8e, 0x32, 0x9f, 0xc7,
      0xd2, 0x11, 0x1e, 0x53, 0x64, 0xe6, 0x3b, 0x36, 0xa3, 0xce},
     "sAMMV2-USDC/MAI",
     "yvVelo-MAI-USDC-f",
     18},
    {{0xc8, 0x6b, 0x70, 0xe2, 0xc1, 0x6c, 0x5f, 0xb5, 0x31, 0x5e,
      0x46, 0x63, 0x73, 0x7e, 0x0e, 0x07, 0x7a, 0xbf, 0xc3, 0x95},
     "vAMMV2-OP/VELO",
     "yvVelo-OP-VELO-f",
     18},
    {{0x3a, 0xd9, 0x56, 0x6b, 0x15, 0xaa, 0xcd, 0xd2, 0x6d, 0x8a,
      0x22, 0x0c, 0xa8, 0x63, 0x5f, 0x92, 0x5e, 0xa7, 0xa3, 0xf6},
     "vAMMV2-OP/USDC",
     "yvVelo-OP-USDC-f",
     18},
    {{0xd7, 0xee, 0x0e, 0x2d, 0x23, 0x2b, 0xcb, 0xef, 0xa7, 0x4e,
      0xf3, 0x6a, 0x43, 0x9d, 0x0d, 0xe8, 0x80, 0xc6, 0xec, 0xe5},
     "vAMMV2-RED/VELO",
     "yvVelo-RED-VELO-f",
     18},
    {{0xf8, 0x9f, 0xdb, 0xbc, 0xe1, 0xa7, 0x07, 0x06, 0x1e, 0x9d,
      0x59, 0xb8, 0xe4, 0x38, 0x7f, 0x89, 0x79, 0x8b, 0x4d, 0x10},
     "vAMMV2-WETH/USDC",
     "yvVelo-USDC-WETH-f",
     18},
    {{0xcf, 0x6b, 0xef, 0x33, 0xc4, 0x98, 0x24, 0x22, 0x6f, 0xb9,
      0xde, 0xfc, 0xdc, 0x3b, 0x1d, 0xe1, 0x1f, 0x20, 0x7d, 0xb7},
     "sAMMV2-FRAX/USDC",
     "yvVelo-FRAX-USDC-f",
     18},
    {{0x3f, 0xb7, 0x92, 0xfa, 0x67, 0xcd, 0xe5, 0x0a, 0x41, 0xe2,
      0x03, 0x04, 0xe4, 0xaf, 0xef, 0x52, 0x2c, 0xf7, 0x11, 0xee},
     "sAMMV2-USDC/USDT",
     "yvVelo-USDT-USDC-f",
     18},
    {{0x53, 0x1f, 0xdb, 0x1c, 0x84, 0x29, 0xf4, 0x04, 0x11, 0x69,
      0x32, 0x22, 0x6d, 0x48, 0x7d, 0xb9, 0x44, 0x71, 0xc4, 0xb7},
     "vAMMV2-wUSDR/USDC",
     "yvVelo-wUSDR-USDC-f",
     18},
    {{0x39, 0xf6, 0x07, 0x10, 0xa2, 0x7a, 0x87, 0x33, 0x2d, 0x10,
      0xe3, 0x33, 0x3c, 0x2e, 0xff, 0x41, 0xee, 0xc9, 0x11, 0xee},
     "sAMMV2-USDC/DOLA",
     "yvVelo-DOLA-USDC-f",
     18},
    {{0x95, 0x0f, 0x38, 0x4f, 0x56, 0x6b, 0x82, 0xcc, 0xa6, 0x38,
      0x0f, 0x75, 0xae, 0x42, 0xe2, 0xbb, 0xe9, 0xb3, 0x57, 0xb2},
     "sAMMV2-USDC/MIM",
     "yvVelo-MIM-USDC-f",
     18},
    {{0x83, 0xb8, 0x39, 0x1b, 0x9e, 0xfb, 0xc5, 0xb5, 0xa3, 0x87,
      0x77, 0xfb, 0x22, 0xa4, 0x96, 0x8c, 0x62, 0x2a, 0x40, 0x5a},
     "vAMMV2-USDC/BLU",
     "yvVelo-BLU-USDC-f",
     18},
    {{0x3b, 0x14, 0x1b, 0xd7, 0xd6, 0xe1, 0xd6, 0x7e, 0x21, 0x01,
      0xa0, 0x8e, 0x4d, 0xd8, 0x49, 0xa8, 0x40, 0x8d, 0x91, 0xaa},
     "sAMMV2-USDC/alUSD",
     "yvVelo-alUSD-USDC-f",
     18},
    {{0x01, 0xc7, 0x7e, 0x8a, 0x09, 0x9e, 0x97, 0xb7, 0xb0, 0xdc,
      0xa2, 0xf9, 0x87, 0xd9, 0xbd, 0x19, 0x11, 0xcd, 0xde, 0x50},
     "vAMMV2-USDC/SNX",
     "yvVelo-SNX-USDC-f",
     18},
    {{0xb9, 0xa1, 0x4c, 0x5c, 0x76, 0x00, 0x23, 0x80, 0x1f, 0x8c,
      0x73, 0x1b, 0x46, 0x21, 0xc9, 0x9f, 0x8a, 0xc2, 0x11, 0xd9},
     "vAMMV2-SONNE/USDC",
     "yvVelo-SONNE-USDC-f",
     18},
    {{0x36, 0xba, 0xf5, 0x2b, 0xc8, 0xa2, 0xdb, 0x44, 0x50, 0x50,
      0x0c, 0x1a, 0x6c, 0x78, 0xf1, 0x0f, 0x6d, 0x0e, 0x1c, 0x3b},
     "vAMMV2-TAROTv1/USDC",
     "yvVelo-TAROT-USDC-f",
     18},
    {{0x71, 0x11, 0x7b, 0xcd, 0x8f, 0xe6, 0x91, 0x77, 0xee, 0xb8,
      0x85, 0x75, 0x38, 0xd6, 0x25, 0x20, 0x97, 0x56, 0xb7, 0x45},
     "vAMMV2-WETH/rETH",
     "yvVelo-rETH-WETH-f",
     18},
    {{0xb3, 0x53, 0x25, 0x18, 0xda, 0xca, 0x20, 0xfd, 0x14, 0xe5,
      0x39, 0xb0, 0xed, 0x6c, 0x0d, 0xe5, 0xc5, 0x9f, 0xd2, 0xde},
     "sAMMV2-WETH/frxETH",
     "yvVelo-frxETH-WETH-f",
     18},
    {{0xdd, 0xdc, 0xae, 0xe8, 0x73, 0xf2, 0xd9, 0xdf, 0x0e, 0x18,
      0xa8, 0x07, 0x09, 0xef, 0x2b, 0x39, 0x6d, 0x4a, 0x6e, 0xa5},
     "vAMMV2-WETH/OP",
     "yvVelo-OP-WETH-f",
     18},
    {{0x6e, 0xc9, 0xd0, 0x03, 0xf0, 0xe5, 0x18, 0x4e, 0xe5, 0x4c,
      0x1d, 0x89, 0x9b, 0x41, 0x43, 0x22, 0xa0, 0xf0, 0xdc, 0x07},
     "vAMMV2-wstETH/WETH",
     "yvVelo-wstETH-WETH-f",
     18},
    {{0xf7, 0xd6, 0x6b, 0x41, 0xcd, 0x42, 0x41, 0xea, 0xe4, 0x50,
      0xfd, 0x9d, 0x2d, 0x69, 0x95, 0x75, 0x46, 0x34, 0xd9, 0xf3},
     "sAMMV2-alETH/WETH",
     "yvVelo-alETH-WETH-f",
     18},
    {{0x56, 0xee, 0xf8, 0x43, 0x0d, 0xdd, 0xf9, 0x5b, 0x2b, 0x92,
      0xc5, 0x8b, 0x21, 0xed, 0xf1, 0xac, 0x7f, 0x77, 0xe6, 0xa6},
     "sAMMV2-USD+/USDC",
     "yvVelo-USD+-USDC-f",
     18},
    {{0x6a, 0xfa, 0x09, 0x14, 0x52, 0x45, 0xea, 0xed, 0xdd, 0xab,
      0x93, 0x33, 0x52, 0x3a, 0xf9, 0x98, 0x44, 0x94, 0xff, 0x34},
     "sAMMV2-USDC/LUSD",
     "yvVelo-LUSD-USDC-f",
     18},
    {{0x83, 0x0c, 0xb4, 0xaa, 0xbf, 0x78, 0x6b, 0x93, 0x49, 0xd9,
      0x70, 0x1d, 0xd8, 0xee, 0x07, 0x32, 0x15, 0xd9, 0x51, 0x74},
     "vAMMV2-wstETH/OP",
     "yvVelo-wstETH-OP-f",
     18},
    {{0x68, 0xf2, 0xb1, 0xdb, 0x2d, 0xa6, 0x20, 0x44, 0x89, 0x27,
      0x9a, 0x8f, 0xc6, 0x81, 0xf8, 0x37, 0x28, 0xbb, 0x96, 0x22},
     "sAMMV2-DOLA/MAI",
     "yvVelo-MAI-DOLA-f",
     18},
    {{0x50, 0x73, 0x43, 0xba, 0xd3, 0xa1, 0xee, 0x0b, 0x67, 0xc3,
      0xb1, 0x71, 0x21, 0x33, 0x29, 0x0d, 0xed, 0x43, 0x98, 0x0d},
     "vAMMV2-wstETH/LDO",
     "yvVelo-LDO-wstETH-f",
     18},
    {{0x3f, 0x14, 0xdf, 0x34, 0x04, 0x98, 0xf3, 0xea, 0xa2, 0x89,
      0x4b, 0xfc, 0x19, 0x78, 0x9d, 0xd5, 0x92, 0xdc, 0x06, 0x2d},
     "sAMMV2-FRAX/DOLA",
     "yvVelo-FRAX-DOLA-f",
     18},
    {{0x4f, 0x12, 0x20, 0xf6, 0x37, 0x5e, 0x95, 0xb4, 0x34, 0x62,
      0x46, 0x59, 0x72, 0xcb, 0x2f, 0x47, 0x8e, 0xd3, 0x4d, 0x0b},
     "sAMMV2-USD+/DOLA",
     "yvVelo-USD+-DOLA-f",
     18},
    {{0xf6, 0xb2, 0x72, 0x13, 0x4a, 0x19, 0x3d, 0xf5, 0xb0, 0x43,
      0x32, 0xe7, 0x31, 0x84, 0xe5, 0xb4, 0x0b, 0x8e, 0xb8, 0x10},
     "vAMMV2-STG/USDC",
     "yvVelo-STG-USDC-f",
     18},
    {{0xbc, 0x61, 0xb7, 0x15, 0x62, 0xb0, 0x1a, 0x3a, 0x48, 0x08,
      0xd3, 0xb9, 0x29, 0x1a, 0x3b, 0xf7, 0x43, 0xab, 0x33, 0x61},
     "vAMMV2-WETH/LUSD",
     "yvVelo-LUSD-WETH-f",
     18},
    {{0x6a, 0x44, 0xb0, 0x41, 0x5a, 0x5c, 0x44, 0x0d, 0x32, 0xe8,
      0x29, 0x65, 0xfd, 0xfa, 0xad, 0x54, 0xa7, 0x2d, 0x47, 0x7d},
     "sAMMV2-WETH/sETH",
     "yvVelo-sETH-WETH-f",
     18},
    {{0x45, 0xb0, 0xa7, 0xdc, 0x29, 0xb7, 0x85, 0x6a, 0x1b, 0x50,
      0x69, 0xdb, 0x4c, 0xfa, 0x2a, 0x98, 0x4b, 0x69, 0xcc, 0x41},
     "vAMMV2-THALES/WETH",
     "yvVelo-THALES-WETH-f",
     18},
    {{0x36, 0xe4, 0xc1, 0x8b, 0x2b, 0x43, 0xcc, 0x98, 0x90, 0x85,
      0xb4, 0xa7, 0x30, 0x69, 0x15, 0xb1, 0x15, 0x05, 0x8a, 0xbf},
     "sAMMV2-USDC/DAI",
     "yvVelo-DAI-USDC-f",
     18},
    {{0xc2, 0x62, 0x6a, 0xce, 0xdc, 0x27, 0xcf, 0xfb, 0x41, 0x86,
      0x80, 0xd0, 0x30, 0x7c, 0x91, 0x78, 0x95, 0x5a, 0x47, 0x43},
     "sAMMV2-sfrxETH/frxETH",
     "yvVelo-sfrxETH-frxE...",
     18},
    {{0xf5, 0xa8, 0xaf, 0x3c, 0x13, 0xc0, 0xf6, 0xc1, 0x39, 0xf5,
      0x8a, 0xac, 0x8a, 0x54, 0x91, 0x00, 0x48, 0x4e, 0x0a, 0xad},
     "vAMMV2-UNLOCK/VELO",
     "yvVelo-UNLOCK-VELO-f",
     18},
    {{0xa3, 0x1a, 0xd8, 0xd3, 0x55, 0xb5, 0x22, 0x3a, 0xd3, 0x4f,
      0xd4, 0xfd, 0x0b, 0xc8, 0x54, 0xa6, 0x8e, 0x7d, 0x96, 0x81},
     "vAMMV2-THALES/USDC",
     "yvVelo-THALES-USDC-f",
     18},
    {{0x05, 0xbb, 0xaf, 0x27, 0x42, 0x9e, 0xb3, 0x5c, 0xb3, 0xd5,
      0x1a, 0x97, 0x9a, 0xcb, 0xa6, 0x9f, 0x2f, 0x00, 0xe6, 0x6a},
     "vAMMV2-USDC/wTBT",
     "yvVelo-wTBT-USDC-f",
     18},
    {{0x66, 0x57, 0xbd, 0xb9, 0x94, 0xfc, 0x86, 0x78, 0xf6, 0xd7,
      0x09, 0x07, 0x7f, 0x30, 0xaa, 0x0b, 0x32, 0x49, 0xb5, 0xc8},
     "vAMMV2-LYRA/USDC",
     "yvVelo-LYRA-USDC-f",
     18},
    {{0x68, 0x6c, 0x12, 0x54, 0x72, 0x02, 0x4b, 0xdd, 0x3f, 0xa7,
      0x4e, 0xeb, 0x37, 0x20, 0xb3, 0x23, 0x75, 0x41, 0xdc, 0xdc},
     "vAMMV2-WETH/KWENTA",
     "yvVelo-KWENTA-WETH-f",
     18},
    {{0xaa, 0x07, 0xca, 0x79, 0x49, 0x0b, 0x3c, 0xda, 0x1a, 0x25,
      0xb8, 0xfc, 0xc6, 0x9b, 0x76, 0xc0, 0x9c, 0x6e, 0x7a, 0x4f},
     "sAMMV2-CHI/DAI",
     "yvVelo-CHI-DAI-f",
     18},
    {{0x78, 0xe2, 0x03, 0x12, 0x10, 0x5a, 0x85, 0xb7, 0xfe, 0x86,
      0xdb, 0x11, 0x9c, 0xfd, 0x5c, 0xd8, 0xde, 0x81, 0xfd, 0xaa},
     "sAMMV2-USD+/DAI+",
     "yvVelo-USD+-DAI+-f",
     18},
    {{0x4e, 0x9c, 0x59, 0xf9, 0xb1, 0xb1, 0x3b, 0xa7, 0xe1, 0xac,
      0x4c, 0x09, 0xb6, 0x4d, 0xf7, 0xfd, 0xef, 0xf4, 0x1b, 0x03},
     "sAMMV2-USDC/USX",
     "yvVelo-USX-USDC-f",
     18},
    {{0xfa, 0x3c, 0x61, 0x22, 0x90, 0x6f, 0x2a, 0x2d, 0x64, 0x44,
      0x09, 0xdb, 0xb5, 0x07, 0xdb, 0x10, 0x60, 0xd1, 0x0b, 0x3a},
     "vAMMV2-RED/OP",
     "yvVelo-RED-OP-f",
     18},
    {{0x03, 0x89, 0x4c, 0xa9, 0xb0, 0xca, 0xbf, 0xc5, 0x3d, 0xde,
      0x7c, 0x2d, 0xcf, 0xcc, 0x2a, 0x58, 0xd6, 0x19, 0x26, 0x87},
     "vAMMV2-USDC/agEUR",
     "yvVelo-agEUR-USDC-f",
     18},
    {{0x90, 0x61, 0x22, 0xac, 0x1b, 0x55, 0xb7, 0x12, 0x48, 0xab,
      0xfa, 0x55, 0x2f, 0xdc, 0x6a, 0xbd, 0x33, 0x56, 0x88, 0x4a},
     "vAMMV2-USDC/MTA",
     "yvVelo-MTA-USDC-f",
     18},
    {{0x8e, 0x8d, 0x63, 0x5e, 0x28, 0xbb, 0x87, 0x74, 0xfd, 0x23,
      0x10, 0x7c, 0xc1, 0xd9, 0xb6, 0xd3, 0x0a, 0xd5, 0xd0, 0xb9},
     "vAMMV2-IB/WETH",
     "yvVelo-IB-WETH-f",
     18},
    {{0xd0, 0xd2, 0xac, 0x44, 0xcc, 0x84, 0x20, 0x79, 0xe9, 0x78,
      0xbb, 0x11, 0xb0, 0x94, 0x76, 0x4f, 0x7d, 0x0d, 0xec, 0x6a},
     "sAMMV2-msETH/WETH",
     "yvVelo-msETH-WETH-f",
     18},
    {{0xb8, 0x3d, 0xba, 0xc6, 0x08, 0x75, 0x92, 0x32, 0x89, 0x09,
      0x99, 0x6a, 0x39, 0xd1, 0x38, 0xe8, 0x9e, 0x4b, 0x0a, 0xfe},
     "sAMMV2-FRAX/USD+",
     "yvVelo-USD+-FRAX-f",
     18},
    {{0x7b, 0xde, 0xa3, 0x1f, 0x96, 0x80, 0x89, 0xf9, 0x3a, 0x54,
      0x8d, 0xde, 0xc8, 0xbb, 0x74, 0x03, 0x6e, 0x8a, 0xc6, 0xe0},
     "sAMMV2-LUSD/ERN",
     "yvVelo-ERN-LUSD-f",
     18},
    {{0xdd, 0x76, 0xa3, 0xc9, 0x1a, 0x35, 0x8b, 0x10, 0x93, 0xde,
      0x52, 0xcb, 0x82, 0xaf, 0x5e, 0xc3, 0x28, 0x2f, 0x6f, 0x7f},
     "vAMMV2-TAROTv1/OP",
     "yvVelo-TAROT-OP-f",
     18},
    {{0x9e, 0x72, 0x4b, 0x3f, 0x65, 0xb5, 0x09, 0x32, 0x6a, 0x4f,
      0x5e, 0xc9, 0x0d, 0x46, 0x89, 0xbe, 0xe6, 0xb6, 0xc7, 0x8e},
     "sAMMV2-USDC/ERN",
     "yvVelo-ERN-USDC-f",
     18},
    {{0x87, 0xbe, 0x63, 0x0d, 0x27, 0x9b, 0xfd, 0x00, 0x47, 0x75,
      0xc1, 0x16, 0x6f, 0x8a, 0x48, 0x8b, 0x2f, 0xff, 0xa5, 0x00},
     "sAMMV2-FRAX/MAI",
     "yvVelo-MAI-FRAX-f",
     18},
    {{0xd0, 0x2c, 0xe9, 0xe2, 0x11, 0x27, 0x9a, 0xb3, 0xf4, 0x14,
      0xff, 0x7a, 0x66, 0x15, 0x18, 0xf9, 0x17, 0x37, 0x80, 0xcb},
     "sAMMV2-alUSD/MAI",
     "yvVelo-MAI-alUSD-f",
     18},
    {{0x90, 0x56, 0xb1, 0x9f, 0xde, 0x67, 0x4b, 0x5a, 0xd8, 0x39,
      0x7e, 0x7e, 0xd3, 0xe2, 0x5a, 0x1b, 0xcc, 0xef, 0x0c, 0x27},
     "sAMMV2-FRAX/alUSD",
     "yvVelo-alUSD-FRAX-f",
     18},
    {{0x7e, 0x1d, 0x45, 0x17, 0x99, 0xaf, 0x57, 0xea, 0x55, 0x70,
      0xd1, 0x01, 0x5c, 0x34, 0x2c, 0x12, 0xa9, 0x18, 0xa3, 0x0b},
     "sAMMV2-alETH/frxETH",
     "yvVelo-alETH-frxETH-f",
     18},
    {{0x50, 0x03, 0x2b, 0xe2, 0xb2, 0xc7, 0xe8, 0xa6, 0xa6, 0xbc,
      0x24, 0x1e, 0x3a, 0xeb, 0xef, 0x21, 0x49, 0x7a, 0x3c, 0xf0},
     "sAMMV2-DOLA/ERN",
     "yvVelo-ERN-DOLA-f",
     18},
    {{0xd4, 0x02, 0xf3, 0xc8, 0xa9, 0x99, 0xbf, 0xe9, 0x7f, 0x86,
      0x44, 0xe8, 0x0d, 0xbd, 0x57, 0xe2, 0xba, 0x77, 0x04, 0xae},
     "vAMMV2-QI/USDC",
     "yvVelo-QI-USDC-f",
     18},
    {{0x00, 0xcb, 0x8e, 0x36, 0xa9, 0xc4, 0x04, 0x91, 0xa3, 0x9e,
      0x8b, 0xf2, 0x86, 0x4e, 0xd3, 0x0c, 0x1b, 0x57, 0x98, 0x60},
     "sAMMV2-WBTC/tBTC",
     "yvVelo-tBTC-WBTC-f",
     18},
    {{0x00, 0xa2, 0xfa, 0xf9, 0x7c, 0xc2, 0xb9, 0x85, 0xb2, 0x9a,
      0x0a, 0x0e, 0xaa, 0x6e, 0x0d, 0x80, 0x33, 0xdc, 0x0e, 0xa1},
     "vAMMV2-WETH/tBTC",
     "yvVelo-tBTC-WETH-f",
     18},
    {{0x6f, 0x4f, 0x01, 0xa0, 0x2e, 0x60, 0x37, 0xaa, 0x98, 0xd2,
      0x24, 0x05, 0xfe, 0xa4, 0xdc, 0xab, 0x98, 0xd2, 0xa8, 0xee},
     "vAMMV2-USDC/PERP",
     "yvVelo-PERP-USDC-f",
     18},
    {{0xc3, 0x43, 0x9b, 0xa7, 0xdb, 0x75, 0x66, 0xed, 0x0d, 0xef,
      0x55, 0xc1, 0x79, 0xed, 0x9b, 0x3b, 0xa2, 0x73, 0xa6, 0x7f},
     "vAMMV2-EXA/WETH",
     "yvVelo-EXA-WETH-f",
     18},
    {{0x43, 0x36, 0x0f, 0xdd, 0x95, 0x46, 0xe3, 0xe7, 0x7a, 0xc2,
      0xe6, 0x79, 0x3f, 0x53, 0x21, 0x97, 0x29, 0x74, 0x32, 0x93},
     "vAMMV2-USDC/wUSDR",
     "yvVelo-wUSDR-USDC-f",
     18},
    {{0xc3, 0x56, 0x66, 0x62, 0x86, 0x2c, 0x26, 0xff, 0x56, 0xe3,
      0xe7, 0x09, 0xdc, 0x02, 0x19, 0x02, 0xcc, 0x68, 0xbe, 0xcd},
     "vAMMV2-TAROT/USDC",
     "yvVelo-TAROT-USDC-f",
     18},
    {{0x3b, 0xde, 0x2a, 0xb7, 0x2a, 0xfe, 0x70, 0x28, 0x6f, 0xc9,
      0x44, 0xc0, 0x7d, 0x98, 0x88, 0x3e, 0x38, 0x3d, 0xf2, 0x39},
     "vAMMV2-TAROT/OP",
     "yvVelo-TAROT-OP-f",
     18},
    {{0xa7, 0xb5, 0x50, 0xb3, 0xa8, 0x03, 0x61, 0xd8, 0xe4, 0x7e,
      0x07, 0x61, 0x6d, 0xc4, 0x2f, 0x04, 0xc6, 0x55, 0x88, 0x1b},
     "vAMMV2-stERN/ERN",
     "yvVelo-stERN-ERN-f",
     18},
    {{0x0d, 0xec, 0x85, 0xe7, 0x4a, 0x92, 0xc5, 0x2b, 0x7f, 0x70,
      0x8c, 0x4b, 0x10, 0x20, 0x7d, 0x95, 0x60, 0xce, 0xfa, 0xf0},
     "WFTM",
     "yvWFTM",
     18},
    {{0x0a, 0x0b, 0x23, 0xd9, 0x78, 0x69, 0x63, 0xde, 0x69, 0xcb,
      0x24, 0x47, 0xdc, 0x12, 0x5c, 0x49, 0x92, 0x94, 0x19, 0xd8},
     "MIM",
     "yvMIM",
     18},
    {{0xef, 0x02, 0x10, 0xeb, 0x96, 0xc7, 0xeb, 0x36, 0xaf, 0x8e,
      0xd1, 0xc2, 0x03, 0x06, 0x46, 0x27, 0x64, 0x93, 0x56, 0x07},
     "USDC",
     "yvUSDC",
     6},
    {{0x63, 0x7e, 0xc6, 0x17, 0xc8, 0x6d, 0x24, 0xe4, 0x21, 0x32,
      0x8e, 0x6c, 0xae, 0xa1, 0xd9, 0x21, 0x14, 0x89, 0x24, 0x39},
     "DAI",
     "yvDAI",
     18},
    {{0x2c, 0x85, 0x0c, 0xce, 0xd0, 0x0c, 0xe2, 0xb1, 0x4a, 0xa9,
      0xd6, 0x58, 0xb7, 0xca, 0xd5, 0xdf, 0x65, 0x94, 0x93, 0xdb},
     "YFI",
     "yvYFI",
     18},
    {{0x35, 0x7c, 0xa4, 0x6d, 0xa2, 0x6e, 0x1e, 0xef, 0xc1, 0x95,
      0x28, 0x7c, 0xe9, 0xd8, 0x38, 0xa6, 0xd5, 0x02, 0x3e, 0xf3},
     "FRAX",
     "yvFRAX",
     18},
    {{0x14, 0x8c, 0x05, 0xca, 0xf1, 0xbb, 0x09, 0xb5, 0x67, 0x0f,
      0x00, 0xd5, 0x11, 0x71, 0x8f, 0x73, 0x3c, 0x54, 0xbc, 0x4c},
     "fUSDT",
     "yvUSDT",
     6},
    {{0xf1, 0x37, 0xd2, 0x2d, 0x7b, 0x23, 0xee, 0xb1, 0x95, 0x0b,
      0x3e, 0x19, 0xd1, 0xf5, 0x78, 0xc0, 0x53, 0xed, 0x97, 0x15},
     "g3CRV",
     "yvCurve-Geist",
     18},
    {{0xcb, 0xca, 0xf8, 0xcb, 0x8c, 0xbe, 0xaf, 0xa9, 0x27, 0xec,
      0xee, 0x0c, 0x5c, 0x56, 0x56, 0x0f, 0x83, 0xe9, 0xb7, 0xd9},
     "crv3crypto",
     "yvCurve-Tricrypto",
     18},
    {{0x04, 0x46, 0xac, 0xab, 0x3e, 0x02, 0x42, 0xfc, 0xf3, 0x3a,
      0xa5, 0x26, 0xf1, 0xc9, 0x5a, 0x88, 0x06, 0x8d, 0x50, 0x42},
     "CRV",
     "yvCRV",
     18},
    {{0xce, 0x2f, 0xc0, 0xbd, 0xc1, 0x8b, 0xd6, 0xa4, 0xd9, 0xa7,
      0x25, 0x79, 0x1a, 0x3d, 0xee, 0x33, 0xf3, 0xa2, 0x3b, 0xb7},
     "ETH",
     "yvWETH",
     18},
    {{0xd8, 0x17, 0xa1, 0x00, 0xab, 0x8a, 0x29, 0xfe, 0x3d, 0xbd,
      0x92, 0x5c, 0x2e, 0xb4, 0x89, 0xd6, 0x7f, 0x75, 0x8d, 0xa9},
     "BTC",
     "yvWBTC",
     8},
    {{0xd3, 0xc1, 0x9e, 0xb0, 0x22, 0xca, 0xc7, 0x06, 0xc8, 0x98,
      0xd6, 0x0d, 0x75, 0x6b, 0xf1, 0x53, 0x5d, 0x60, 0x5e, 0x1d},
     "SPELL",
     "yvSPELL",
     18},
    {{0x1b, 0x48, 0x64, 0x1d, 0x82, 0x51, 0xc3, 0xe8, 0x4e, 0xcb,
      0xe3, 0xf2, 0xbd, 0x76, 0xb3, 0x70, 0x14, 0x01, 0x90, 0x6d},
     "DOLA",
     "yvDOLA",
     18},
    {{0xf2, 0xd3, 0x23, 0x62, 0x17, 0x85, 0xa0, 0x66, 0xe6, 0x42,
      0x82, 0xd2, 0xb4, 0x07, 0xea, 0xc7, 0x9c, 0xc0, 0x49, 0x66},
     "LINK",
     "yvLINK",
     18},
    {{0x0f, 0xbb, 0xf9, 0x84, 0x8d, 0x96, 0x97, 0x76, 0xa5, 0xeb,
      0x84, 0x2e, 0xda, 0xfa, 0xf2, 0x9e, 0xf4, 0x46, 0x76, 0x98},
     "BOO",
     "yvBOO",
     18},
    {{0x1e, 0x2f, 0xe8, 0x07, 0x4a, 0x5c, 0xe1, 0xbb, 0x73, 0x94,
      0x85, 0x6b, 0x0c, 0x61, 0x8e, 0x75, 0xd8, 0x23, 0xb9, 0x3b},
     "fBEETS",
     "yvfBEETS",
     18},
    {{0xa9, 0x7e, 0x7d, 0xa0, 0x1c, 0x70, 0x47, 0xd6, 0xa6, 0x5f,
      0x89, 0x4c, 0x99, 0xbe, 0x8c, 0x83, 0x22, 0x27, 0xa8, 0xbc},
     "3poolV2-f",
     "yvCurve-MIM",
     18},
    {{0x00, 0x46, 0x26, 0xA0, 0x08, 0xB1, 0xaC, 0xdC, 0x4c, 0x74,
      0xab, 0x51, 0x64, 0x40, 0x93, 0xb1, 0x55, 0xe5, 0x9A, 0x23},
     "stEUR",
     "stEUR",
     18},
    {{0x88, 0x9e, 0xdC, 0x2e, 0xDa, 0xb5, 0xf4, 0x0e, 0x90, 0x2b,
      0x86, 0x4a, 0xD4, 0xd7, 0xAd, 0xE8, 0xE4, 0x12, 0xF9, 0xB1},
     "unstETH",
     "unstETH",
     18},
};