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

| Module | Network | Smart Contract Name | Smart Contract Address| Proxy Name | Proxy smart contract |
| ---     | ---       | --- | --- | --- | --- |
| APE Native Staking | Ethereum | ApeCoinStaking | 0x5954ab967bc958940b7eb73ee84797dc8a2afbb9| X | X |
| ETH Lido Staking | Ethereum  | AppProxyUpgradeable | 0xae7ab96520de3a18e5e111b5eaab095312d7fe84| Lido | 0x17144556fd3424EDC8Fc8A4C940B2D04936d17eb |
| ETH rETH Staking | Ethereum  | RocketSwapRouter | 0x16d5a408e807db8ef7c578279beeee6b228f1c1c| X | X |
| ETH Stakewise Liquid Staking | Ethereum  | AdminUpgradeabilityProxy | 0xc874b064f465bdd6411d45734b56fac750cda29a| Pool | 0x61975c09207c5DFe794b0A652C8CAf8458159AAe |
| MATIC Lido Liquid | Ethereum  | TransparentUpgradeableProxy | 0x9ee91f9f426fa633d227f7a9b000e28b9dfd8599| StMATIC | 0x6c25AEbD494a9984A3d7C8CF395c8713E0C74D98 |
| MATIC Native Staking | Ethereum  | ValidatorShareProxy | 0x857679d69fe50e7b722f94acd2629d80c355163d| ValidatorShare | 0xf98864DA30a5bd657B13e70A57f5718aBf7BAB31 |
| Morpho Lending | Ethereum  | TransparentUpgradeableProxy | 0x777777c9898d384f785ee44acfe945efdff5f3e0| Morpho | 0xFBc7693f114273739C74a3FF028C13769C49F2d0 |
| Paraspace cAPE Staking | Ethereum  | InitializableAdminUpgradeabilityProxy | 0xc5c9fb6223a989208df27dcee33fc59ff5c26fff| AutoCompoundApe | 0x1Ba6891D74b3B1f84b3EdFa6538D99eE979E8B63 |
| GRT Native Staking | Ethereum  | GraphProxy | 0xf55041e37e12cd407ad00ce2910b8269b01263b9| L1Staking | 0x20a14D78848BC8B3F3d4B77239F2adC3C0259A10 |
| SUSHI xSUSHI Staking | Ethereum  | SushiBar | 0x8798249c2e607446efb7ad49ec89dd1865ff4272| X | X |
| Compound V3 USDC | <table>  <tbody>  <tr> <td><code>Ethereum</code></td></tr> <tr><td><code>Ethereum</code></td></tr> <tr><td><code>Polygon</code></td></tr> <tr><td><code>Polygon</code></td></tr></tbody> </table>  | <table>  <tbody>  <tr> <td><code>TransparentUpgradeableProxy</code></td></tr> <tr><td><code>CometRewards</code></td></tr> <tr><td><code>TransparentUpgradeableProxy</code></td></tr> <tr><td><code>CometRewards</code></td></tr> </tbody> </table> |  <table>  <tbody>  <tr> <td><code>0xc3d688b66703497daa19211eedff47f25384cdc3</code></td></tr> <tr><td><code>0x1b0e765f6224c21223aea2af16c1c46e38885a40</code></td></tr> <tr><td><code>0xf25212e676d1f7f89cd72ffee66158f541246445</code></td></tr> <tr><td><code>0x45939657d1ca34a8fa39a924b71d28fe8431e581</code></td></tr></tbody> </table> | <table>  <tbody>  <tr> <td><code>Comet</code></td></tr> <tr><td><code>X</code></td></tr></tbody> <tr><td><code>Comet</code></td></tr> <tr><td><code>X</code></td></tr></table> | <table>  <tbody>  <tr> <td><code>0xBFC4FeEc175996C08C8F3a0469793a7979526065</code></td></tr> <tr><td><code>X</code></td></tr> <tr><td><code>0x4149BF3b11a90817B138b1D25BE640Ac4925a175</code></td></tr> <tr><td><code>X</code></td></tr></tbody> </table> |
| BNB Native Staking (Legacy) | BSC  | TokenHub | 0x0000000000000000000000000000000000001004| X | X |
| Celo Native Staking | Celo  | <table> <tbody> <tr> <td><code>AccountsProxy</code></td></tr> <tr><td><code>LockedGoldProxy</code></td></tr> <tr><td><code>ElectionProxy</code></td></tr></tbody> </table> | <table> <tbody> <tr> <td><code>0x7d21685c17607338b313a7174bab6620bad0aab7</code></td></tr> <tr><td><code>0x6cc083aed9e3ebe302a6336dbc7c921c9f03349e</code></td></tr> <tr><td><code>0x8d6677192144292870907e3fa8a5527fe55a7ff6</code></td></tr></tbody> </table>| <table> <tbody> <tr> <td><code>Accounts</code></td></tr> <tr><td><code>LockedGold</code></td></tr> <tr><td><code>Election</code></td></tr></tbody> </table> |<table> <tbody> <tr> <td><code>0x75Ec00c4B09574945F7d407797f8b61ca5AD9Cef</code></td></tr> <tr><td><code>0xdEBe38061Db542E8c2AF2427a312f70816965E93</code></td></tr> <tr><td><code>0xCdE5039e3AcB3483aEebEBd59Cf6936056c455D4</code></td></tr></tbody> </table>  |
| Avalanche Liquid Staking | Avalanche  | TransparentUpgradeableProxy | 0x2b2c81e08f1af8835a78bb2a90ae924ace0ea4be| StakedAvax | 0x0CE7F620Eb645a4FbF688a1C1937bC6CB0CbDd29 |
|Aave v3 Lending DAI | <table>  <tbody>  <tr> <td><code>Optimism</code></td></tr> <tr><td><code>Polygon</code></td></tr> <tr><td><code>Arbitrum</code></td></tr> <tr><td><code>Avalanche</code></td></tr> </tbody> </table>   |InitializableImmutableAdminUpgradeabilityProxy | 0x794a61358d6845594f94dc1db02a252b5b4814ad | <table>  <tbody>  <tr> <td><code>Pool</code></td></tr> <tr><td><code>Pool</code></td></tr> <tr><td><code>L2Pool</code></td></tr> <tr><td><code>L2Pool</code></td></tr> </tbody> </table> | <table>  <tbody>  <tr> <td><code>0xb77fc84a549ecc0b410d6fa15159C2df207545a3</code></td></tr> <tr><td><code>0xCf85FF1c37c594a10195F7A9Ab85CBb0a03f69dE</code></td></tr> <tr><td><code>0x764594F8e9757edE877B75716f8077162B251460</code></td></tr> <tr><td><code>0xbCb167bDCF14a8F791d6f4A6EDd964aed2F8813B</code></td></tr> </tbody> </table>
|Yearn Vault | <table>  <tbody>  <tr> <td><code>Ethereum</code></td></tr> <tr><td><code>Optimism</code></td></tr> <tr><td><code>Fantom</code></td></tr> </tbody> </table>   | Yearn Vault | [Token json](./tokens.json) |
| Angle Protocol | <table><tbody> <tr><td><code>Ethereum</code></td></tr> <tr><td><code>Arbitrum</code></td></tr> </tbody></table> | TransparentUpgradeableProxy | 0x004626A008B1aCdC4c74ab51644093b155e59A23| Savings | 0xfD2cCc920d498db30FBE9c13D5705aE2C72670F9 |
| Lido stETH Withdrawal NFT | Ethereum | OssifiableProxy | 0x889edC2eDab5f40e902b864aD4d7AdE8E412F9B1| WithdrawalQueueERC721 | 0xE42C659Dc09109566720EA8b2De186c2Be7D94D9 |
| VIC Native Staking | Viction | TomoValidator | 0x0000000000000000000000000000000000000088| X | X |
| BNB Native Staking | BSC        | StakeHub       | 0x0000000000000000000000000000000000002002| X | X |


