#pragma once
#include "../Subscription.h"
#include "../../../UserService/Models/User.h"
class SubscriptionFactory
{
public:
    virtual Subscription* create(User* user) = 0;
    static SubscriptionFactory* getFactory(SubscriptionType type);
};