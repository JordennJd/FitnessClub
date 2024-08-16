#ifndef HEADER_H_     
#define HEADER_H_
#include "LoggerStrategy.h"
#endif // HEADER_H_
using namespace std;

class FileLoggerStrategy : public LoggerStrategy
{
public:
    void log(string message);
    FileLoggerStrategy(string fileName = "");
private:
    string fileName = "./Log/log.txt";
};