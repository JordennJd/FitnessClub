#include "User.h"
#include <list>

class UserService{
    public:
    UserService();
    ~UserService();

    User* getUser(int id);

    void saveUser(User* user);

    list<User> getUsers();
};