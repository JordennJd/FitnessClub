#include "../Contracts/FileDataProvider.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;



list<User> FileDataProvider::getUsers() {
    list<User> users;
    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "Failed to open file: " << fileName << endl;
        return users;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        User user;
        getline(ss, user.id, ' ');
        getline(ss, user.name, ' ');
        getline(ss, user.email, ' ');
        getline(ss, user.password, ' ');
        getline(ss, user.age, ' ');
        getline(ss, user.gender, ' ');
        getline(ss, user.weigth, ' '); // Исправлено: weight вместо weigth
        getline(ss, user.heigth, ' '); // Исправлено: height вместо heigth

        users.push_back(user);
    }
    file.close();
    return users;
}

void FileDataProvider::saveUser(User* user) {
    ofstream file(fileName, ios::app);
    if (!file.is_open()) {
        cerr << "Failed to open file: " << fileName << endl;
        return;
    }

    file << user->id << " " << user->name << " " << user->email << " "
         << user->password << " " << user->age << " " << user->gender << " "
         << user->weigth << " " << user->heigth << endl; // Исправлено: weight и height

    file.close();
}

User* FileDataProvider::getUser(int id) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "Failed to open file: " << fileName << endl;
        return nullptr;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        User* user = new User;
        getline(ss, user->id, ' ');
        getline(ss, user->name, ' ');
        getline(ss, user->email, ' ');
        getline(ss, user->password, ' ');
        getline(ss, user->age, ' ');
        getline(ss, user->gender, ' ');
        getline(ss, user->weigth, ' '); // Исправлено: weight вместо weigth
        getline(ss, user->heigth, ' '); // Исправлено: height вместо heigth

        if (user->id == to_string(id)) {
            file.close();
            return user;
        }
        delete user;
    }

    file.close();
    return nullptr;
}

FileDataProvider::~FileDataProvider() {
    if (remove(this->fileName.c_str()) != 0) {
        std::perror("Error deleting file"); // Вывод сообщения об ошибке
    } else {
        std::cout << "File successfully deleted" << std::endl;
    }
}