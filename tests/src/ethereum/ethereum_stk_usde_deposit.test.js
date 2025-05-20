import { processTest, populateTransaction } from "../test.fixture";

const contractName = "TransparentUpgradeableProxy";  // <= Name of the smart contract

const testLabel = "ethereum_stk_usde_deposit"; // <= Name of the test
const testDirSuffix = "ethereum_stk_usde_deposit"; // <= directory to compare device snapshots to
const testNetwork = "ethereum";
const signedPlugin = false;

const contractAddr = "0x4e6189f16a348e6233a33317c6480f2fd4fc7870";   // <= Address of the smart contract
const chainID = 1;

// From : https://etherscan.io/tx/0x3da8bd4b8bdda4cbc257e05fd70d5ece2e8e95bcf10991e6994ef793d5f0c034
const inputData = "0x6e553f650000000000000000000000000000000000000000000000000de0b6b3a76400000000000000000000000000006877bb79f680216bbdf01704939037f22193e771";

// Create serializedTx and remove the "0x" prefix
const serializedTx = populateTransaction(contractAddr, inputData, chainID);

const devices = [
    {
        name: "nanox",
        label: "Nano X",
        steps: 4, // <= Define the number of steps for this test case and this device
    },
    {
        name: "nanosp",
        label: "Nano S+",
        steps: 4, // <= Define the number of steps for this test case and this device
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
