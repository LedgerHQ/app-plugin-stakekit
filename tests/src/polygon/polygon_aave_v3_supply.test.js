import { processTest, populateTransaction } from "../test.fixture";

const contractName = "InitializableImmutableAdminUpgradeabilityProxy";  // <= Name of the smart contract

const testLabel = "polygon_aave_v3_supply"; // <= Name of the test
const testDirSuffix = "polygon_aave_v3_supply"; // <= directory to compare device snapshots to
const testNetwork = "polygon";
const signedPlugin = false;

const contractAddr = "0x794a61358d6845594f94dc1db02a252b5b4814ad";   // <= Address of the smart contract
const chainID = 137;

// From : https://polygonscan.com/tx/0x51fca72ececf92b6f7998277ac3617a27992b0e241f81e97ad7069250d9b036d
const inputData = "0x617ba0370000000000000000000000000b3f868e0be5597d5db7feb59e1cadbb0fdda50a0000000000000000000000000000000000000000000000470a6726d08a75d506000000000000000000000000dd2926ee0f01203cfa956d11425ef70a49bcfe3f0000000000000000000000000000000000000000000000000000000000000000";

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
