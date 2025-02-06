import { processTest, populateTransaction } from "../test.fixture";

const contractName = "StakeHub";  // <= Name of the smart contract

const testLabel = "bsc_undelegate"; // <= Name of the test
const testDirSuffix = "bsc_undelegate"; // <= directory to compare device snapshots to
const testNetwork = "bsc";
const signedPlugin = false;

const contractAddr = "0x0000000000000000000000000000000000002002";   // <= Address of the smart contract
const chainID = 56;

// From : https://bscscan.com/tx/0x53db4ffefe847eab3683dd9201be2a6e410ab507b43051ac08fe9b61ef337c12
const inputData = "0x4d99dd1600000000000000000000000011f3a9d13f6f11f29a7c96922c5471f356bd129f0000000000000000000000000000000000000000000000000dc0b539ef122ad6";

// Create serializedTx and remove the "0x" prefix
const serializedTx = populateTransaction(contractAddr, inputData, chainID);

const devices = [
    {
        name: "nanos",
        label: "Nano S",
        steps: 7, // <= Define the number of steps for this test case and this device
    },
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
