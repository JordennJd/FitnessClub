#include "../../Logger/Imperative/Logger.h"
#include "../../Logger/Imperative/ConsoleLoggerStrategy.h"
#include "../../Logger/Imperative/FileLoggerStrategy.h"
#include "../../UserService/Contracts/UserService.h"
#include "../../UserService/Storages/Contracts/FileDataProvider.h"

using namespace std;

int main(){
    Logger* logger = new Logger(new ConsoleLoggerStrategy());
    FileDataProvider* dataProvider = new FileDataProvider();
    UserService* userService = new UserService(dataProvider);
    auto user = new User("John", "johndoe", "password", "25", "Male", "80", "180");
    auto user1 = new User("John1", "johndoe", "password", "25", "Male", "80", "180");
    auto user2 = new User("John2", "johndoe", "password", "25", "Male", "80", "180");

    userService->saveUser(user);
    userService->saveUser(user1);
    userService->saveUser(user2);

    User* obtained = userService->getUser(2);
    logger->log(obtained->name);

    delete userService;
    delete logger;
} 