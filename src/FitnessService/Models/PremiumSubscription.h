#include "Subscription.h"


class PremiumSubscription : public Subscription{
    public:
        PremiumSubscription(string id, string name, string description, int price, int duration, bool active, string userId);
        ~PremiumSubscription();
};