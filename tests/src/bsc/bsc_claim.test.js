import { processTest, populateTransaction } from "../test.fixture";

const contractName = "StakeHub";  // <= Name of the smart contract

const testLabel = "bsc_claim"; // <= Name of the test
const testDirSuffix = "bsc_claim"; // <= directory to compare device snapshots to
const testNetwork = "bsc";
const signedPlugin = false;

const contractAddr = "0x0000000000000000000000000000000000002002";   // <= Address of the smart contract
const chainID = 56;

// From : https://bscscan.com/tx/0x7be3829b21952e8ffd580bda2edb5ad48179e9e568cb71c3da06a52ae4c7f022
const inputData = "0xaad3ec960000000000000000000000000e3cf208f4141c41da86d52c5f2076b1ab310e8f0000000000000000000000000000000000000000000000000000000000000000";

// Create serializedTx and remove the "0x" prefix
const serializedTx = populateTransaction(contractAddr, inputData, chainID);

const devices = [
    {
        name: "nanos",
        label: "Nano S",
        steps: 8, // <= Define the number of steps for this test case and this device
    },
    {
        name: "nanox",
        label: "Nano X",
        steps: 6, // <= Define the number of steps for this test case and this device
    },
    {
        name: "nanosp",
        label: "Nano S+",
        steps: 6, // <= Define the number of steps for this test case and this device
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
