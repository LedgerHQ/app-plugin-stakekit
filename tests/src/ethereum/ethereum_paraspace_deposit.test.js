import { processTest, populateTransaction } from "../test.fixture";

const contractName = "InitializableAdminUpgradeabilityProxy";  // <= Name of the smart contract

const testLabel = "ethereum_paraspace_deposit"; // <= Name of the test
const testDirSuffix = "ethereum_paraspace_deposit"; // <= directory to compare device snapshots to
const testNetwork = "ethereum";
const signedPlugin = false;

const contractAddr = "0xc5c9fb6223a989208df27dcee33fc59ff5c26fff";   // <= Address of the smart contract
const chainID = 1;

// From : https://etherscan.io/tx/0x43112003c4be7e813240cc7f395640b1778907081063cec93a40101a00c342f9
const inputData = "0x47e7ef2400000000000000000000000001b007e74987ace65c44eaf311c5e8cad3ea54410000000000000000000000000000000000000000000000000de0b6b3a7640000";

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
