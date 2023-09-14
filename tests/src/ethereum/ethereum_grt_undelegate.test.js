import { processTest, populateTransaction } from "../test.fixture";

const contractName = "GraphProxy";  // <= Name of the smart contract

const testLabel = "ethereum_grt_undelegate"; // <= Name of the test
const testDirSuffix = "ethereum_grt_undelegate"; // <= directory to compare device snapshots to
const testNetwork = "ethereum";
const signedPlugin = false;

const contractAddr = "0xf55041e37e12cd407ad00ce2910b8269b01263b9";   // <= Address of the smart contract
const chainID = 1;

// From : https://etherscan.io/tx/0x3b6d369660ca770847a7d0c4fb2a8c67c9bcf2429d8492ea12f2b8220a95d17f
const inputData = "0x4d99dd1600000000000000000000000063c560997b8338f2b033f3ffdcc0f7c680feec450000000000000000000000000000000000000000000069e10de76676d0800000";

// Create serializedTx and remove the "0x" prefix
const serializedTx = populateTransaction(contractAddr, inputData, chainID);

const devices = [
    {
        name: "nanos",
        label: "Nano S",
        steps: 6, // <= Define the number of steps for this test case and this device
    },
    {
        name: "nanox",
        label: "Nano X",
        steps: 4, // <= Define the number of steps for this test case and this device
    },
    {
        name: "nanosp",
        label: "Nano S+",
        steps: 4, // <= Define the number of steps for this test case and this device
    }
];

devices.forEach((device) =>
    processTest(device, contractName, testLabel, testDirSuffix, "", signedPlugin, serializedTx, testNetwork)
);
