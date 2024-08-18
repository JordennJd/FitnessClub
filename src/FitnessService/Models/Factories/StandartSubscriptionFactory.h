#pragma once
#include "../Subscription.h"
#include "SubscriptionFactory.h"
#include "../../../UserService/Models/User.h"


using namespace std;

class StandartSubscriptionFactory : public SubscriptionFactory
{
public:
    StandartSubscriptionFactory();
    Subscription* create(User* user) override;
};