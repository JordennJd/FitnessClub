#include "../../Logger/Imperative/Logger.h"
#include "../../Logger/Imperative/ConsoleLoggerStrategy.h"
#include "../../Logger/Imperative/FileLoggerStrategy.h"
#include "../../UserService/Contracts/UserService.h"
#include "../../UserService/Storages/Contracts/FileDataProvider.h"
#include "./../../FitnessService/Contracts/FitnessService.h"
#include "./../../FitnessService/Models/Factories/StandartSubscriptionFactory.h"
#include "./../../FitnessService/Models/Factories/VipSubscriptionFactory.h"
#include "./../../FitnessService/Models/Factories/PremiumSubscriptionFactory.h"
#include "./../../FitnessService/Storages/Contracts/FitnessFileDataProvider.h"
#include <cstdlib>  // For std::stoi

#include <iostream>
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>  // For std::setw and std::setfill
#include <string>
#include <vector>

// Function to display the menu with enhanced formatting
void displayMenu() {
    std::cout << "\n";
    std::cout << "=========================================\n";
    std::cout << "          \033[1;32mFitness Management System\033[0m          \n";
    std::cout << "=========================================\n";
    std::cout << "\033[1;34mSelect an action:\033[0m\n";
    std::cout << "1. \033[1;33mAdd a new user\033[0m\n";
    std::cout << "2. \033[1;33mGet user information\033[0m\n";
    std::cout << "3. \033[1;33mGet list of all users\033[0m\n";
    std::cout << "4. \033[1;33mCreate subscription for user\033[0m\n";
    std::cout << "5. \033[1;33mGet subscription information\033[0m\n";
    std::cout << "6. \033[1;31mExit\033[0m\n";
    std::cout << "=========================================\n";
    std::cout << "\033[1;36mEnter your choice:\033[0m ";
}

// Function to display the subscription menu with enhanced formatting
void displaySubscriptionMenu() {
    std::cout << "\n";
    std::cout << "=========================================\n";
    std::cout << "       \033[1;32mSubscription Types\033[0m       \n";
    std::cout << "=========================================\n";
    std::cout << "1. \033[1;33mStandard\033[0m\n";
    std::cout << "2. \033[1;33mVIP\033[0m\n";
    std::cout << "3. \033[1;33mPremium\033[0m\n";
    std::cout << "=========================================\n";
    std::cout << "\033[1;36mSelect subscription type:\033[0m ";
}

