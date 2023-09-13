import { processTest, populateTransaction } from "../test.fixture";

const contractName = "TransparentUpgradeableProxy";  // <= Name of the smart contract

const testLabel = "ethereum_morpho_supply"; // <= Name of the test
const testNetwork = "ethereum";
const signedPlugin = false;

const contractAddr = "0x777777c9898d384f785ee44acfe945efdff5f3e0";   // <= Address of the smart contract
const chainID = 1;

const transactions = [
    // {
    //     // From : https://etherscan.io/tx/0x238086cd092f6c5e6988baa2839851547d35c952417f1f46e80c0eaad7d73870
    //     inputData: '0x0c0a769b0000000000000000000000009ff58f4ffb29fa2266ab25e75e2a8b3503311656000000000000000000000000721096bcd32a2a653efa5633b9fa1e07359d974600000000000000000000000000000000000000000000000000000000245bdc800000000000000000000000000000000000000000000000000000018a8d2e9f0d000000000000000000000000000000000000000000000000000000000000da44',
    //     nanoStep: 7,
    //     nanoSPtep: 5,
    //     nanoXtep: 5,
    //     index: 1,
    // },
    // {
    //     // From : https://etherscan.io/tx/0x397720ea112b40cb60bd27f2e2fa9509f1bde520d95315a5bf6d3b955c791e3c
    //     inputData: '0xf2b9fdb8000000000000000000000000030ba81f1c18d280636f32af80b9aad02cf0854e0000000000000000000000000000000000000000000000000de0b6b3a7640000',
    //     nanoStep: 4,
    //     nanoSPtep: 4,
    //     nanoXtep: 4,
    //     index: 2,
    // },
    {
        // From : https://etherscan.io/tx/0xa3f4967680be4f3bf0317829f58516c56668ea0f55cceb3017c11848db7dd504
        inputData: '0xf62256c7000000000000000000000000028171bca77440897b824ca71d1c56cac55b68a3000000000000000000000000d625c7458da1a0758da8d3ac7f2c10180bf0e5060000000000000000000000000000000000000000000000000c7d713b49da00000000000000000000000000000000000000000000000000000000000000061a80',
        nanoStep: 7,
        nanoSPtep: 5,
        nanoXtep: 5,
        index: 3,
    },
];

transactions.forEach((tx) => {
    const devices = [
        {
            name: 'nanos',
            label: 'Nano S',
            steps: tx.nanoStep, // <= Define the number of steps for this test case and this device
        },
        {
            name: 'nanox',
            label: 'Nano X',
            steps: tx.nanoSPtep, // <= Define the number of steps for this test case and this device
        },
        {
            name: 'nanosp',
            label: 'Nano S+',
            steps: tx.nanoXtep, // <= Define the number of steps for this test case and this device
        },
    ];

    const testDirSuffix = `${testLabel}_${tx.index}`; // <= directory to compare device snapshots to
    const serializedTx = populateTransaction(contractAddr, tx.inputData, chainID);

    devices.forEach((device) => processTest(device, contractName, testDirSuffix, testDirSuffix, '', signedPlugin, serializedTx, testNetwork));
});
