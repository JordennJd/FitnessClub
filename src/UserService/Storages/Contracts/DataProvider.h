#pragma once     
#include <list>
#include "../../Models/User.h"


class DataProvider {
    public:
        virtual list<User> getUsers() = 0;
        virtual void saveUser(User* user) = 0;
        virtual User* getUser(int id) = 0;
        virtual ~DataProvider() = default;
};