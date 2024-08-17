#include "../Models/User.h"
#include <list>
#include "../Storages/Contracts/DataProvider.h"

class UserService{
    public:
    UserService(DataProvider* DataProvider);
    ~UserService();

    User* getUser(int id);

    void saveUser(User* user);

    list<User> getUsers();
private:
    DataProvider* dataProvider;
    static int index;
};