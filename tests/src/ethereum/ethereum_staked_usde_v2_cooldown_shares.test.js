import { processTest, populateTransaction } from "../test.fixture";

const contractName = "StakedUSDeV2";  // <= Name of the smart contract

const testLabel = "ethereum_staked_usde_v2_cooldown_shares"; // <= Name of the test
const testDirSuffix = "ethereum_staked_usde_v2_cooldown_shares"; // <= directory to compare device snapshots to
const testNetwork = "ethereum";
const signedPlugin = false;

const contractAddr = "0x9d39a5de30e57443bff2a8307a4256c8797a3497";   // <= Address of the smart contract
const chainID = 1;

// From : https://etherscan.io/tx/0x521e77f56fbd3d080f78c6d1a41e9d02e7c6d70d4303b1af3279a1d97908fc0f
const inputData = "0x9343d9e10000000000000000000000000000000000000000000005f88a4d309f42a6e1ac";

// Create serializedTx and remove the "0x" prefix
const serializedTx = populateTransaction(contractAddr, inputData, chainID);

const devices = [
    {
        name: "nanox",
        label: "Nano X",
        steps: 3, // <= Define the number of steps for this test case and this device
    },
    {
        name: "nanosp",
        label: "Nano S+",
        steps: 3, // <= Define the number of steps for this test case and this device
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
