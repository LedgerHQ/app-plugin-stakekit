import { processTest, populateTransaction } from "../test.fixture";

const contractName = "GraphProxy";  // <= Name of the smart contract

const testLabel = "ethereum_grt_delegate"; // <= Name of the test
const testDirSuffix = "ethereum_grt_delegate"; // <= directory to compare device snapshots to
const testNetwork = "ethereum";
const signedPlugin = false;

const contractAddr = "0xf55041e37e12cd407ad00ce2910b8269b01263b9";   // <= Address of the smart contract
const chainID = 1;

// From : https://etherscan.io/tx/0xa21c1858bca4780b04f388bd4795c61d1ab29ffe8569548fa997b5ac3d18e6f9
const inputData = "0x026e402b00000000000000000000000087eba079059b75504c734820d6cf828476754b8300000000000000000000000000000000000000000000000387dd99661fba5400";

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
    }
];

devices.forEach((device) =>
    processTest(device, contractName, testLabel, testDirSuffix, "", signedPlugin, serializedTx, testNetwork)
);
