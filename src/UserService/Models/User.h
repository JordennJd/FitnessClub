#pragma once  
#include <string>

using namespace std;
class User
{
public:
    string id;
    string name;
    string email;
    string password;
    string age;
    string gender;
    string weigth;
    string heigth;
    string subscriptionId;

    User(string name, string email,
     string password, string age, string gender,
      string weigth, string heigth, string subscriptionId);
    User();
};