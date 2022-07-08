#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <string>
#include <iostream>
#include <nlohmann/json.hpp>
#include "definitions.hpp"

using namespace std;
using json = nlohmann::json;

class Config
{
public:
    bool runProverServer;
    bool runProverServerMock;
    bool runProverClient;
    bool runExecutorServer;
    bool runExecutorServerMock;
    bool runExecutorClient;
    bool runStateDBServer;
    bool runStateDBTest;
    bool runFile;
    bool runFileFast;
    bool runKeccakScriptGenerator;
    bool runKeccakTest;
    bool runStorageSMTest;
    bool runBinarySMTest;
    bool runMemAlignSMTest;
    bool runStarkTest;
    bool executeInParallel;
    bool useMainExecGenerated;
    uint16_t proverServerPort;
    uint16_t proverServerMockPort;
    uint16_t proverClientPort;
    uint16_t executorServerPort;
    uint16_t executorClientPort;
    string executorClientHost;
    uint16_t stateDBServerPort;
    string stateDBURL;
    string inputFile;
    string outputPath;
    string romFile;
    string pilFile;
    string cmPolsFile;
    string constPolsFile;
    string constantsTreeFile;
    string scriptFile;
    string starkFile;
    string verifierFile;
    string witnessFile;
    string starkVerifierFile;
    string publicFile;
    string proofFile;
    string keccakScriptFile;
    string keccakPolsFile;
    string keccakConnectionsFile;
    string storageRomFile;
    string storagePilFile;
    string storagePolsFile;
    string memoryPilFile;
    string memoryPolsFile;
    string binaryPilFile;
    string binaryPolsFile;
    string binaryConstPolsFile;
    string starkInfoFile;
    //string dbHost;
    //uint16_t dbPort;
    //string dbUser;
    //string dbPassword;
    //string dbDatabaseName;
    string databaseURL;
    string dbTableName;
    bool dbAsyncWrite;
    uint64_t cleanerPollingPeriod;
    uint64_t requestsPersistence;
    void load(json &config);
    bool generateProof(void) const { return runProverServer || runFile; }
};

#endif