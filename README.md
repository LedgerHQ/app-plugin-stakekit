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
| TransparentUpgradeableProxy    | 0x0c0a769b | supply |
| TransparentUpgradeableProxy    | 0xf2b9fdb8 | supply |
| TransparentUpgradeableProxy    | 0xf62256c7 | supply |
| TransparentUpgradeableProxy    | 0xf3fef3a3 | withdraw |
| TransparentUpgradeableProxy    | 0x69328dec | withdraw |
| InitializableAdminUpgradeabilityProxy    | 0x47e7ef24 | deposit |
| InitializableAdminUpgradeabilityProxy    | 0x2e1a7d4d | withdraw |


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
