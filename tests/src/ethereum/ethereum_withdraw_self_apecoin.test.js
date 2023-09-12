import { processTest, populateTransaction } from "../test.fixture";

const contractName = "ApeCoinStaking";  // <= Name of the smart contract

const testLabel = "ethereum_withdraw_self_apecoin"; // <= Name of the test
const testDirSuffix = "ethereum_withdraw_self_apecoin"; // <= directory to compare device snapshots to
const testNetwork = "ethereum";
const signedPlugin = false;

const contractAddr = "0x5954ab967bc958940b7eb73ee84797dc8a2afbb9";   // <= Address of the smart contract
const chainID = 1;

// From : https://etherscan.io/tx/0xcf81591d87ec7c200ae5322180718c8a50dc5b34b4ac816c2eb923bc82d47501
const inputData = "0x7f60d3380000000000000000000000000000000000000000000000e062f6c5f2e0ed5115";

// Create serializedTx and remove the "0x" prefix
const serializedTx = populateTransaction(contractAddr, inputData, chainID);

const devices = [
    {
        name: "nanos",
        label: "Nano S",
        steps: 7, // <= Define the number of steps for this test case and this device
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
