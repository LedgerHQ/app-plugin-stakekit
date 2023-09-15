import { processTest, populateTransaction } from "../test.fixture";

const contractName = "LockedGoldProxy";  // <= Name of the smart contract

const testLabel = "celo_lock"; // <= Name of the test
const testDirSuffix = "celo_lock"; // <= directory to compare device snapshots to
const testNetwork = "celo";
const signedPlugin = false;

const contractAddr = "0x6cc083aed9e3ebe302a6336dbc7c921c9f03349e";   // <= Address of the smart contract
const chainID = 42220;

// From : https://celoscan.io/tx/0x574de296735989d67b0f29be428b093a4f78a3c0e012404497326497ee43fda3
const inputData = "0xf83d08ba";

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
