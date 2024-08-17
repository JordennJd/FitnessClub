#include "../Models/StandartSubscription.h"
#include "../Models/Subscription.h"
#include "../Models/Factories/StandartSubscriptionFactory.h"
#include "../../UserService/Models/User.h"


using namespace std;

StandartSubscriptionFactory::StandartSubscriptionFactory() {}

Subscription* StandartSubscriptionFactory::create(User* user) {
    auto subscription = new StandartSubscription();
    subscription->name = "Standart for " + user->name;
    subscription->description = "Standart subscription for " + user->name;
    subscription->active = true;
    subscription->userId = user->id;
    subscription->type = SubscriptionType::Standart;
    time_t t = time(NULL);
    auto now = localtime(&t);
    now->tm_year += 1900;
    now->tm_mon += 1;
    subscription->buyDate = *now;
    now->tm_year += 1;
    auto exp = now;
    subscription->expirationDate = *exp;
    subscription->duration = 365;
    subscription->price = 1000 + stoi(user->age) * 10 + stoi(user->weigth) * 10 + stoi(user->heigth) * 10;
    return subscription;
}