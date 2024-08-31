#include "../Contracts/FitnessService.h"
#include "../Models/Factories/SubscriptionFactory.h"
#include "../Models/Subscription.h"

int FitnessService::index = 1;
const string _prefix = "[FitnessService] ";
FitnessService::FitnessService(SubscriptionFactory* subscriptionFactory, Logger* logger, FitnessDataProvider* dataProvider){
    this->subscriptionFactory = subscriptionFactory;
    this->dataProvider = dataProvider;
    this->logger = logger;
}

FitnessService::~FitnessService(){
    delete subscriptionFactory;
    delete logger;
}

void FitnessService::createSubscription(User* user) {
    Subscription* subscription = subscriptionFactory->create(user);
    subscription->id = to_string(FitnessService::index);
    logger->log(_prefix + "Created subscription: " + subscription->name);
    this->dataProvider->save(subscription);
    FitnessService::index++;
}

list<Subscription> FitnessService::getSubscriptions() {
    logger->log(_prefix + "get all subscriptions");
    return this->dataProvider->getAll();
}

Subscription* FitnessService::getSubscription(int userId) {
    logger->log(_prefix + "get subscription for user with id " + to_string(userId));
    return this->dataProvider->getById(userId);
}