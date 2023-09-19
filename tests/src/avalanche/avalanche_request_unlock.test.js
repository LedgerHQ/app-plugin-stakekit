import { processTest, populateTransaction } from "../test.fixture";

const contractName = "TransparentUpgradeableProxy";  // <= Name of the smart contract

const testLabel = "avalanche_request_unlock"; // <= Name of the test
const testDirSuffix = "avalanche_request_unlock"; // <= directory to compare device snapshots to
const testNetwork = "avalanche";
const signedPlugin = false;

const contractAddr = "0x2b2c81e08f1af8835a78bb2a90ae924ace0ea4be";   // <= Address of the smart contract
const chainID = 43114;

// From : https://snowtrace.io/tx/0xf34e9a2c54caa7897702a973f9a3570634007936158b94b5b1c30db0346be59c
const inputData = "0xc9d2ff9d000000000000000000000000000000000000000000000000093989dc9b047639";

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
