import { processTest, populateTransaction } from "../test.fixture";

const contractName = "ValidatorShareProxy";  // <= Name of the smart contract

const testLabel = "ethereum_withdraw_rewards_pol"; // <= Name of the test
const testDirSuffix = "ethereum_withdraw_rewards_pol"; // <= directory to compare device snapshots to
const testNetwork = "ethereum";
const signedPlugin = false;

const contractAddr = "0x35b1ca0f398905cf752e6fe122b51c88022fca32";   // <= Address of the smart contract
const chainID = 1;

// From : https://etherscan.io/tx/0x2749b0232d137a1647bd5cefedd751bc22e89a0e2e2586d82ac56b9219502b23
const inputData = "0xe0db556b";

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
