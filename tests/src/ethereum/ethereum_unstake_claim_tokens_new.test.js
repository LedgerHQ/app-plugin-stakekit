import { processTest, populateTransaction } from "../test.fixture";

const contractName = "ValidatorShareProxy";  // <= Name of the smart contract

const testLabel = "ethereum_unstake_claim_tokens_new"; // <= Name of the test
const testDirSuffix = "ethereum_unstake_claim_tokens_new"; // <= directory to compare device snapshots to
const testNetwork = "ethereum";
const signedPlugin = false;

const contractAddr = "0x857679d69fe50e7b722f94acd2629d80c355163d";   // <= Address of the smart contract
const chainID = 1;

// From : https://etherscan.io/tx/0xe39b1f42e6848e98089a7cd7cfd5e77d230ac402c4931232c4be258e592131df
const inputData = "0xe97fddc20000000000000000000000000000000000000000000000000000000000000001";

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
