#pragma once
#include "../../Models/Subscription.h"

#include <list>
#include <string>

using namespace std;
class FileDataProvider
{
public:
    ~FileDataProvider();
    list<Subscription> getAll();
    Subscription* getAll(int id);
    void save(Subscription* subscription);
private:
    string fileName = "./subscriptions.txt";
};    
