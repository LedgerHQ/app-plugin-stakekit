import { processTest, populateTransaction } from "../test.fixture";

const contractName = "GraphProxy";  // <= Name of the smart contract

const testLabel = "ethereum_grt_withdraw_delegated"; // <= Name of the test
const testDirSuffix = "ethereum_grt_withdraw_delegated"; // <= directory to compare device snapshots to
const testNetwork = "ethereum";
const signedPlugin = false;

const contractAddr = "0xf55041e37e12cd407ad00ce2910b8269b01263b9";   // <= Address of the smart contract
const chainID = 1;

// From : https://etherscan.io/tx/0x02d7c932581fa59411b57d98f60e21b198d90cac14beb4ac84e6d82bdb0c9a04
const inputData = "0x51a60b0200000000000000000000000063c560997b8338f2b033f3ffdcc0f7c680feec450000000000000000000000000000000000000000000000000000000000000000";

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
