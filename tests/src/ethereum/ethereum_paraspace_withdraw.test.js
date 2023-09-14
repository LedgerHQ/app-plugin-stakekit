import { processTest, populateTransaction } from "../test.fixture";

const contractName = "InitializableAdminUpgradeabilityProxy";  // <= Name of the smart contract

const testLabel = "ethereum_paraspace_withdraw"; // <= Name of the test
const testDirSuffix = "ethereum_paraspace_withdraw"; // <= directory to compare device snapshots to
const testNetwork = "ethereum";
const signedPlugin = false;

const contractAddr = "0xc5c9fb6223a989208df27dcee33fc59ff5c26fff";   // <= Address of the smart contract
const chainID = 1;

// From : https://etherscan.io/tx/0xafce28bd45013d4a30285049020c07e27fc7a10e465473186d09654a310dc41e
const inputData = "0x2e1a7d4d000000000000000000000000000000000000000000000026bb402507cd0ac000";

// Create serializedTx and remove the "0x" prefix
const serializedTx = populateTransaction(contractAddr, inputData, chainID);

const devices = [
    {
        name: "nanos",
        label: "Nano S",
        steps: 4, // <= Define the number of steps for this test case and this device
    },
    {
        name: "nanox",
        label: "Nano X",
        steps: 4, // <= Define the number of steps for this test case and this device
    },
    {
        name: "nanosp",
        label: "Nano S+",
        steps: 4, // <= Define the number of steps for this test case and this device
    }
];

devices.forEach((device) =>
    processTest(device, contractName, testLabel, testDirSuffix, "", signedPlugin, serializedTx, testNetwork)
);
