#include <iostream>
#include "../Imperative/ConsoleLoggerStrategy.h"

using namespace std;

void ConsoleLoggerStrategy::log(string message) {
    cout << message << endl;
}