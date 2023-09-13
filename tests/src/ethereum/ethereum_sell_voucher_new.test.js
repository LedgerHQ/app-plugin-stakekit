import { processTest, populateTransaction } from "../test.fixture";

const contractName = "ValidatorShareProxy";  // <= Name of the smart contract

const testLabel = "ethereum_sell_voucher_new"; // <= Name of the test
const testDirSuffix = "ethereum_sell_voucher_new"; // <= directory to compare device snapshots to
const testNetwork = "ethereum";
const signedPlugin = false;

const contractAddr = "0x857679d69fe50e7b722f94acd2629d80c355163d";   // <= Address of the smart contract
const chainID = 1;

// From : https://etherscan.io/tx/0xc8a571d90172d3bc2f17afa756c3a392230048eece3f33b65c2c813ac5e0cc8b
const inputData = "0xc83ec04d000000000000000000000000000000000000000000002dab46fe26b415db6c7c000000000000000000000000000000000000000000002dab46fe26b415db6c7c";

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
