import { processTest, populateTransaction } from "../test.fixture";

const contractName = "StakedUSDeV2";  // <= Name of the smart contract

const testLabel = "ethereum_staked_usde_v2_unstake"; // <= Name of the test
const testDirSuffix = "ethereum_staked_usde_v2_unstake"; // <= directory to compare device snapshots to
const testNetwork = "ethereum";
const signedPlugin = false;

const contractAddr = "0x9d39a5de30e57443bff2a8307a4256c8797a3497";   // <= Address of the smart contract
const chainID = 1;

// From : https://etherscan.io/tx/0x8a397638f8743748d4be40c9a7878405f4170b58dad7113bb597a6371e47f5bd
const inputData = "0xf2888dbb0000000000000000000000000299f346d41eaf36254195f15b3771517e649e0c";

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
