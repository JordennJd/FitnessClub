#include "../../Logger/Imperative/Logger.h"
#include "../../Logger/Imperative/ConsoleLoggerStrategy.h"
#include "../../Logger/Imperative/FileLoggerStrategy.h"
#include "../../UserService/Contracts/UserService.h"
#include "../../UserService/Storages/Contracts/FileDataProvider.h"
#include "./../../FitnessService/Contracts/FitnessService.h"
#include "./../../FitnessService/Models/Factories/StandartSubscriptionFactory.h"
#include "./../../FitnessService/Models/Factories/VipSubscriptionFactory.h"
#include "./../../FitnessService/Models/Factories/PremiumSubscriptionFactory.h"
#include "./../../FitnessService/Storages/Contracts/FitnessFileDataProvider.h"
using namespace std;


int main(){
    Logger* logger = new Logger(new FileLoggerStrategy("./log.txt"));
    FileDataProvider* dataProvider = new FileDataProvider();
    UserService* userService = new UserService(dataProvider, logger);
    auto user = new User("John", "johndoe", "password", "25", "Male", "80", "180", "");
    auto user1 = new User("John1", "johndoe", "password", "25", "Male", "80", "180", "");
    auto user2 = new User("John2", "johndoe", "password", "25", "Male", "80", "180", "");


    userService->saveUser(user);
    User* obtained = userService->getUser(1);
    logger->log(obtained->id);
    obtained->subscriptionId = "1";
    userService->saveUser(obtained);

    userService->saveUser(user);
    userService->saveUser(user1);
    userService->saveUser(user2);
    User* obtained = userService->getUser(2);

    SubscriptionFactory* standartSubscriptionFactory = new StandartSubscriptionFactory();
    SubscriptionFactory* vipSubscriptionFactory = new VipSubscriptionFactory();
    SubscriptionFactory* premiumSubscriptionFactory = new PremiumSubscriptionFactory();
    FitnessFileDataProvider * fitnessFileDataProvider = new FitnessFileDataProvider();


    FitnessService* fitnessService = new FitnessService(standartSubscriptionFactory, logger, fitnessFileDataProvider);
    fitnessService->createSubscription(obtained);

    Subscription* obtainedSub = fitnessService->getSubscription(1);

    logger->log(obtainedSub->description);

    delete fitnessService;
    delete userService;
    delete logger;
} 