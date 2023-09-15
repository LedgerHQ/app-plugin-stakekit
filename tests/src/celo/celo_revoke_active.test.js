import { processTest, populateTransaction } from "../test.fixture";

const contractName = "ElectionProxy";  // <= Name of the smart contract

const testLabel = "celo_revoke_active"; // <= Name of the test
const testDirSuffix = "celo_revoke_active"; // <= directory to compare device snapshots to
const testNetwork = "celo";
const signedPlugin = false;

const contractAddr = "0x8d6677192144292870907e3fa8a5527fe55a7ff6";   // <= Address of the smart contract
const chainID = 42220;

// From : https://celoscan.io/tx/0xd721d24e95b5a359f1e54e59d4fe92fb22ad19a5e9481382c15b5edc1ab0402b
const inputData = "0x6e1984750000000000000000000000004da92da1afbf103f2b52dd29326e34c98ca1e78c000000000000000000000000000000000000000000000056bed3f962b0f7cc3600000000000000000000000035ae10f412503abcf9275133613e8df7f56e72be000000000000000000000000dadbd6cfb29b054adc9c4c2ef0f21f0bbdb448710000000000000000000000000000000000000000000000000000000000000000";

// Create serializedTx and remove the "0x" prefix
const serializedTx = populateTransaction(contractAddr, inputData, chainID);

const devices = [
    {
        name: "nanos",
        label: "Nano S",
        steps: 15, // <= Define the number of steps for this test case and this device
    },
    {
        name: "nanox",
        label: "Nano X",
        steps: 8, // <= Define the number of steps for this test case and this device
    },
    {
        name: "nanosp",
        label: "Nano S+",
        steps: 8, // <= Define the number of steps for this test case and this device
    }
];

devices.forEach((device) =>
    processTest(device, contractName, testLabel, testDirSuffix, "", signedPlugin, serializedTx, testNetwork)
);
