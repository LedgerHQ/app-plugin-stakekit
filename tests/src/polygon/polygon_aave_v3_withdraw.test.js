import { processTest, populateTransaction } from "../test.fixture";

const contractName = "InitializableImmutableAdminUpgradeabilityProxy";  // <= Name of the smart contract

const testLabel = "polygon_aave_v3_withdraw"; // <= Name of the test
const testDirSuffix = "polygon_aave_v3_withdraw"; // <= directory to compare device snapshots to
const testNetwork = "polygon";
const signedPlugin = false;

const contractAddr = "0x794a61358d6845594f94dc1db02a252b5b4814ad";   // <= Address of the smart contract
const chainID = 137;

// From : https://polygonscan.com/tx/0x40545433641505b25f110f98771abfe99c0422cf824fabf1ba46e2070c8cc22c
const inputData = "0x69328dec000000000000000000000000e111178a87a3bff0c8d18decba5798827539ae9900000000000000000000000000000000000000000000000000000000009896800000000000000000000000008da35b920fe236a757a0fad93d3a3ab8ea0a24cc";

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
