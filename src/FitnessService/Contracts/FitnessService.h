#pragma once
#include "../Models/Factories/SubscriptionFactory.h"
#include "../../Logger/Imperative/Logger.h"
#include "../Storages/Contracts/FitnessDataProvider.h"
#include <list>

class FitnessService {
public:
    FitnessService(SubscriptionFactory* subscriptionFactory, Logger* logger, FitnessDataProvider* dataProvider);
    ~FitnessService();

    void createSubscription(User *user);

    Subscription* getSubscription(int id);
    Subscription* getSubscriptionByUserId(int userId);
    list<Subscription> getSubscriptions();
private:
    SubscriptionFactory* subscriptionFactory;
    Logger* logger;
    FitnessDataProvider* dataProvider;
    static int index;
};