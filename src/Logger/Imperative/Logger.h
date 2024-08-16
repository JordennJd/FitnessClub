#ifndef HEADER_H_     
#define HEADER_H_
#include "LoggerStrategy.h"
#endif // HEADER_H_
#pragma once

using namespace std;

class Logger
{
public:
    Logger(LoggerStrategy* strategy);
    ~Logger();
    void log(std::string message);
private:
    LoggerStrategy* strategy;
};