#pragma once
#include "../../Models/Subscription.h"

#include <list>
using namespace std;
class FitnessDataProvider
{
public:
    virtual list<Subscription> getAll() = 0;
    virtual Subscription* getById(int id) = 0;
    virtual void save(Subscription* subscription) = 0;
};