#include <fstream>
#include "../Imperative/FileLoggerStrategy.h"

using namespace std;

void FileLoggerStrategy::log(string message) {
    ofstream file;
    file.open(this->fileName, ios_base::app);
    file << message << endl;
    file.close();
}

FileLoggerStrategy::FileLoggerStrategy(string fileName) {
    if(fileName != ""){
        this->fileName = fileName;
    }
}