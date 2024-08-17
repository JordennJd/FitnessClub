#include "../Models/VipSubscription.h"
#include "../Models/Subscription.h"
#include "../Models/Factories/VipSubscriptionFactory.h"
#include "../../UserService/Models/User.h"


using namespace std;

VipSubscriptionFactory::VipSubscriptionFactory() {}

Subscription* VipSubscriptionFactory::create(User* user) {
    auto subscription = new VipSubscription();
    subscription->name = "Vip for " + user->name;
    subscription->description = "Vip subscription for " + user->name;
    subscription->active = true;
    subscription->userId = user->id;
    subscription->type = SubscriptionType::Vip;
    time_t t = time(NULL);
    auto now = localtime(&t);
    now->tm_year += 1900;
    now->tm_mon += 1;
    subscription->buyDate = *now;
    now->tm_year += 2;
    auto exp = now;
    subscription->expirationDate = *exp;
    subscription->duration = 365 * 2;
    subscription->price = 1500 + stoi(user->age) * 10 + stoi(user->weigth) * 10 + stoi(user->heigth) * 10;
    return subscription;
}