import { processTest, populateTransaction } from "../test.fixture";

const contractName = "Vyper_contract";  // <= Name of the smart contract

const testLabel = "yearn_vault_deposit"; // <= Name of the test
const testNetwork = "fantom";
const signedPlugin = false;

const contractAddr = "0xef0210eb96c7eb36af8ed1c20306462764935607";   // <= Address of the smart contract
const chainID = 250;


const transactions = [
    {
        // From : https://ftmscan.com/tx/0xba3a60575b568f064aa428444dfcb950f8a32cc90eca62752698cd7a9115e870
        inputData: '0xd0e30db0',
        nanoStep: 7,
        nanoSPtep: 5,
        nanoXtep: 5,
        index: 1,
    },
    {
        // From : https://ftmscan.com/tx/0xf83cede3cbb7d450519137bf2aade666c7a42e545570f27bbe667f702e3f5b2b
        inputData: '0xb6b55f2500000000000000000000000000000000000000000000000000000000000f4240',
        nanoStep: 5,
        nanoSPtep: 5,
        nanoXtep: 5,
        index: 2,
    },
    {
        // From : https://ftmscan.com/tx/0x85cf621da132ed5472b6883a6a9945f5392d4abda74df50f8edb2991002f54f9
        inputData: '0x6e553f6500000000000000000000000000000000000000000000000000000000000f4240000000000000000000000000b6c5273e79e2add234ebc07d87f3824e0f94b2f7',
        nanoStep: 8,
        nanoSPtep: 6,
        nanoXtep: 6,
        index: 3,
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
