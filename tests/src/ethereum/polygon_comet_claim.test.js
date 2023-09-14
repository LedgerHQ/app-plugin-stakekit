import { processTest, populateTransaction } from "../test.fixture";

const contractName = "CometRewards";  // <= Name of the smart contract

const testLabel = "polygon_comet_claim"; // <= Name of the test
const testDirSuffix = "polygon_comet_claim"; // <= directory to compare device snapshots to
const testNetwork = "polygon";
const signedPlugin = false;

const contractAddr = "0x45939657d1ca34a8fa39a924b71d28fe8431e581";   // <= Address of the smart contract
const chainID = 137;

// From : https://polygonscan.com/tx/0x9c6f8b5f875ba19eef318413b5a0a635d48f1d37f12973513b8523f1a4355ba8
const inputData = "0xb7034f7e000000000000000000000000f25212e676d1f7f89cd72ffee66158f541246445000000000000000000000000a2b78902eb7894ad2d16ed6b242f6a19a9ad13e40000000000000000000000000000000000000000000000000000000000000001";

// Create serializedTx and remove the "0x" prefix
const serializedTx = populateTransaction(contractAddr, inputData, chainID);

const devices = [
    {
        name: "nanos",
        label: "Nano S",
        steps: 10, // <= Define the number of steps for this test case and this device
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
    }
];

devices.forEach((device) =>
    processTest(device, contractName, testLabel, testDirSuffix, "", signedPlugin, serializedTx, testNetwork)
);
