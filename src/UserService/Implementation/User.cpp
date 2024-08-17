#include "../Models/User.h"

User::User(string name, string email, string password, string age, string gender, string weigth, string heigth) {
    this->name = name;
    this->email = email;
    this->password = password;
    this->age = age;
    this->gender = gender;
    this->weigth = weigth;
    this->heigth = heigth;
}

User::User(){};