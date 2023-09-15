import { processTest, populateTransaction } from "../test.fixture";

const contractName = "TokenHub";  // <= Name of the smart contract

const testLabel = "bsc_transfer_out"; // <= Name of the test
const testDirSuffix = "bsc_transfer_out"; // <= directory to compare device snapshots to
const testNetwork = "bsc";
const signedPlugin = false;

const contractAddr = "0x0000000000000000000000000000000000001004";   // <= Address of the smart contract
const chainID = 56;

// From : https://bscscan.com/tx/0x360486359f85bc7393f4f2db3aa49e6f3bf76412acbfd24e570f7637b0ed4e2c
const inputData = "0xaa7415f50000000000000000000000000000000000000000000000000000000000000000000000000000000000000000b10c289ece8279379a7a3d4c800b4574b2c6d0ae0000000000000000000000000000000000000000000000025a012aab0fab80000000000000000000000000000000000000000000000000000000000065031672";

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
