#pragma once
#include "../../Models/Subscription.h"
#include "FitnessDataProvider.h"
#include <list>
#include <string>

using namespace std;
class FitnessFileDataProvider : public FitnessDataProvider
{
public:
    ~FitnessFileDataProvider();
    list<Subscription> getAll();
    Subscription* getAll(int id);
    void save(Subscription* subscription);
private:
    string fileName = "./subscriptions.txt";
};    
