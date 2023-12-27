import { processTest, populateTransaction } from "../test.fixture";

const contractName = "TransparentUpgradeableProxy";  // <= Name of the smart contract

const testLabel = "arbitrum_angle_deposit"; // <= Name of the test
const testDirSuffix = "arbitrum_angle_deposit"; // <= directory to compare device snapshots to
const testNetwork = "arbitrum";
const signedPlugin = false;

const contractAddr = "0x004626a008b1acdc4c74ab51644093b155e59a23";   // <= Address of the smart contract
const chainID = 42161;

// From : https://arbiscan.io/tx/0xdccdf29e8cbea34fc2435ffe58cca33453c0cc7329303a1c4ee73273a8bd15f1
const inputData = "0x6e553f650000000000000000000000000000000000000000000000000de0b6b3a7640000000000000000000000000000b6c5273e79e2add234ebc07d87f3824e0f94b2f7";

// Create serializedTx and remove the "0x" prefix
const serializedTx = populateTransaction(contractAddr, inputData, chainID);

const devices = [
    {
        name: "nanos",
        label: "Nano S",
        steps: 8, // <= Define the number of steps for this test case and this device
    },
    {
        name: "nanox",
        label: "Nano X",
        steps: 6, // <= Define the number of steps for this test case and this device
    },
    {
        name: "nanosp",
        label: "Nano S+",
        steps: 6, // <= Define the number of steps for this test case and this device
    }
];

devices.forEach((device) =>
    processTest(device, contractName, testLabel, testDirSuffix, "", signedPlugin, serializedTx, testNetwork)
);
