#include <string>

class LoggerStrategy
{
public:
    virtual void log(std::string message) = 0;
};