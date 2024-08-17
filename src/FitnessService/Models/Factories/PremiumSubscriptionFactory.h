#pragma once
#include "../Subscription.h"

class PremiumSubscriptionFactory
{
public:
    Subscription* create(string id, string name, string description, int price, int duration, bool active, string userId);
};