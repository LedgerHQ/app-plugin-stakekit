import { processTest, populateTransaction } from "../test.fixture";

const contractName = "ElectionProxy";  // <= Name of the smart contract

const testLabel = "celo_vote"; // <= Name of the test
const testDirSuffix = "celo_vote"; // <= directory to compare device snapshots to
const testNetwork = "celo";
const signedPlugin = false;

const contractAddr = "0x8d6677192144292870907e3fa8a5527fe55a7ff6";   // <= Address of the smart contract
const chainID = 42220;

// From : https://celoscan.io/tx/0x8dd579e2fa04efb063f1444f297646223e31053bafb35ee4b4da33fba09719e0
const inputData = "0x580d747a00000000000000000000000026e6b535a62d2ce81bc84dbfd836548a2fcb31040000000000000000000000000000000000000000000000bc1bec7726ed7800000000000000000000000000006f8e6ff69935f000b09d182a4739342faeaf0c77000000000000000000000000e075ba4b1dcaf75513118d7aa08a057c658842c9";

// Create serializedTx and remove the "0x" prefix
const serializedTx = populateTransaction(contractAddr, inputData, chainID);

const devices = [
    {
        name: "nanos",
        label: "Nano S",
        steps: 14, // <= Define the number of steps for this test case and this device
    },
    {
        name: "nanox",
        label: "Nano X",
        steps: 8, // <= Define the number of steps for this test case and this device
    },
    {
        name: "nanosp",
        label: "Nano S+",
        steps: 8, // <= Define the number of steps for this test case and this device
    }
];

devices.forEach((device) =>
    processTest(device, contractName, testLabel, testDirSuffix, "", signedPlugin, serializedTx, testNetwork)
);
