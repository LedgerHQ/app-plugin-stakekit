import { processTest, populateTransaction } from "../test.fixture";

const contractName = "StakeHub";  // <= Name of the smart contract

const testLabel = "bsc_delegate"; // <= Name of the test
const testDirSuffix = "bsc_delegate"; // <= directory to compare device snapshots to
const testNetwork = "bsc";
const signedPlugin = false;

const contractAddr = "0x0000000000000000000000000000000000002002";   // <= Address of the smart contract
const chainID = 56;

// From : https://bscscan.com/tx/0x16a08e90b09c97842f2656d1b2bb0f3f65c9d8cbcd1e318d45a89cceaa7c397b
const inputData = "0x982ef0a700000000000000000000000031738238b6a4fcb00ba4de9ee923986b6df55ae60000000000000000000000000000000000000000000000000000000000000000";

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
