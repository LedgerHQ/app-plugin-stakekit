import { processTest, populateTransaction } from "../test.fixture";

const contractName = "StakedUSDeV2";  // <= Name of the smart contract

const testLabel = "ethereum_staked_usde_v2_cooldown_assets"; // <= Name of the test
const testDirSuffix = "ethereum_staked_usde_v2_cooldown_assets"; // <= directory to compare device snapshots to
const testNetwork = "ethereum";
const signedPlugin = false;

const contractAddr = "0x9d39a5de30e57443bff2a8307a4256c8797a3497";   // <= Address of the smart contract
const chainID = 1;

// From : https://etherscan.io/tx/0xd46b596ec7628dcdc249dca6759645470c772f30269fc27cfe567012d7f5c25e
const inputData = "0xcdac52ed00000000000000000000000000000000000000000000000101af0be4d0788e5f";

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
