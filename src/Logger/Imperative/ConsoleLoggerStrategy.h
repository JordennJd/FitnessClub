#ifndef HEADER_H_     
#define HEADER_H_
#include "LoggerStrategy.h"
#endif // HEADER_H_
using namespace std;

class ConsoleLoggerStrategy : public LoggerStrategy
{
public:
    void log(std::string message) override ;
};