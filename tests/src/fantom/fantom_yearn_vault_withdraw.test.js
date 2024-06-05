import { processTest, populateTransaction } from "../test.fixture";

const contractName = "Vyper_contract";  // <= Name of the smart contract

const testLabel = "fantom_yearn_vault_withdraw"; // <= Name of the test
const testNetwork = "fantom";
const signedPlugin = false;

const contractAddr = "0xef0210eb96c7eb36af8ed1c20306462764935607";   // <= Address of the smart contract
const chainID = 250;


const transactions = [
    {
        // From : https://ftmscan.com/tx/0x0886b343f22515ceeec557ab3a810aab99d296eefed5a402dd0022c1d2984591
        inputData: '0x3ccfd60b',
        nanoStep: 7,
        nanoSPtep: 5,
        nanoXtep: 5,
        index: 1,
    },
    {
        // From : https://ftmscan.com/tx/0x64c9853386866501f3fee802b269b50588832524a0fa7db8d62b9d05443ccedf
        inputData: '0x2e1a7d4d0000000000000000000000000000000000000000000000000000000011297cb7',
        nanoStep: 5,
        nanoSPtep: 5,
        nanoXtep: 5,
        index: 2,
    },
    {
        // From : https://ftmscan.com/tx/0xcb0590a2bd4ad4796bfd539f0ccce805ab2555d90b7a38369940701f2f20c0d5
        inputData: '0x00f714ce00000000000000000000000000000000000000000000000000000000000e643f000000000000000000000000b6c5273e79e2add234ebc07d87f3824e0f94b2f7',
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
