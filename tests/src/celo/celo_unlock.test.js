import { processTest, populateTransaction } from "../test.fixture";

const contractName = "LockedGoldProxy";  // <= Name of the smart contract

const testLabel = "celo_unlock"; // <= Name of the test
const testDirSuffix = "celo_unlock"; // <= directory to compare device snapshots to
const testNetwork = "celo";
const signedPlugin = false;

const contractAddr = "0x6cc083aed9e3ebe302a6336dbc7c921c9f03349e";   // <= Address of the smart contract
const chainID = 42220;

// From : https://celoscan.io/tx/0x7d106db34a99c5e7b47386e97e774c8b834888d1f59e8d0f36e5fcf3c4f0460e
const inputData = "0x6198e339000000000000000000000000000000000000000000000009e55f088b3431adcd";

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
