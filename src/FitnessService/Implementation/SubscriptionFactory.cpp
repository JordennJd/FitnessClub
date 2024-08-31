#include "../Models/Factories/SubscriptionFactory.h"
#include "../Models/Factories/StandartSubscriptionFactory.h"
#include "../Models/Factories/VipSubscriptionFactory.h"
#include "../Models/Factories/PremiumSubscriptionFactory.h"
#include "../Models/VipSubscription.h"
#include "../Models/PremiumSubscription.h"
#include "../Models/StandartSubscription.h"
#include <stdexcept>

SubscriptionFactory* SubscriptionFactory::getFactory(SubscriptionType type) {
    switch (type) {
        case SubscriptionType::Vip:
            return new VipSubscriptionFactory();
        case SubscriptionType::Premium:
            return new PremiumSubscriptionFactory();
        case SubscriptionType::Standart:
            return new StandartSubscriptionFactory();
        default:
            throw std::invalid_argument("Subscription type not found");
    }
}