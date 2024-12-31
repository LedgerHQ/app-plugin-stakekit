import { processTest, populateTransaction } from "../test.fixture";

const contractName = "StakeHub";  // <= Name of the smart contract

const testLabel = "bsc_redelegate"; // <= Name of the test
const testDirSuffix = "bsc_redelegate"; // <= directory to compare device snapshots to
const testNetwork = "bsc";
const signedPlugin = false;

const contractAddr = "0x0000000000000000000000000000000000002002";   // <= Address of the smart contract
const chainID = 56;

// From : https://bscscan.com/tx/0x7e69d623b177ef2b1dc7e4342e05e68104ff63a0cfccc44b4badefcfc07a2b63
const inputData = "0x594918710000000000000000000000009941bce2601fc93478df9f5f6cc83f4ffc1d71d800000000000000000000000031738238b6a4fcb00ba4de9ee923986b6df55ae6000000000000000000000000000000000000000000000000468aa1967d98533d0000000000000000000000000000000000000000000000000000000000000000";

// Create serializedTx and remove the "0x" prefix
const serializedTx = populateTransaction(contractAddr, inputData, chainID);

const devices = [
    {
        name: "nanos",
        label: "Nano S",
        steps: 11, // <= Define the number of steps for this test case and this device
    },
    {
        name: "nanox",
        label: "Nano X",
        steps: 7, // <= Define the number of steps for this test case and this device
    },
    {
        name: "nanosp",
        label: "Nano S+",
        steps: 7, // <= Define the number of steps for this test case and this device
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
