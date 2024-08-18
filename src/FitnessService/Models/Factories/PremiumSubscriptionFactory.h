#pragma once
#include "../Subscription.h"
#include "SubscriptionFactory.h"
#include "../../../UserService/Models/User.h"

class PremiumSubscriptionFactory : public SubscriptionFactory
{
public:
    PremiumSubscriptionFactory();
    Subscription* create(User* user) override;
};