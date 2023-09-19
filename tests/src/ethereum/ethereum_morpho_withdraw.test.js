import { processTest, populateTransaction } from "../test.fixture";

const contractName = "TransparentUpgradeableProxy";  // <= Name of the smart contract

const testLabel = "ethereum_morpho_withdraw"; // <= Name of the test
const testNetwork = "ethereum";
const signedPlugin = false;

const contractAddr = "0x777777c9898d384f785ee44acfe945efdff5f3e0";   // <= Address of the smart contract
const chainID = 1;

const transactions = [
    {
        // From : https://etherscan.io/tx/0xdfdb427651807ed9ef26f15c3d0d3faed76d4529fdefc18309295ecac165f8c3
        inputData: '0xf3fef3a3000000000000000000000000030ba81f1c18d280636f32af80b9aad02cf0854e0000000000000000000000000000000000000000000000049b9ca9a6943400000000000000000000000000000000000000000000000000000000018a8dba6d6b000000000000000000000000000000000000000000000000000000000000da44',
        nanoStep: 4,
        nanoSPtep: 4,
        nanoXtep: 4,
        index: 1,
    },
    {
        // From : https://etherscan.io/tx/0x444f2d0401e982b452dc1259a98cc982929855f59dad57a48f6f8096c37dc841
        inputData: '0x69328dec0000000000000000000000009ff58f4ffb29fa2266ab25e75e2a8b3503311656000000000000000000000000000000000000000000000000000000000000271000000000000000000000000025ebad8a8d3246c127f5e61984651398558ec4ee',
        nanoStep: 7,
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
