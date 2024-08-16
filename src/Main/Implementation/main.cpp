#include "../../Logger/Imperative/Logger.h"
#include "../../Logger/Imperative/ConsoleLoggerStrategy.h"
#include "../../Logger/Imperative/FileLoggerStrategy.h"
using namespace std;

int main(){
    Logger* logger = new Logger(new FileLoggerStrategy("log.txt"));
    logger->log("Hello World");
}

