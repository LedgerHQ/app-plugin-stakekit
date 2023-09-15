import { processTest, populateTransaction } from "../test.fixture";

const contractName = "AccountsProxy";  // <= Name of the smart contract

const testLabel = "celo_create_account"; // <= Name of the test
const testDirSuffix = "celo_create_account"; // <= directory to compare device snapshots to
const testNetwork = "celo";
const signedPlugin = false;

const contractAddr = "0x7d21685c17607338b313a7174bab6620bad0aab7";   // <= Address of the smart contract
const chainID = 42220;

// From : https://celoscan.io/tx/0xadfff542b0b52749d3c4e8b06f8c4834060668e58b56b8b51410e7ea4948b935
const inputData = "0x9dca362f";

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
