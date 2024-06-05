import { processTest, populateTransaction } from "../test.fixture";

const contractName = "TomoValidator";  // <= Name of the smart contract

const testLabel = "tomochain_vic_withdraw"; // <= Name of the test
const testNetwork = "tomochain";
const signedPlugin = false;

const contractAddr = "0x0000000000000000000000000000000000000088";   // <= Address of the smart contract
const chainID = 88;

const transactions = [
    {
        // From : https://tomoscan.io/tx/0x18a68417e99b419c9b16c20474ca3df78ce9767ca4059385d0a5b75648e56c44
        inputData: "0x441a3e7000000000000000000000000000000000000000000000000000000000046648e00000000000000000000000000000000000000000000000000000000000000000",
        nanoStep: 6,
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
