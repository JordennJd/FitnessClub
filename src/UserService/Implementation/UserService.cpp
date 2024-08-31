#include "../Contracts/UserService.h"
#include <iostream>

int UserService::index = 1;
const string _prefix = "[UserService] ";

UserService::UserService(DataProvider* dataProvider, Logger* logger) {
    this->dataProvider = dataProvider;
    this->logger = logger;
}

UserService::~UserService() {
    delete dataProvider;
}

User* UserService::getUser(int id) {
    logger->log(_prefix + "get user with id " + to_string(id));
    return dataProvider->getUser(id);
}

void UserService::saveUser(User* user) {
    if(user->id != ""){
        logger->log(_prefix + "ipdate user with id " + user->id);
        dataProvider->updateUser(user);
        return;
    }
    user->id = to_string(UserService::index);
    logger->log(_prefix + "save user with id " + user->id);
    UserService::index++;
    dataProvider->saveUser(user);
}

list<User> UserService::getUsers() {
    logger->log(_prefix + "get all users ");
    return this->dataProvider->getUsers();
}