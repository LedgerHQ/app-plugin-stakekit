import { processTest, populateTransaction } from "../test.fixture";

const contractName = "OssifiableProxy";  // <= Name of the smart contract

const testLabel = "ethereum_lido_request_withdrawals"; // <= Name of the test
const testNetwork = "ethereum";
const signedPlugin = false;

const contractAddr = "0x889edc2edab5f40e902b864ad4d7ade8e412f9b1";   // <= Address of the smart contract
const chainID = 1;

const transactions = [
    {
        // From : https://etherscan.io/tx/0xf04b7649c40848f55e3fae8f6b511badb4af3ae7eefdec7609bc6cadd90495ab
        inputData: "0xd66810420000000000000000000000000000000000000000000000000000000000000040000000000000000000000000e7dbe6aa7edcc38cb5007b87153d236ad879309b000000000000000000000000000000000000000000000000000000000000000600000000000000000000000000000000000000000000003635c9adc5dea0000000000000000000000000000000000000000000000000003635c9adc5dea0000000000000000000000000000000000000000000000000003635c9adc5dea0000000000000000000000000000000000000000000000000003635c9adc5dea0000000000000000000000000000000000000000000000000003635c9adc5dea000000000000000000000000000000000000000000000000000128c5671c0043f210f",
        nanoStep: 9,
        nanoSPtep: 5,
        nanoXtep: 5,
        index: 1,
    },
    {
        // From : https://etherscan.io/tx/0xa15406c00339f694bd34f4c123bea678bfa2ef908f66ca73e65a2199641a3ec1
        inputData: '0xd66810420000000000000000000000000000000000000000000000000000000000000040000000000000000000000000a7e157be40806e2dc73fff09100739649ae6b4d4000000000000000000000000000000000000000000000000000000000000000100000000000000000000000000000000000000000000000005c2c45740144fda',
        nanoStep: 9,
        nanoSPtep: 5,
        nanoXtep: 5,
        index: 2,
    }
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
