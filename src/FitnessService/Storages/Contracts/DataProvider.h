#pragma once
#include "../../Models/Subscription.h"

#include <list>
using namespace std;
class DataProvider
{
public:
    virtual ~DataProvider() = default;
    virtual list<Subscription> getAll() = 0;
    virtual Subscription* getAll(int id) = 0;
    virtual void save(Subscription* subscription) = 0;
};