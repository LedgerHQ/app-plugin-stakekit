import { processTest, populateTransaction } from "../test.fixture";

const contractName = "TransparentUpgradeableProxy";  // <= Name of the smart contract

const testLabel = "ethereum_stk_usde_redeem"; // <= Name of the test
const testDirSuffix = "ethereum_stk_usde_redeem"; // <= directory to compare device snapshots to
const testNetwork = "ethereum";
const signedPlugin = false;

const contractAddr = "0x4e6189f16a348e6233a33317c6480f2fd4fc7870";   // <= Address of the smart contract
const chainID = 1;

// From : https://etherscan.io/tx/0xcde2a49a706c521f8851c5bcad87f17ea322ffad28b2a178f16db95542d8c052
const inputData = "0xba08765200000000000000000000000000000000000000000000ace95bf8a46d33e4f2c00000000000000000000000006877bb79f680216bbdf01704939037f22193e7710000000000000000000000006877bb79f680216bbdf01704939037f22193e771";

// Create serializedTx and remove the "0x" prefix
const serializedTx = populateTransaction(contractAddr, inputData, chainID);

const devices = [
    {
        name: "nanox",
        label: "Nano X",
        steps: 5, // <= Define the number of steps for this test case and this device
    },
    {
        name: "nanosp",
        label: "Nano S+",
        steps: 5, // <= Define the number of steps for this test case and this device
    },
    {
        name: "stax",
        label: "Stax",
    },
    {
        name: "flex",
        label: "Flex",
    }
];

devices.forEach((device) =>
    processTest(device, contractName, testLabel, testDirSuffix, "", signedPlugin, serializedTx, testNetwork)
);
