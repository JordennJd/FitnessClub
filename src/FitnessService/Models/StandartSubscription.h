#include "Subscription.h"


class StandartSubscription : public Subscription{
    public:
        StandartSubscription(string id, string name, string description, int price, int duration, bool active, string userId);
        ~StandartSubscription();
};