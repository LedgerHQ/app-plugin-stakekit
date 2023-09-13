import { processTest, populateTransaction } from "../test.fixture";

const contractName = "TransparentUpgradeableProxy";  // <= Name of the smart contract

const testLabel = "ethereum_submit_matic_lido"; // <= Name of the test
const testDirSuffix = "ethereum_submit_matic_lido"; // <= directory to compare device snapshots to
const testNetwork = "ethereum";
const signedPlugin = false;

const contractAddr = "0x9ee91f9f426fa633d227f7a9b000e28b9dfd8599";   // <= Address of the smart contract
const chainID = 1;

// From : https://etherscan.io/tx/0xd9ac578663440f30b27b01551e7bdfa55d30a06b95af786a7f8a84565c0f56af
const inputData = "0xf532e86a00000000000000000000000000000000000000000000000a7f91dc75ca604400000000000000000000000000231488f58d7ec8767b40e06069de263d27e95ef4";

// Create serializedTx and remove the "0x" prefix
const serializedTx = populateTransaction(contractAddr, inputData, chainID);

const devices = [
    {
        name: "nanos",
        label: "Nano S",
        steps: 7, // <= Define the number of steps for this test case and this device
    },
    {
        name: "nanox",
        label: "Nano X",
        steps: 5, // <= Define the number of steps for this test case and this device
    },
    {
        name: "nanosp",
        label: "Nano S+",
        steps: 5, // <= Define the number of steps for this test case and this device
    }
];

devices.forEach((device) =>
    processTest(device, contractName, testLabel, testDirSuffix, "", signedPlugin, serializedTx, testNetwork)
);
