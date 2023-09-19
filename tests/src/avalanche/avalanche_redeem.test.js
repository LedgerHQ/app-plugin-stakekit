import { processTest, populateTransaction } from "../test.fixture";

const contractName = "TransparentUpgradeableProxy";  // <= Name of the smart contract

const testLabel = "avalanche_redeem"; // <= Name of the test
const testDirSuffix = "avalanche_redeem"; // <= directory to compare device snapshots to
const testNetwork = "avalanche";
const signedPlugin = false;

const contractAddr = "0x2b2c81e08f1af8835a78bb2a90ae924ace0ea4be";   // <= Address of the smart contract
const chainID = 43114;


const transactions = [
    {
        // From : https://snowtrace.io/tx/0xff1f51fae1bdb50dd47ce41bf0e740612c6480d62842c2ea1494593bbfd59540
        inputData: '0xbe040fb0',
        nanoStep: 7,
        nanoSPtep: 5,
        nanoXtep: 5,
        index: 1,
    },
    {
        // From : https://snowtrace.io/tx/0xe930e5431db191d40cdc3db840a21779184ae9175889aafab7fbd4761827f067
        inputData: '0xdb006a750000000000000000000000000000000000000000000000000000000000000000',
        nanoStep: 5,
        nanoSPtep: 5,
        nanoXtep: 5,
        index: 2,
    },
];

transactions.forEach((tx) => {
    const devices = [
        {
            name: 'nanos',
            label: 'Nano S',
            steps: tx.nanoStep, // <= Define the number of steps for this test case and this device
        },
        {
            name: 'nanox',
            label: 'Nano X',
            steps: tx.nanoSPtep, // <= Define the number of steps for this test case and this device
        },
        {
            name: 'nanosp',
            label: 'Nano S+',
            steps: tx.nanoXtep, // <= Define the number of steps for this test case and this device
        },
    ];

    const testDirSuffix = `${testLabel}_${tx.index}`; // <= directory to compare device snapshots to
    const serializedTx = populateTransaction(contractAddr, tx.inputData, chainID);

    devices.forEach((device) => processTest(device, contractName, testDirSuffix, testDirSuffix, '', signedPlugin, serializedTx, testNetwork));
});
