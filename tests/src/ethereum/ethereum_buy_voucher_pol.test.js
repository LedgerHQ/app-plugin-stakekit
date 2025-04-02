import { processTest, populateTransaction } from "../test.fixture";

const contractName = "ValidatorShareProxy";  // <= Name of the smart contract

const testLabel = "ethereum_buy_voucher_pol"; // <= Name of the test
const testDirSuffix = "ethereum_buy_voucher_pol"; // <= directory to compare device snapshots to
const testNetwork = "ethereum";
const signedPlugin = false;

const contractAddr = "0x06998af8f39ff8630d1fb515d22781da4dc2ca71";   // <= Address of the smart contract
const chainID = 1;

// From : https://etherscan.io/tx/0x5c99588f563b6492624322cad17701ae613725bf9d13fc6c60e4a7abd6d93c0a
const inputData = "0xe4457a8a0000000000000000000000000000000000000000000017b28c969594bc1800000000000000000000000000000000000000000000000000000000000000000000";

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
