#include<string>
#include <ctime>
using namespace std;

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

    Subscription(string id, string name, string description, int price, int duration, bool active, string userId);
    Subscription();
    
};

enum SubscriptionType {
    Standart,
    Vip,
    Premium
};