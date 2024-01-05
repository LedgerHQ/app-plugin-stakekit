import { processTest, populateTransaction } from "../test.fixture";

const contractName = "TomoValidator";  // <= Name of the smart contract

const testLabel = "tomochain_vic_unvote"; // <= Name of the test
const testNetwork = "tomochain";
const signedPlugin = false;

const contractAddr = "0x0000000000000000000000000000000000000088";   // <= Address of the smart contract
const chainID = 88;

const transactions = [
    {
        // From : https://tomoscan.io/tx/0x497a6c4e1af6a1aeb9956f91d5c428de96d5b54eb72406c3401605125e567847
        inputData: "0x02aa9be200000000000000000000000095a512dba9e93814a2cf0925abf2f720c39c2bb700000000000000000000000000000000000000000000000e5d9d1ff846840000",
        nanoStep: 8,
        nanoSPtep: 6,
        nanoXtep: 6,
        index: 1,
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
