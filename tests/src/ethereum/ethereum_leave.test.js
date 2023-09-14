import { processTest, populateTransaction } from "../test.fixture";

const contractName = "SushiBar";  // <= Name of the smart contract

const testLabel = "ethereum_leave"; // <= Name of the test
const testDirSuffix = "ethereum_leave"; // <= directory to compare device snapshots to
const testNetwork = "ethereum";
const signedPlugin = false;

const contractAddr = "0x8798249c2e607446efb7ad49ec89dd1865ff4272";   // <= Address of the smart contract
const chainID = 1;

// From : https://etherscan.io/tx/0x8026512b4e22c65489f657ad082b1726fda60e6603f7b477945b82a2abf0e734
const inputData = "0x67dfd4c90000000000000000000000000000000000000000000001f9f6e37b8216617c12";

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
