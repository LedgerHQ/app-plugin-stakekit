import { processTest, populateTransaction } from "../test.fixture";

const contractName = "ValidatorShareProxy";  // <= Name of the smart contract

const testLabel = "ethereum_unstake_claim_tokens_new_pol"; // <= Name of the test
const testDirSuffix = "ethereum_unstake_claim_tokens_new_pol"; // <= directory to compare device snapshots to
const testNetwork = "ethereum";
const signedPlugin = false;

const contractAddr = "0xa6e768fef2d1af36c0cfdb276422e7881a83e951";   // <= Address of the smart contract
const chainID = 1;

// From : https://etherscan.io/tx/0x7489996630431eedd1da777cf4e2c2aa822ac9f6d6b1cfc7e3a91b4c5a5d07b0
const inputData = "0x8759c2340000000000000000000000000000000000000000000000000000000000000001";

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
