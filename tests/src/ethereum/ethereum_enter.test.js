import { processTest, populateTransaction } from "../test.fixture";

const contractName = "SushiBar";  // <= Name of the smart contract

const testLabel = "ethereum_enter"; // <= Name of the test
const testDirSuffix = "ethereum_enter"; // <= directory to compare device snapshots to
const testNetwork = "ethereum";
const signedPlugin = false;

const contractAddr = "0x8798249c2e607446efb7ad49ec89dd1865ff4272";   // <= Address of the smart contract
const chainID = 1;

// From : https://etherscan.io/tx/0x3cf9256bdc5a3936a3051564a1355e078ff4defcaa00f8e7bf6d9b4e3e9dad29
const inputData = "0xa59f3e0c0000000000000000000000000000000000000000000002ad1e143315b2ae3800";

// Create serializedTx and remove the "0x" prefix
const serializedTx = populateTransaction(contractAddr, inputData, chainID);

const devices = [
    {
        name: "nanos",
        label: "Nano S",
        steps: 5, // <= Define the number of steps for this test case and this device
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
