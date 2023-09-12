import { processTest, populateTransaction } from "../test.fixture";

const contractName = "RocketSwapRouter";  // <= Name of the smart contract

const testLabel = "ethereum_swap_from"; // <= Name of the test
const testDirSuffix = "ethereum_swap_from"; // <= directory to compare device snapshots to
const testNetwork = "ethereum";
const signedPlugin = false;

const contractAddr = "0x16d5a408e807db8ef7c578279beeee6b228f1c1c";   // <= Address of the smart contract
const chainID = 1;

// From : https://etherscan.io/tx/0x88d97705c3c665e5f8561f55da19a6a36ab9bcafda6231e8bf463f0b945cfe46
const inputData = "0xa824ae8b0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000a00000000000000000000000000000000000000000000000001d8072da437f6e800000000000000000000000000000000000000000000000001dccbc6ab0c91f800000000000000000000000000000000000000000000000001b4148901688ce7";

// Create serializedTx and remove the "0x" prefix
const serializedTx = populateTransaction(contractAddr, inputData, chainID);

const devices = [
    {
        name: "nanos",
        label: "Nano S",
        steps: 9, // <= Define the number of steps for this test case and this device
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
    }
];

devices.forEach((device) =>
    processTest(device, contractName, testLabel, testDirSuffix, "", signedPlugin, serializedTx, testNetwork)
);
