import { processTest, populateTransaction } from "../test.fixture";

const contractName = "TransparentUpgradeableProxy";  // <= Name of the smart contract

const testLabel = "avalanche_redeem_overdue_shares"; // <= Name of the test
const testDirSuffix = "avalanche_redeem_overdue_shares"; // <= directory to compare device snapshots to
const testNetwork = "avalanche";
const signedPlugin = false;

const contractAddr = "0x2b2c81e08f1af8835a78bb2a90ae924ace0ea4be";   // <= Address of the smart contract
const chainID = 43114;


const transactions = [
    {
        // From : https://snowtrace.io/tx/0xada8f8fe6ae25dcf9bdbccb9caf8d3f0dc75b5085f03c665d5cc4cd16eced93c
        inputData: '0x0d10d32c',
        nanoStep: 8,
        nanoSPtep: 5,
        nanoXtep: 5,
        index: 1,
    },
    {
        // From : https://snowtrace.io/tx/0x03280d9d84c0f20870a9a265aa00dd69299a332e16e504104048116a1a6d7e5d
        inputData: '0x0f7e20480000000000000000000000000000000000000000000000000000000000000000',
        nanoStep: 6,
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
