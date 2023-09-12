import { processTest, populateTransaction } from "../test.fixture";

const contractName = "ApeCoinStaking";  // <= Name of the smart contract

const testLabel = "ethereum_deposit_self_apecoin"; // <= Name of the test
const testDirSuffix = "ethereum_deposit_self_apecoin"; // <= directory to compare device snapshots to
const testNetwork = "ethereum";
const signedPlugin = false;

const contractAddr = "0x5954ab967bc958940b7eb73ee84797dc8a2afbb9";   // <= Address of the smart contract
const chainID = 1;

// From : https://etherscan.io/tx/0xff61484a13af6e5e102448530590102df50cfa6b01b4acdf1d4c488f7acf2816
const inputData = "0x9dcaafb400000000000000000000000000000000000000000000000292813354903b676e";

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
