#include "../Contracts/FitnessFileDataProvider.h"
#include "../../Models/Subscription.h"
#include <fstream>
#include <sstream>
#include <iostream>



list<Subscription> FitnessFileDataProvider::getAll() {
    list<Subscription> subscriptions;
    ifstream file(fileName);
    
    if (!file.is_open()) {
        cerr << "Failed to open file: " << fileName << endl;
        return subscriptions;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        Subscription subscription;
        
        getline(ss, subscription.id, ' ');
        getline(ss, subscription.name, ' ');
        getline(ss, subscription.description, ' ');
        ss >> subscription.price;
        ss >> subscription.duration;
        ss >> subscription.active;
        getline(ss, subscription.userId, ' ');

        // Пропуск для даты и типа подписки
        // Добавьте парсинг для buyDate, expirationDate и type, если потребуется

        subscriptions.push_back(subscription);
    }

    file.close();
    return subscriptions;
}

Subscription* FitnessFileDataProvider::getAll(int id) {
    ifstream file(fileName);
    
    if (!file.is_open()) {
        cerr << "Failed to open file: " << fileName << endl;
        return nullptr;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        Subscription* subscription = new Subscription();

        getline(ss, subscription->id, ' ');
        if (subscription->id == to_string(id)) {
            getline(ss, subscription->name, ' ');
            getline(ss, subscription->description, ' ');
            ss >> subscription->price;
            ss >> subscription->duration;
            ss >> subscription->active;
            getline(ss, subscription->userId, ' ');

            // Пропуск для даты и типа подписки
            // Добавьте парсинг для buyDate, expirationDate и type, если потребуется

            file.close();
            return subscription;
        }
        delete subscription;
    } 

    file.close();
    return nullptr;
}

void FitnessFileDataProvider::save(Subscription* subscription) {
    ofstream file(fileName, ios::app);
    
    if (!file.is_open()) {
        cerr << "Failed to open file: " << fileName << endl;
        return;
    }

    file << subscription->id << " "
         << subscription->name << " "
         << subscription->description << " "
         << subscription->price << " "
         << subscription->duration << " "
         << subscription->active << " "
         << subscription->userId << endl;

    // Пропуск для даты и типа подписки
    // Добавьте сохранение buyDate, expirationDate и type, если потребуется

    file.close();
}
