#include "../Contracts/UserService.h"
#include <iostream>
int UserService::index = 1;

UserService::UserService(DataProvider* dataProvider) {
    this->dataProvider = dataProvider;
}

UserService::~UserService() {
    delete dataProvider;
}

User* UserService::getUser(int id) {
    return dataProvider->getUser(id);
}

void UserService::saveUser(User* user) {
    user->id = to_string(UserService::index);
    UserService::index++;
    dataProvider->saveUser(user);
}

list<User> UserService::getUsers() {
    return this->dataProvider->getUsers();
}