#include "../Models/PremiumSubscription.h"
#include "../Models/Subscription.h"
#include "../Models/Factories/PremiumSubscriptionFactory.h"
#include "../../UserService/Models/User.h"


using namespace std;

PremiumSubscriptionFactory::PremiumSubscriptionFactory() {}

Subscription* PremiumSubscriptionFactory::create(User* user) {
    auto subscription = new PremiumSubscription();
    subscription->name = "Premium for " + user->name;
    subscription->description = "Premium subscription for " + user->name;
    subscription->active = true;
    subscription->userId = user->id;
    subscription->type = SubscriptionType::Standart;
    time_t t = time(NULL);
    auto now = localtime(&t);
    now->tm_year += 1900;
    now->tm_mon += 1;
    subscription->buyDate = *now;
    now->tm_year += 3;
    auto exp = now;
    subscription->expirationDate = *exp;
    subscription->duration = 365 * 3;
    subscription->price = 1500 + stoi(user->age) * 10 + stoi(user->weigth) * 10 + stoi(user->heigth) * 10;
    return subscription;
}