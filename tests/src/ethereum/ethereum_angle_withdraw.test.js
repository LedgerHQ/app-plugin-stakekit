import { processTest, populateTransaction } from "../test.fixture";

const contractName = "TransparentUpgradeableProxy";  // <= Name of the smart contract

const testLabel = "ethereum_angle_withdraw"; // <= Name of the test
const testDirSuffix = "ethereum_angle_withdraw"; // <= directory to compare device snapshots to
const testNetwork = "ethereum";
const signedPlugin = false;

const contractAddr = "0x004626a008b1acdc4c74ab51644093b155e59a23";   // <= Address of the smart contract
const chainID = 1;

// From : https://etherscan.io/tx/0x3138aa710234da85b449405d0f9f98eab204332ce76cd8a4421ddcebd64ba73b
const inputData = "0xb460af94000000000000000000000000000000000000000000000000016345785d8a0000000000000000000000000000b6c5273e79e2add234ebc07d87f3824e0f94b2f7000000000000000000000000b6c5273e79e2add234ebc07d87f3824e0f94b2f7";

// Create serializedTx and remove the "0x" prefix
const serializedTx = populateTransaction(contractAddr, inputData, chainID);

const devices = [
    {
        name: "nanos",
        label: "Nano S",
        steps: 10, // <= Define the number of steps for this test case and this device
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
