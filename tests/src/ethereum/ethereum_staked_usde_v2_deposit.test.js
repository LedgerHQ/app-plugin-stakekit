import { processTest, populateTransaction } from "../test.fixture";

const contractName = "StakedUSDeV2";  // <= Name of the smart contract

const testLabel = "ethereum_staked_usde_v2_deposit"; // <= Name of the test
const testDirSuffix = "ethereum_staked_usde_v2_deposit"; // <= directory to compare device snapshots to
const testNetwork = "ethereum";
const signedPlugin = false;

const contractAddr = "0x9d39a5de30e57443bff2a8307a4256c8797a3497";   // <= Address of the smart contract
const chainID = 1;

// From : https://etherscan.io/tx/0x91fd9a41239ed1d6857d807210d692c40393b98f9ad0f7f3d1a0de15db57f967
const inputData = "0x6e553f650000000000000000000000000000000000000000000000000de0b6b3a76400000000000000000000000000009237c8bd06930bd336b03adeffe2b6ef30363774";

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
