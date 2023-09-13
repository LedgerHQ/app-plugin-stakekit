import { processTest, populateTransaction } from "../test.fixture";

const contractName = "ValidatorShareProxy";  // <= Name of the smart contract

const testLabel = "ethereum_buy_voucher"; // <= Name of the test
const testDirSuffix = "ethereum_buy_voucher"; // <= directory to compare device snapshots to
const testNetwork = "ethereum";
const signedPlugin = false;

const contractAddr = "0x857679d69fe50e7b722f94acd2629d80c355163d";   // <= Address of the smart contract
const chainID = 1;

// From : https://etherscan.io/tx/0xa62c3d54e5886da76268dcf4574c64ea06f1137312fc6e38c769e9b9fcb977b2
const inputData = "0x6ab1507100000000000000000000000000000000000000000000007685fa9b1d82cd00000000000000000000000000000000000000000000000000000000000000000977";

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
