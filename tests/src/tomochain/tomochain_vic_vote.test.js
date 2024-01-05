import { processTest, populateTransaction } from "../test.fixture";

const contractName = "TomoValidator";  // <= Name of the smart contract

const testLabel = "tomochain_vic_vote"; // <= Name of the test
const testNetwork = "tomochain";
const signedPlugin = false;

const contractAddr = "0x0000000000000000000000000000000000000088";   // <= Address of the smart contract
const chainID = 88;

const transactions = [
    {
        // From : https://tomoscan.io/tx/0xd2b87e71d3c3a2a48985608736649851c67f8764c117a8cd19bb58464c0f70f6
        inputData: "0x6dd7d8ea000000000000000000000000fe66acfe4d132780fdbedbf3f113eb869d19db58",
        nanoStep: 7,
        nanoSPtep: 5,
        nanoXtep: 5,
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
