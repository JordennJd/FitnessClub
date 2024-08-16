#include "../Imperative/Logger.h"

using namespace std;

Logger::Logger(LoggerStrategy* strategy) {
    this->strategy = strategy;
}

Logger::~Logger() {
    delete strategy;
}

void Logger::log(std::string message) {
    strategy->log(message);
}