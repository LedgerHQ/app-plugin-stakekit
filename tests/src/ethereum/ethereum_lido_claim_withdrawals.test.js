import { processTest, populateTransaction } from "../test.fixture";

const contractName = "OssifiableProxy";  // <= Name of the smart contract

const testLabel = "ethereum_lido_claim_withdrawals"; // <= Name of the test
const testNetwork = "ethereum";
const signedPlugin = false;

const contractAddr = "0x889edc2edab5f40e902b864ad4d7ade8e412f9b1";   // <= Address of the smart contract
const chainID = 1;

const transactions = [
    {
        // From : https://etherscan.io/tx/0x9b55ea0772d02e277664583741e14d1f103b3a06666728d36093cbbc12cef8dd
        inputData: "0xe3afe0a3000000000000000000000000000000000000000000000000000000000000004000000000000000000000000000000000000000000000000000000000000000a000000000000000000000000000000000000000000000000000000000000000020000000000000000000000000000000000000000000000000000000000004ff70000000000000000000000000000000000000000000000000000000000004ff8000000000000000000000000000000000000000000000000000000000000000200000000000000000000000000000000000000000000000000000000000000e300000000000000000000000000000000000000000000000000000000000000e3",
        nanoStep: 7,
        nanoSPtep: 7,
        nanoXtep: 7,
        index: 1,
    },
    {
        // From : https://etherscan.io/tx/0xa3f20cdfaa0cad18482585e7617b700df470d06f3f2b6f871791510becc48417
        inputData: "0xe3afe0a30000000000000000000000000000000000000000000000000000000000000040000000000000000000000000000000000000000000000000000000000000008000000000000000000000000000000000000000000000000000000000000000010000000000000000000000000000000000000000000000000000000000004dfd000000000000000000000000000000000000000000000000000000000000000100000000000000000000000000000000000000000000000000000000000000e0",
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
