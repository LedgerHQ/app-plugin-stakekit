import { processTest, populateTransaction } from "../test.fixture";

const contractName = "TransparentUpgradeableProxy";  // <= Name of the smart contract

const testLabel = "ethereum_claim_tokens"; // <= Name of the test
const testDirSuffix = "ethereum_claim_tokens"; // <= directory to compare device snapshots to
const testNetwork = "ethereum";
const signedPlugin = false;

const contractAddr = "0x9ee91f9f426fa633d227f7a9b000e28b9dfd8599";   // <= Address of the smart contract
const chainID = 1;

// From : https://etherscan.io/tx/0xf3ad5d16bbf994af6ac989f551c2d6d1f496a7c250523a78b7f9dbeb34d9974c
const inputData = "0x46e04a2f00000000000000000000000000000000000000000000000000000000000006a3";

// Create serializedTx and remove the "0x" prefix
const serializedTx = populateTransaction(contractAddr, inputData, chainID);

const devices = [
    {
        name: "nanos",
        label: "Nano S",
        steps: 4, // <= Define the number of steps for this test case and this device
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
