#pragma once
#include "../Subscription.h"

class SubscriptionFactory
{
public:
    virtual Subscription* create(string id, string name, string description, int price, int duration, bool active, string userId) = 0;

    static SubscriptionFactory* getFactory(SubscriptionType type);
};