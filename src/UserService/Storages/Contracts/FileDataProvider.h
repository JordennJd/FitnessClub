#pragma once
#include "DataProvider.h"
#include <string>

using namespace std;

class FileDataProvider : public DataProvider {
public:
    list<User> getUsers();

    void saveUser(User* user);

    User* getUser(int id);

    void updateUser(User* user);

    ~FileDataProvider();

private:
    string fileName = "./users.txt";
};