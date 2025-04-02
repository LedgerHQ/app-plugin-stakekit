import { processTest, populateTransaction } from "../test.fixture";

const contractName = "TransparentUpgradeableProxy";  // <= Name of the smart contract

const testLabel = "arbitrum_angle_withdraw"; // <= Name of the test
const testDirSuffix = "arbitrum_angle_withdraw"; // <= directory to compare device snapshots to
const testNetwork = "arbitrum";
const signedPlugin = false;

const contractAddr = "0x004626a008b1acdc4c74ab51644093b155e59a23";   // <= Address of the smart contract
const chainID = 42161;

// From : https://arbiscan.io/tx/0x9f7cfc79d3c2b83e40c8c16240aea03430dadbed3d4cfa683b49b7f1669e9952
const inputData = "0xb460af9400000000000000000000000000000000000000000000000002c68af0bb140000000000000000000000000000b6c5273e79e2add234ebc07d87f3824e0f94b2f7000000000000000000000000b6c5273e79e2add234ebc07d87f3824e0f94b2f7";

// Create serializedTx and remove the "0x" prefix
const serializedTx = populateTransaction(contractAddr, inputData, chainID);

const devices = [
    {
        name: "nanos",
        label: "Nano S",
        steps: 11, // <= Define the number of steps for this test case and this device
    },
    {
        name: "nanox",
        label: "Nano X",
        steps: 7, // <= Define the number of steps for this test case and this device
    },
    {
        name: "nanosp",
        label: "Nano S+",
        steps: 7, // <= Define the number of steps for this test case and this device
    }
];

devices.forEach((device) =>
    processTest(device, contractName, testLabel, testDirSuffix, "", signedPlugin, serializedTx, testNetwork)
);
