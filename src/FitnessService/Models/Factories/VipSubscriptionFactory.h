#pragma once
#include "../Subscription.h"
#include "SubscriptionFactory.h"
#include "../../../UserService/Models/User.h"

class VipSubscriptionFactory : public SubscriptionFactory
{
public:
    VipSubscriptionFactory();
    Subscription* create(User* user) override;
};