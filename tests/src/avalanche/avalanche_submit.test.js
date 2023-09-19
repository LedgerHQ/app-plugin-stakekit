import { processTest, populateTransaction } from "../test.fixture";

const contractName = "TransparentUpgradeableProxy";  // <= Name of the smart contract

const testLabel = "avalanche_submit"; // <= Name of the test
const testDirSuffix = "avalanche_submit"; // <= directory to compare device snapshots to
const testNetwork = "avalanche";
const signedPlugin = false;

const contractAddr = "0x2b2c81e08f1af8835a78bb2a90ae924ace0ea4be";   // <= Address of the smart contract
const chainID = 43114;

// From : https://snowtrace.io/tx/0x969733fd8afafba24173de5b92ec6b83109b90d71486d7c3a3bfb999b49d9ec6
const inputData = "0x5bcb2fc6";

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
