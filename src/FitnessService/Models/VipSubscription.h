#include "Subscription.h"


class VipSubscription : public Subscription{
    public:
        VipSubscription(string id, string name, string description, int price, int duration, bool active, string userId);
        ~VipSubscription();
};