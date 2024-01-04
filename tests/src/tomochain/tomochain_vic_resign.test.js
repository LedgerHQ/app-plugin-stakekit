import { processTest, populateTransaction } from "../test.fixture";

const contractName = "TomoValidator";  // <= Name of the smart contract

const testLabel = "tomochain_vic_resign"; // <= Name of the test
const testNetwork = "tomochain";
const signedPlugin = false;

const contractAddr = "0x0000000000000000000000000000000000000088";   // <= Address of the smart contract
const chainID = 88;

const transactions = [
    {
        // From : https://tomoscan.io/tx/0x820b57ef79a067c3b7d2c9e99b46a63a1a8cafb8c4b51ca23d01928efe66a3d7
        inputData: "0xae6e43f5000000000000000000000000d3cac70664429382db8f59ca1eac89634edd23c8",
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
