#ifndef HEADER_H_     
#define HEADER_H_
#include <list>
#include "User.h"
#endif // HEADER_H_

class DataProvider {
    public:
        virtual list<User> getUsers() = 0;
        virtual void saveUser(User* user) = 0;
        virtual User* getUser(int id) = 0;
};