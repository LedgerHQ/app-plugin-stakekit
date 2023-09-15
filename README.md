# Badges
<Plugin Github Action Badger>

# Ledger StakeKit Plugin

This is a plugin for the Ethereum application which helps parsing and displaying relevant information when signing a StakeKit transaction.

## Prerequisite

Clone the plugin to a new folder.

```shell
git clone https://github.com/blooo-io/LedgerHQ-app-plugin-stakekit.git
```

Then in the same folder clone two more repositories, which is the plugin-tools and app-ethereum.

```shell
git clone https://github.com/LedgerHQ/plugin-tools.git                          #plugin-tools
git clone --recurse-submodules https://github.com/LedgerHQ/app-ethereum.git     #app-ethereum
```
## Documentation

Need more information about the interface, the architecture, or general stuff about ethereum plugins? You can find more about them in the [ethereum-app documentation](https://github.com/LedgerHQ/app-ethereum/blob/master/doc/ethapp_plugins.asc).

## Smart Contracts

Smart contracts covered by this plugin are:

| Network | Smart Contract Name | Smart Contract Address|
| ---       | --- | --- |
| Ethereum  | ApeCoinStaking | 0x5954ab967bc958940b7eb73ee84797dc8a2afbb9|
| Ethereum  | AppProxyUpgradeable | 0xae7ab96520de3a18e5e111b5eaab095312d7fe84|
| Ethereum  | RocketSwapRouter | 0x16d5a408e807db8ef7c578279beeee6b228f1c1c|
| Ethereum  | AdminUpgradeabilityProxy | 0xc874b064f465bdd6411d45734b56fac750cda29a|
| Ethereum  | TransparentUpgradeableProxy | 0x9ee91f9f426fa633d227f7a9b000e28b9dfd8599|
| Ethereum  | ValidatorShareProxy | 0x857679d69fe50e7b722f94acd2629d80c355163d|
| Ethereum  | TransparentUpgradeableProxy | 0x777777c9898d384f785ee44acfe945efdff5f3e0|
| Ethereum  | InitializableAdminUpgradeabilityProxy | 0xc5c9fb6223a989208df27dcee33fc59ff5c26fff|
| Ethereum  | GraphProxy | 0xf55041e37e12cd407ad00ce2910b8269b01263b9|
| Ethereum  | SushiBar | 0x8798249c2e607446efb7ad49ec89dd1865ff4272|
| Ethereum  | TransparentUpgradeableProxy | 0xc3d688b66703497daa19211eedff47f25384cdc3|
| Ethereum  | CometRewards | 0x1b0e765f6224c21223aea2af16c1c46e38885a40|
| Polygon  | TransparentUpgradeableProxy | 0xf25212e676d1f7f89cd72ffee66158f541246445|
| Polygon  | CometRewards | 0x45939657d1ca34a8fa39a924b71d28fe8431e581|
| Polygon  | InitializableImmutableAdminUpgradeabilityProxy | 0x794a61358d6845594f94dc1db02a252b5b4814ad|
| BSC  | TokenHub | 0x0000000000000000000000000000000000001004|
| Celo  | AccountsProxy | 0x7d21685c17607338b313a7174bab6620bad0aab7|
| Celo  | LockedGoldProxy | 0x6cc083aed9e3ebe302a6336dbc7c921c9f03349e|
| Celo  | ElectionProxy | 0x8d6677192144292870907e3fa8a5527fe55a7ff6|
| Avalanche  | InitializableImmutableAdminUpgradeabilityProxy | 0x794a61358d6845594f94dc1db02a252b5b4814ad|
| Optimism  | InitializableImmutableAdminUpgradeabilityProxy | 0x794a61358d6845594f94dc1db02a252b5b4814ad|
| Arbitrum  | InitializableImmutableAdminUpgradeabilityProxy | 0x794a61358d6845594f94dc1db02a252b5b4814ad|


## Methods

Methods covered by this plugin are:

| Conrtact Name | Selector | Method Name |
|      ---      |    ---   |     ---     |
| ApeCoinStaking    | 0x9dcaafb4 | depositSelfApeCoin |
| ApeCoinStaking    | 0x7f60d338 | withdrawSelfApeCoin |
| ApeCoinStaking    | 0x8279e760 | claimSelfApeCoin |
| AppProxyUpgradeable    | 0xa1903eab | submit |
| RocketSwapRouter    | 0x55362f4d | swapTo |
| RocketSwapRouter    | 0xa824ae8b | swapFrom |
| AdminUpgradeabilityProxy    | 0x3a4b66f1 | stake |
| TransparentUpgradeableProxy    | 0xf532e86a | submit |
| TransparentUpgradeableProxy    | 0xccc143b8 | requestWithdraw |
| TransparentUpgradeableProxy    | 0x46e04a2f | claimTokens |
| ValidatorShareProxy    | 0x6ab15071 | buyVoucher |
| ValidatorShareProxy    | 0xc83ec04d | sellVoucher_new |
| ValidatorShareProxy    | 0xc7b8981c | withdrawRewards |
| ValidatorShareProxy    | 0xe97fddc2 | unstakeClaimTokens_new |
| TransparentUpgradeableProxy    | 0x0c0a769b | supply |
| TransparentUpgradeableProxy    | 0xf2b9fdb8 | supply |
| TransparentUpgradeableProxy    | 0xf62256c7 | supply |
| TransparentUpgradeableProxy    | 0xf3fef3a3 | withdraw |
| TransparentUpgradeableProxy    | 0x69328dec | withdraw |
| InitializableAdminUpgradeabilityProxy    | 0x47e7ef24 | deposit |
| InitializableAdminUpgradeabilityProxy    | 0x2e1a7d4d | withdraw |
| GraphProxy    | 0x026e402b | delegate |
| GraphProxy    | 0x4d99dd16 | undelegate |
| GraphProxy    | 0x51a60b02 | withdrawDelegated |
| SushiBar    | 0xa59f3e0c | enter |
| SushiBar    | 0x67dfd4c9 | leave |
| TransparentUpgradeableProxy    | 0xf2b9fdb8 | supply |
| TransparentUpgradeableProxy    | 0xf3fef3a3 | withdraw |
| CometRewards    | 0xb7034f7e | claim |
| TokenHub    | 0xaa7415f5 | transferOut |
| AccountsProxy    | 0x9dca362f | createAccount |
| LockedGoldProxy    | 0xf83d08ba | lock |
| LockedGoldProxy    | 0x6198e339 | unlock |
| ElectionProxy    | 0x580d747a | vote |
| ElectionProxy    | 0x6e198475 | revokeActive |
| InitializableImmutableAdminUpgradeabilityProxy    | 0x617ba037 | supply |
| InitializableImmutableAdminUpgradeabilityProxy    | 0x69328dec | withdraw |


## Build

Go to the plugin-tools folder and run the "./start" script.
```shell
cd plugin-tools  # go to plugin folder
./start.sh       # run the script start.sh
```
The script will build a docker image and attach a console.
When the docker image is running go to the "LedgerHQ-app-plugin-stakekit" folder and build the ".elf" files.
```shell
cd LedgerHQ-app-plugin-stakekit/tests       # go to the tests folder in LedgerHQ-app-plugin-stakekit
./build_local_test_elfs.sh              # run the script build_local_test_elfs.sh
```

## Tests

To test the plugin go to the tests folder from the "LedgerHQ-app-plugin-stakekit" and run the script "test"
```shell
cd LedgerHQ-app-plugin-stakekit/tests       # go to the tests folder in LedgerHQ-app-plugin-stakekit
yarn test                       # run the script test
```
## Continuous Integration


The flow processed in [GitHub Actions](https://github.com/features/actions) is the following:

- Code formatting with [clang-format](http://clang.llvm.org/docs/ClangFormat.html)
- Compilation of the application for Ledger Nano S in [ledger-app-builder](https://github.com/LedgerHQ/ledger-app-builder)
