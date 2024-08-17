#pragma once
#include "../Models/Factories/SubscriptionFactory.h"
#include "../../Logger/Imperative/Logger.h"
#include <list>

class FitnessService {
public:
    FitnessService(SubscriptionFactory* subscriptionFactory, Logger* logger);
    ~FitnessService();

    void createSubscription(string name, string description, int price, int duration, bool active, string userId);

    Subscription* getSubscription(int id);
    Subscription* getSubscriptionByUserId(string userId);
    list<Subscription> getSubscriptions();
private:
    SubscriptionFactory* subscriptionFactory;
    Logger* logger;
    static int index;
};