## Methods

Methods covered by this plugin are:

| Module | Conrtact Name | Selector | Method Name |
|   ---  |      ---      |    ---   |     ---     |
| APE Native Staking | ApeCoinStaking    | <table><tbody>  <tr><td><code>0x9dcaafb4</code></td></tr> <tr><td><code>0x7f60d338</code></td></tr> <tr><td><code>0x8279e760</code></td></tr> </tbody></table> | <table><tbody>  <tr><td><code>depositSelfApeCoin</code></td></tr> <tr><td><code>withdrawSelfApeCoin</code></td></tr> <tr><td><code>claimSelfApeCoin</code></td></tr> </tbody></table> |
| ETH Lido Staking | Lido    | 0xa1903eab | submit |
| ETH rETH Staking | RocketSwapRouter    | <table><tbody>  <tr><td><code>0x55362f4d</code></td></tr> <tr><td><code>0xa824ae8b</code></td></tr> </tbody></table> | <table><tbody>  <tr><td><code>swapTo</code></td></tr> <tr><td><code>swapFrom</code></td></tr> </tbody></table> |
| ETH stakewise Liquid Staking | Pool    | 0x3a4b66f1 | stake |
| MATIC Lido Liquid | StMATIC    | <table><tbody>  <tr><td><code>0xf532e86a</code></td></tr> <tr><td><code>0xccc143b8</code></td></tr> <tr><td><code>0x46e04a2f</code></td></tr> </tbody></table> | <table><tbody>  <tr><td><code>submit</code></td></tr> <tr><td><code>requestWithdraw</code></td></tr> <tr><td><code>claimTokens</code></td></tr> </tbody></table> |
| MATIC Native Staking | ValidatorShare    | <table><tbody>  <tr><td><code>0x6ab15071</code></td></tr> <tr><td><code>0xc83ec04d</code></td></tr> <tr><td><code>0xc7b8981c</code></td></tr> <tr><td><code>0xe97fddc2</code></td></tr> </tbody></table> | <table><tbody>  <tr><td><code>buyVoucher</code></td></tr> <tr><td><code>sellVoucher_new</code></td></tr> <tr><td><code>withdrawRewards</code></td></tr> <tr><td><code>unstakeClaimTokens_new</code></td></tr> </tbody></table> |
| Morpho lending | Morpho    | <table><tbody>  <tr><td><code>0x0c0a769b</code></td></tr> <tr><td><code>0xf2b9fdb8</code></td></tr> <tr><td><code>0xf62256c7</code></td></tr> <tr><td><code>0xf3fef3a3</code></td></tr> <tr><td><code>0x69328dec</code></td></tr> </tbody></table> | <table><tbody>  <tr><td><code>supply</code></td></tr> <tr><td><code>supply</code></td></tr> <tr><td><code>supply</code></td></tr> <tr><td><code>withdraw</code></td></tr> <tr><td><code>withdraw</code></td></tr> </tbody></table> |
| Paraspace cAPE Staking | AutoCompoundApe    | <table><tbody>  <tr><td><code>0x47e7ef24</code></td></tr> <tr><td><code>0x2e1a7d4d</code></td></tr> </tbody></table>  | <table><tbody>  <tr><td><code>deposit</code></td></tr> <tr><td><code>withdraw</code></td></tr> </tbody></table> |
| GRT Native Staking | L1Staking    | <table><tbody>  <tr><td><code>0x026e402b</code></td></tr> <tr><td><code>0x4d99dd16</code></td></tr> <tr><td><code>0x51a60b02</code></td></tr> </tbody></table>  | <table><tbody> <tr><td><code>delegate</code></td></tr> <tr><td><code>undelegate</code></td></tr> <tr><td><code>withdrawDelegated</code></td></tr> </tbody></table> |
| SUSHI xSUSHI Staking | SushiBar    | <table><tbody>  <tr><td><code>0xa59f3e0c</code></td></tr> <tr><td><code>0x67dfd4c9</code></td></tr> </tbody></table> | <table><tbody>  <tr><td><code>enter</code></td></tr> <tr><td><code>leave</code></td></tr> </tbody></table> |
|Compound V3 USDC | <table><tbody>  <tr><td><code>Comet</code></td></tr> <tr><td><code>Comet</code></td></tr> <tr><td><code>CometRewards</code></td></tr> </tbody></table>    | <table><tbody>  <tr><td><code>0xf2b9fdb8</code></td></tr> <tr><td><code>0xf3fef3a3</code></td></tr> <tr><td><code>0xb7034f7e</code></td></tr> </tbody></table> | <table><tbody>  <tr><td><code>supply</code></td></tr> <tr><td><code>withdraw</code></td></tr> <tr><td><code>claim</code></td></tr> </tbody></table> |
| BNB Native Staking (Legacy) | TokenHub    | 0xaa7415f5 | transferOut |
| Celo Native Staking | <table><tbody>  <tr><td><code>Accounts</code></td></tr> <tr><td><code>LockedGold</code></td></tr> <tr><td><code>LockedGold</code></td></tr> <tr><td><code>LockedGold</code></td></tr> <tr><td><code>Election</code></td></tr> <tr><td><code>Election</code></td></tr> </tbody></table>    | <table><tbody>  <tr><td><code>0x9dca362f</code></td></tr> <tr><td><code>0xf83d08ba</code></td></tr> <tr><td><code>0x6198e339</code></td></tr> <tr><td><code>0x2e1a7d4d</code></td></tr> <tr><td><code>0x580d747a</code></td></tr> <tr><td><code>0x6e198475</code></td></tr> </tbody></table> | <table><tbody>  <tr><td><code>createAccount</code></td></tr> <tr><td><code>lock</code></td></tr> <tr><td><code>unlock</code></td></tr> <tr><td><code>withdraw</code></td></tr> <tr><td><code>vote</code></td></tr> <tr><td><code>revokeActive</code></td></tr> </tbody></table> |
| Aave v3 Lending DAI | <table><tbody>  <tr><td><code>L2Pool</code></td></tr> <tr><td><code>Pool</code></td></tr> </tbody></table> | <table><tbody>  <tr><td><code>0x617ba037</code></td></tr> <tr><td><code>0x69328dec</code></td></tr> </tbody></table> | <table><tbody>  <tr><td><code>supply</code></td></tr> <tr><td><code>withdraw</code></td></tr> </tbody></table> |
| Avalanche Liquid Staking | StakedAvax    | <table><tbody>  <tr><td><code>0x5bcb2fc6</code></td></tr> <tr><td><code>0xc9d2ff9d</code></td></tr> <tr><td><code>0xdb006a75</code></td></tr> <tr><td><code>0xbe040fb0</code></td></tr> <tr><td><code>0x0d10d32c</code></td></tr> <tr><td><code>0x0f7e2048</code></td></tr> </tbody></table> | <table><tbody>  <tr><td><code>submit</code></td></tr> <tr><td><code>requestUnlock</code></td></tr> <tr><td><code>redeem</code></td></tr> <tr><td><code>redeem</code></td></tr> <tr><td><code>redeemOverdueShares</code></td></tr> <tr><td><code>redeemOverdueShares</code></td></tr> </tbody></table> |
| Yearn Vault | Yearn Vault    | <table><tbody>  <tr><td><code>0xd0e30db0</code></td></tr> <tr><td><code>0xb6b55f25</code></td></tr> <tr><td><code>0x6e553f65</code></td></tr> <tr><td><code>0x3ccfd60b</code></td></tr> <tr><td><code>0x2e1a7d4d</code></td></tr> <tr><td><code>0x00f714ce</code></td></tr> </tbody></table> | <table><tbody>  <tr><td><code>deposit</code></td></tr> <tr><td><code>deposit</code></td></tr> <tr><td><code>deposit</code></td></tr> <tr><td><code>withdraw</code></td></tr> <tr><td><code>withdraw</code></td></tr> <tr><td><code>withdraw</code></td></tr> </tbody></table> |
| Angle Protocol | Savings | <table><tbody>  <tr><td><code>0x6e553f65</code></td></tr> <tr><td><code>0xb460af94</code></td></tr>  </tbody></table> | <table><tbody>  <tr><td><code>deposit</code></td></tr><tr><td><code>withdraw</code></td></tr> </tbody></table> |
| Lido stETH Withdrawal NFT | WithdrawalQueueERC721 | <table><tbody>  <tr><td><code>0xd6681042</code></td></tr> <tr><td><code>0xe3afe0a3</code></td></tr>  </tbody></table> | <table><tbody>  <tr><td><code>requestWithdrawals</code></td></tr><tr><td><code>claimWithdrawals</code></td></tr> </tbody></table> |
| VIC Native Staking | TomoValidator | <table><tbody>  <tr><td><code>0x6dd7d8ea</code></td></tr> <tr><td><code>0x02aa9be2</code></td></tr> <tr><td><code>0xae6e43f5</code></td></tr> <tr><td><code>0x441a3e70</code></td></tr>  </tbody></table> | <table><tbody>  <tr><td><code>vote</code></td></tr> <tr><td><code>unvote</code></td></tr> <tr><td><code>resign</code></td></tr> <tr><td><code>withdraw</code></td></tr> </tbody></table> |
| BNB Native Staking | StakeHub | <table><tbody>  <tr><td><code>0xaad3ec96</code></td></tr> <tr><td><code>0x982ef0a7</code></td></tr> <tr><td><code>0x4d99dd16</code></td></tr> <tr><td><code>0x59491871</code></td></tr>  </tbody></table> | <table><tbody>  <tr><td><code>claim</code></td></tr> <tr><td><code>delegate</code></td></tr> <tr><td><code>undelegate</code></td></tr> <tr><td><code>redelegate</code></td></tr> </tbody></table> |

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
