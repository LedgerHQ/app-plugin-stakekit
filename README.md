# Badges
<Plugin Github Action Badger>

# Ledger StakeKit Plugin

This is a plugin for the Ethereum application which helps parsing and displaying relevant information when signing a StakeKit transaction.

## Prerequisite

Clone the plugin to a new folder.

```shell
git clone https://github.com/blooo-io/LedgerHQ-app-plugin-stakekit.git
```

Then in the same folder clone one more repository, which is the app-ethereum.

```shell
git clone --recurse-submodules https://github.com/LedgerHQ/app-ethereum.git     #app-ethereum
```
## Documentation

Need more information about the interface, the architecture, or general stuff about ethereum plugins? You can find more about them in the [ethereum-app documentation](https://github.com/LedgerHQ/app-ethereum/blob/master/doc/ethapp_plugins.asc).

## Smart Contracts

Smart contracts covered by this plugin are:

| Network | Smart Contract Name | Smart Contract Address| Proxy Name | Proxy smart contract |
| ---       | --- | --- | --- | --- |
| Ethereum  | ApeCoinStaking | 0x5954ab967bc958940b7eb73ee84797dc8a2afbb9| X | X |
| Ethereum  | AppProxyUpgradeable | 0xae7ab96520de3a18e5e111b5eaab095312d7fe84| Lido | 0x17144556fd3424EDC8Fc8A4C940B2D04936d17eb |
| Ethereum  | RocketSwapRouter | 0x16d5a408e807db8ef7c578279beeee6b228f1c1c| X | X |
| Ethereum  | AdminUpgradeabilityProxy | 0xc874b064f465bdd6411d45734b56fac750cda29a| Pool | 0x61975c09207c5DFe794b0A652C8CAf8458159AAe |
| Ethereum  | TransparentUpgradeableProxy | 0x9ee91f9f426fa633d227f7a9b000e28b9dfd8599| StMATIC | 0x6c25AEbD494a9984A3d7C8CF395c8713E0C74D98 |
| Ethereum  | ValidatorShareProxy | 0x857679d69fe50e7b722f94acd2629d80c355163d| ValidatorShare | 0xf98864DA30a5bd657B13e70A57f5718aBf7BAB31 |
| Ethereum  | TransparentUpgradeableProxy | 0x777777c9898d384f785ee44acfe945efdff5f3e0| Morpho | 0xFBc7693f114273739C74a3FF028C13769C49F2d0 |
| Ethereum  | InitializableAdminUpgradeabilityProxy | 0xc5c9fb6223a989208df27dcee33fc59ff5c26fff| AutoCompoundApe | 0x1Ba6891D74b3B1f84b3EdFa6538D99eE979E8B63 |
| Ethereum  | GraphProxy | 0xf55041e37e12cd407ad00ce2910b8269b01263b9| L1Staking | 0x20a14D78848BC8B3F3d4B77239F2adC3C0259A10 |
| Ethereum  | SushiBar | 0x8798249c2e607446efb7ad49ec89dd1865ff4272| X | X |
| Ethereum  | TransparentUpgradeableProxy | 0xc3d688b66703497daa19211eedff47f25384cdc3| Comet | 0xBFC4FeEc175996C08C8F3a0469793a7979526065 |
| Ethereum  | CometRewards | 0x1b0e765f6224c21223aea2af16c1c46e38885a40| X | X |
| Ethereum  | Yearn Vault | [Token json](./tokens.json) |
| Polygon  | TransparentUpgradeableProxy | 0xf25212e676d1f7f89cd72ffee66158f541246445| Comet | 0x4149BF3b11a90817B138b1D25BE640Ac4925a175 |
| Polygon  | CometRewards | 0x45939657d1ca34a8fa39a924b71d28fe8431e581| X | X |
| Polygon  | InitializableImmutableAdminUpgradeabilityProxy | 0x794a61358d6845594f94dc1db02a252b5b4814ad| Pool | 0xb77fc84a549ecc0b410d6fa15159C2df207545a3 |
| BSC  | TokenHub | 0x0000000000000000000000000000000000001004| X | X |
| Celo  | AccountsProxy | 0x7d21685c17607338b313a7174bab6620bad0aab7| Accounts | X | 0x75Ec00c4B09574945F7d407797f8b61ca5AD9Cef |
| Celo  | LockedGoldProxy | 0x6cc083aed9e3ebe302a6336dbc7c921c9f03349e| LockedGold | 0xdEBe38061Db542E8c2AF2427a312f70816965E93 |
| Celo  | ElectionProxy | 0x8d6677192144292870907e3fa8a5527fe55a7ff6| Election | 0xCdE5039e3AcB3483aEebEBd59Cf6936056c455D4 |
| Avalanche  | InitializableImmutableAdminUpgradeabilityProxy | 0x794a61358d6845594f94dc1db02a252b5b4814ad| Pool | 0xCf85FF1c37c594a10195F7A9Ab85CBb0a03f69dE
| Avalanche  | TransparentUpgradeableProxy | 0x2b2c81e08f1af8835a78bb2a90ae924ace0ea4be| StakedAvax | 0x0CE7F620Eb645a4FbF688a1C1937bC6CB0CbDd29 |
| Optimism  | InitializableImmutableAdminUpgradeabilityProxy | 0x794a61358d6845594f94dc1db02a252b5b4814ad| L2Pool | 0x764594F8e9757edE877B75716f8077162B251460 |
| Optimism  | Yearn Vault | [Token json](./tokens.json) |
| Arbitrum  | InitializableImmutableAdminUpgradeabilityProxy | 0x794a61358d6845594f94dc1db02a252b5b4814ad| L2Pool | 0xbCb167bDCF14a8F791d6f4A6EDd964aed2F8813B |
| Fantom  | Yearn Vault | [Token json](./tokens.json) |


## Methods

Methods covered by this plugin are:

| Conrtact Name | Selector | Method Name |
|      ---      |    ---   |     ---     |
| ApeCoinStaking    | 0x9dcaafb4 | depositSelfApeCoin |
| ApeCoinStaking    | 0x7f60d338 | withdrawSelfApeCoin |
| ApeCoinStaking    | 0x8279e760 | claimSelfApeCoin |
| Lido    | 0xa1903eab | submit |
| RocketSwapRouter    | 0x55362f4d | swapTo |
| RocketSwapRouter    | 0xa824ae8b | swapFrom |
| Pool    | 0x3a4b66f1 | stake |
| StMATIC    | 0xf532e86a | submit |
| StMATIC    | 0xccc143b8 | requestWithdraw |
| StMATIC    | 0x46e04a2f | claimTokens |
| ValidatorShare    | 0x6ab15071 | buyVoucher |
| ValidatorShare    | 0xc83ec04d | sellVoucher_new |
| ValidatorShare    | 0xc7b8981c | withdrawRewards |
| ValidatorShare    | 0xe97fddc2 | unstakeClaimTokens_new |
| Morpho    | 0x0c0a769b | supply |
| Morpho    | 0xf2b9fdb8 | supply |
| Morpho    | 0xf62256c7 | supply |
| Morpho    | 0xf3fef3a3 | withdraw |
| Morpho    | 0x69328dec | withdraw |
| AutoCompoundApe    | 0x47e7ef24 | deposit |
| AutoCompoundApe    | 0x2e1a7d4d | withdraw |
| L1Staking    | 0x026e402b | delegate |
| L1Staking    | 0x4d99dd16 | undelegate |
| L1Staking    | 0x51a60b02 | withdrawDelegated |
| SushiBar    | 0xa59f3e0c | enter |
| SushiBar    | 0x67dfd4c9 | leave |
| Comet    | 0xf2b9fdb8 | supply |
| Comet    | 0xf3fef3a3 | withdraw |
| CometRewards    | 0xb7034f7e | claim |
| TokenHub    | 0xaa7415f5 | transferOut |
| Accounts    | 0x9dca362f | createAccount |
| LockedGold    | 0xf83d08ba | lock |
| LockedGold    | 0x6198e339 | unlock |
| Election    | 0x580d747a | vote |
| Election    | 0x6e198475 | revokeActive |
| L2Pool / Pool | 0x617ba037 | supply |
| L2Pool / Pool | 0x69328dec | withdraw |
| StakedAvax    | 0x5bcb2fc6 | submit |
| StakedAvax    | 0xc9d2ff9d | requestUnlock |
| StakedAvax    | 0xdb006a75 | redeem |
| StakedAvax    | 0xbe040fb0 | redeem |
| StakedAvax    | 0x0d10d32c | redeemOverdueShares |
| StakedAvax    | 0x0f7e2048 | redeemOverdueShares |
| Yearn Vault    | 0xd0e30db0 | deposit |
| Yearn Vault    | 0xb6b55f25 | deposit |
| Yearn Vault    | 0x6e553f65 | deposit |
| Yearn Vault    | 0x3ccfd60b | withdraw |
| Yearn Vault    | 0x2e1a7d4d | withdraw |
| Yearn Vault    | 0x00f714ce | withdraw |


## Build

Go to the global folder and run the below command.
```shell
sudo docker run --rm -ti -v "$(realpath .):/app" --user $(id -u $USER):$(id -g $USER) ghcr.io/ledgerhq/ledger-app-builder/ledger-app-dev-tools:latest
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
## Loading on a physical device

This step will vary slightly depending on your platform.

Your physical device must be connected, unlocked and the screen showing the dashboard (not inside an application).

**Linux (Ubuntu)**

First make sure you have the proper udev rules added on your host :

```shell
# Run these commands on your host, from the app's source folder.
sudo cp .vscode/20-ledger.ledgerblue.rules /etc/udev/rules.d/
sudo udevadm control --reload-rules 
sudo udevadm trigger
```

Then once you have [opened a terminal](#with-a-terminal) in the `app-builder` image and [built the app](#compilation-and-load) for the device you want, run the following command :

```shell
# Run this command from the app-builder container terminal.
make load    # load the app on a Nano S by default
```

[Setting the BOLOS_SDK environment variable](#compilation-and-load) will allow you to load on whichever supported device you want.

**macOS / Windows (with PowerShell)**

It is assumed you have [Python](https://www.python.org/downloads/) installed on your computer.

Run these commands on your host from the app's source folder once you have [built the app](#compilation-and-load) for the device you want :

```shell
# Install Python virtualenv
python3 -m pip install virtualenv 
# Create the 'ledger' virtualenv
python3 -m virtualenv ledger
```

Enter the Python virtual environment

* macOS : `source ledger/bin/activate`
* Windows : `.\ledger\Scripts\Activate.ps1`

```shell
# Install Ledgerblue (tool to load the app)
python3 -m pip install ledgerblue 
# Load the app.
python3 -m ledgerblue.runScript --scp --fileName bin/app.apdu --elfFile bin/app.elf
```
## Continuous Integration


The flow processed in [GitHub Actions](https://github.com/features/actions) is the following:

- Code formatting with [clang-format](http://clang.llvm.org/docs/ClangFormat.html)
- Compilation of the application for Ledger Nano S in [ledger-app-builder](https://github.com/LedgerHQ/ledger-app-builder)
