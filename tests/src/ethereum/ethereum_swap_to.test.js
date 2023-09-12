import { processTest, populateTransaction } from "../test.fixture";

const contractName = "RocketSwapRouter";  // <= Name of the smart contract

const testLabel = "ethereum_swap_to"; // <= Name of the test
const testDirSuffix = "ethereum_swap_to"; // <= directory to compare device snapshots to
const testNetwork = "ethereum";
const signedPlugin = false;

const contractAddr = "0x16d5a408e807db8ef7c578279beeee6b228f1c1c";   // <= Address of the smart contract
const chainID = 1;

// From : https://etherscan.io/tx/0xd230d0a8d49f5209bf137a933377e847dbf310fa03a829dbd079184a81299a9a
const inputData = "0x55362f4d0000000000000000000000000000000000000000000000000000000000000009000000000000000000000000000000000000000000000000000000000000000100000000000000000000000000000000000000000000000fd541a17f678f665c00000000000000000000000000000000000000000000000ffe32c754bb5a8b99";

// Create serializedTx and remove the "0x" prefix
const serializedTx = populateTransaction(contractAddr, inputData, chainID);

const devices = [
    {
        name: "nanos",
        label: "Nano S",
        steps: 6, // <= Define the number of steps for this test case and this device
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