int main() {
    Logger* logger = new Logger(new FileLoggerStrategy("./log.txt"));
    FileDataProvider* dataProvider = new FileDataProvider();
    UserService* userService = new UserService(dataProvider, logger);
    
    SubscriptionFactory* standartSubscriptionFactory = new StandartSubscriptionFactory();
    SubscriptionFactory* vipSubscriptionFactory = new VipSubscriptionFactory();
    SubscriptionFactory* premiumSubscriptionFactory = new PremiumSubscriptionFactory();
    FitnessFileDataProvider* fitnessFileDataProvider = new FitnessFileDataProvider();

    FitnessService* fitnessService = new FitnessService(standartSubscriptionFactory, logger, fitnessFileDataProvider);

    int choice = 0;
    while (choice != 6) {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string name, username, password, age, gender, weight, height;
                std::cout << "\n\033[1;34mEnter user details:\033[0m\n";
                std::cout << "Name: ";
                std::cin >> name;
                std::cout << "Username: ";
                std::cin >> username;
                std::cout << "Password: ";
                std::cin >> password;
                std::cout << "Age: ";
                std::cin >> age;
                std::cout << "Gender: ";
                std::cin >> gender;
                std::cout << "Weight: ";
                std::cin >> weight;
                std::cout << "Height: ";
                std::cin >> height;

                User* user = new User(name, username, password, age, gender, weight, height, "");
                userService->saveUser(user);
                logger->log("User saved: " + user->name);
                
                std::cout << "\n\033[1;32mUser \"" << name << "\" successfully added!\033[0m\n";
                break;
            }
            case 2: {
                int userId;
                std::cout << "\n\033[1;34mEnter user ID:\033[0m ";
                std::cin >> userId;
                User* obtained = userService->getUser(userId);
                if (obtained) {
                    std::cout << "\n\033[1;32mUser information:\033[0m\n";
                    std::cout << "-----------------------------------------\n";
                    std::cout << "Name: " << obtained->name << "\n";
                    std::cout << "Age: " << obtained->age << "\n";
                    std::cout << "Gender: " << obtained->gender << "\n";
                    std::cout << "Weight: " << obtained->weigth << " kg\n";
                    std::cout << "Height: " << obtained->heigth << " cm\n";

                    // Check if the user has a subscription
                    Subscription* userSubscription = fitnessService->getSubscription(userId);
                    if (userSubscription) {
                        std::cout << "\033[1;33mSubscription:\033[0m " << userSubscription->description << "\n";
                    } else {
                        std::cout << "\033[1;31mNo subscription found for this user.\033[0m\n";
                    }
                    std::cout << "-----------------------------------------\n";

                    logger->log("User found: " + obtained->name);
                } else {
                    std::cout << "\033[1;31mUser not found!\033[0m\n";
                }
                break;
            }
            case 3: {
                auto users = userService->getUsers();
                std::cout << "\n\033[1;32mList of users:\033[0m\n";
                std::cout << "=========================================\n";
                for (const auto& user : users) {
                    std::cout << "ID: \033[1;34m" << user.id << "\033[0m, Name: \033[1;34m" << user.name << "\033[0m\n";

                    // Check if the user has a subscription
                    Subscription* userSubscription = fitnessService->getSubscription(std::stoi(user.id));
                    if (userSubscription) {
                        std::cout << "  \033[1;33mSubscription:\033[0m " << userSubscription->description << "\n";
                    }
                }
                std::cout << "=========================================\n";
                logger->log("User list retrieved.");
                break;
            }
            case 4: {
                int userId;
                std::cout << "\n\033[1;34mEnter user ID:\033[0m ";
                std::cin >> userId;
                User* obtained = userService->getUser(userId);
                if (obtained) {
                    int subChoice;
                    displaySubscriptionMenu();
                    std::cin >> subChoice;

                    // Select the appropriate factory based on user choice
                    switch (subChoice) {
                        case 1:
                            fitnessService->setSubscriptionsFactory(standartSubscriptionFactory);
                            break;
                        case 2:
                            fitnessService->setSubscriptionsFactory(vipSubscriptionFactory);
                            break;
                        case 3:
                            fitnessService->setSubscriptionsFactory(premiumSubscriptionFactory);
                            break;
                        default:
                            std::cout << "\033[1;31mInvalid subscription type, defaulting to Standard.\033[0m\n";
                            fitnessService->setSubscriptionsFactory(standartSubscriptionFactory);
                            break;
                    }

                    fitnessService->createSubscription(obtained);
                    logger->log("Subscription created for user: " + obtained->name);

                    std::cout << "\n\033[1;32mSubscription successfully created for user \"" << obtained->name << "\"!\033[0m\n";
                } else {
                    std::cout << "\033[1;31mUser not found!\033[0m\n";
                }
                break;
            }
            case 5: {
                int subscriptionId;
                std::cout << "\n\033[1;34mEnter subscription ID:\033[0m ";
                std::cin >> subscriptionId;
                Subscription* obtainedSub = fitnessService->getSubscription(subscriptionId);
                if (obtainedSub) {
                    std::cout << "\n\033[1;32mSubscription information:\033[0m\n";
                    std::cout << "-----------------------------------------\n";
                    std::cout << "Description: " << obtainedSub->description << "\n";
                    std::cout << "-----------------------------------------\n";
                    logger->log("Subscription information retrieved: " + obtainedSub->description);
                } else {
                    std::cout << "\033[1;31mSubscription not found!\033[0m\n";
                }
                break;
            }
            case 6: {
                std::cout << "\033[1;31mExiting...\033[0m\n";
                break;
            }
            default: {
                std::cout << "\033[1;31mInvalid choice, please try again.\033[0m\n";
                break;
            }
        }
    }

    // Clean up
    delete fitnessService;
    delete userService;
    delete logger;
    delete standartSubscriptionFactory;
    delete vipSubscriptionFactory;
    delete premiumSubscriptionFactory;
    delete fitnessFileDataProvider;

    return 0;
}