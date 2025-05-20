import { processTest, populateTransaction } from "../test.fixture";

const contractName = "StakedUSDeV2";  // <= Name of the smart contract

const testLabel = "ethereum_staked_usde_v2_withdraw"; // <= Name of the test
const testDirSuffix = "ethereum_staked_usde_v2_withdraw"; // <= directory to compare device snapshots to
const testNetwork = "ethereum";
const signedPlugin = false;

const contractAddr = "0x9d39a5de30e57443bff2a8307a4256c8797a3497";   // <= Address of the smart contract
const chainID = 1;

// From : https://etherscan.io/tx/0x995d780b9768d3d4f8ef9b937c33dda4352d964f7a14b5c3f553475ecf701fd7
const inputData = "0xb460af94000000000000000000000000000000000000000000000000000000746a5288000000000000000000000000000a251df99a88a20a93876205fb7f5faf2e85a4810000000000000000000000000a251df99a88a20a93876205fb7f5faf2e85a481";

// Create serializedTx and remove the "0x" prefix
const serializedTx = populateTransaction(contractAddr, inputData, chainID);

const devices = [
    {
        name: "nanox",
        label: "Nano X",
        steps: 6, // <= Define the number of steps for this test case and this device
    },
    {
        name: "nanosp",
        label: "Nano S+",
        steps: 6, // <= Define the number of steps for this test case and this device
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
