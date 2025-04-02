import { processTest, populateTransaction } from "../test.fixture";

const contractName = "ValidatorShareProxy";  // <= Name of the smart contract

const testLabel = "ethereum_sell_voucher_new_pol"; // <= Name of the test
const testDirSuffix = "ethereum_sell_voucher_new_pol"; // <= directory to compare device snapshots to
const testNetwork = "ethereum";
const signedPlugin = false;

const contractAddr = "0x56d783Ca8e0b998C57a428Bf1c26A8baca50524e";   // <= Address of the smart contract
const chainID = 1;

// From : https://etherscan.io/tx/0x05497a760f918f43533d2608272ac0f9df729063cf10d3f93d823241380b200d
const inputData = "0xe570b78b00000000000000000000000000000000000000000000001491ed349675f9000000000000000000000000000000000000000000000000001491ed349675f90000";

// Create serializedTx and remove the "0x" prefix
const serializedTx = populateTransaction(contractAddr, inputData, chainID);

const devices = [
    {
        name: "nanos",
        label: "Nano S",
        steps: 6, // <= Define the number of steps for this test case and this device
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
