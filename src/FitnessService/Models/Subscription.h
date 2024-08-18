#pragma once
#include<string>
#include <ctime>
using namespace std;
enum SubscriptionType {
    Standart,
    Vip,
    Premium
};
class Subscription{
public:
    string id;
    string name;
    string description;
    double price;
    int duration;
    bool active;
    string userId;
    tm expirationDate;
    tm buyDate;
    SubscriptionType type;
};