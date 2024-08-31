#include "../Contracts/FileDataProvider.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

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
        getline(ss, user.weigth, ' '); 
        getline(ss, user.heigth, ' ');
        getline(ss, user.subscriptionId, ' ');

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
         << user->weigth << " " << user->heigth << user->subscriptionId << endl; 
    file.close();
}

void FileDataProvider::updateUser(User* user) {
    std::ifstream fileIn(fileName);
    if (!fileIn.is_open()) {
        std::cerr << "Failed to open file: " << fileName << std::endl;
        return;
    }

    std::vector<std::string> lines;
    std::string line;
    bool userFound = false;

    // Читаем файл построчно и ищем нужного пользователя
    while (std::getline(fileIn, line)) {
        std::istringstream iss(line);
        int id;
        iss >> id;

        if (to_string(id) == user->id) {
            // Формируем обновленную строку
            std::ostringstream oss;
            oss << user->id << " " << user->name << " " << user->email << " "
                << user->password << " " << user->age << " " << user->gender << " "
                << user->weigth << " " << user->heigth << " " << user->subscriptionId;
            lines.push_back(oss.str());
            userFound = true;
        } else {
            // Если не наш пользователь, просто добавляем строку как есть
            lines.push_back(line);
        }
    }

    fileIn.close();

    if (!userFound) {
        std::cerr << "User with ID " << user->id << " not found." << std::endl;
        return;
    }

    // Записываем обновленные данные обратно в файл
    std::ofstream fileOut(fileName);
    if (!fileOut.is_open()) {
        std::cerr << "Failed to open file: " << fileName << std::endl;
        return;
    }

    for (const auto& l : lines) {
        fileOut << l << std::endl;
    }

    fileOut.close();
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
        getline(ss, user->weigth, ' '); 
        getline(ss, user->heigth, ' '); 
        getline(ss, user->subscriptionId, ' ');

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