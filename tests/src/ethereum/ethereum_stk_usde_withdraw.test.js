import { processTest, populateTransaction } from "../test.fixture";

const contractName = "TransparentUpgradeableProxy";  // <= Name of the smart contract

const testLabel = "ethereum_stk_usde_withdraw"; // <= Name of the test
const testDirSuffix = "ethereum_stk_usde_withdraw"; // <= directory to compare device snapshots to
const testNetwork = "ethereum";
const signedPlugin = false;

const contractAddr = "0x4e6189f16a348e6233a33317c6480f2fd4fc7870";   // <= Address of the smart contract
const chainID = 1;

// No example on chain yet
// made up data
const inputData = "0xb460af94000000000000000000000000000000000000000000000000000000746a5288000000000000000000000000000a251df99a88a20a93876205fb7f5faf2e85a4810000000000000000000000000a251df99a88a20a93876205fb7f5faf2e85a481";

// Create serializedTx and remove the "0x" prefix
const serializedTx = populateTransaction(contractAddr, inputData, chainID);

const devices = [
    {
        name: "nanox",
        label: "Nano X",
        steps: 5, // <= Define the number of steps for this test case and this device
    },
    {
        name: "nanosp",
        label: "Nano S+",
        steps: 5, // <= Define the number of steps for this test case and this device
    },
    {
        name: "stax",
        label: "Stax",
    },
    {
        name: "flex",
        label: "Flex",
    }
];

devices.forEach((device) =>
    processTest(device, contractName, testLabel, testDirSuffix, "", signedPlugin, serializedTx, testNetwork)
);
