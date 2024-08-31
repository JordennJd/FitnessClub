#include "../Models/User.h"
#include <list>
#include "../Storages/Contracts/DataProvider.h"
#include "../../Logger/Imperative/Logger.h"

class UserService{
    public:
    UserService(DataProvider* DataProvider, Logger* logger);
    ~UserService();

    User* getUser(int id);

    void saveUser(User* user);

    list<User> getUsers();
private:
    DataProvider* dataProvider;
    Logger* logger;
    static int index;
};