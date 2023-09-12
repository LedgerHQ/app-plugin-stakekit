import { processTest, populateTransaction } from "../test.fixture";

const contractName = "AdminUpgradeabilityProxy";  // <= Name of the smart contract

const testLabel = "ethereum_stake"; // <= Name of the test
const testDirSuffix = "ethereum_stake"; // <= directory to compare device snapshots to
const testNetwork = "ethereum";
const signedPlugin = false;

const contractAddr = "0xc874b064f465bdd6411d45734b56fac750cda29a";   // <= Address of the smart contract
const chainID = 1;

// From : https://etherscan.io/tx/0x2c642cbc1bf3cf092b8b2b427548147c68104f9f80edff12b5174cf924d7a848
const inputData = "0x3a4b66f1";

// Create serializedTx and remove the "0x" prefix
const serializedTx = populateTransaction(contractAddr, inputData, chainID, "4.2");

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
