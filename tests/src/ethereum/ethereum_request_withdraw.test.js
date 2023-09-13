import { processTest, populateTransaction } from "../test.fixture";

const contractName = "TransparentUpgradeableProxy";  // <= Name of the smart contract

const testLabel = "ethereum_request_withdraw"; // <= Name of the test
const testDirSuffix = "ethereum_request_withdraw"; // <= directory to compare device snapshots to
const testNetwork = "ethereum";
const signedPlugin = false;

const contractAddr = "0x9ee91f9f426fa633d227f7a9b000e28b9dfd8599";   // <= Address of the smart contract
const chainID = 1;

// From : https://etherscan.io/tx/0xeb2deb767946ff0575ecd1dcf388206aee098aa1465ea1bd803cad644bc69bf1
const inputData = "0xccc143b8000000000000000000000000000000000000000000000017b589a84da2eb51440000000000000000000000000000000000000000000000000000000000000000";

// Create serializedTx and remove the "0x" prefix
const serializedTx = populateTransaction(contractAddr, inputData, chainID);

const devices = [
    {
        name: "nanos",
        label: "Nano S",
        steps: 9, // <= Define the number of steps for this test case and this device
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
