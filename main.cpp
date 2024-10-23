#include "Dict.hpp"
#include "NetUsers.hpp"
#include <iostream>

void displayMenu() {
    std::cout << "1. Add Admin" << std::endl;
    std::cout << "2. Add User" << std::endl;
    std::cout << "3. View Users" << std::endl;
    std::cout << "4. Delete User" << std::endl;
    std::cout << "5. Exit" << std::endl;
}

void handleAddAdmin(Dict& dict) {
    std::string name;
    int yearsOfExperience;
    
    std::cout << "Enter admin name: ";
    std::cin >> name;
    std::cout << "Enter years of experience: ";
    std::cin >> yearsOfExperience;

    Users* admin = new Admin(name, yearsOfExperience);
    dict.addUser(admin);
}

void handleAddUser(Dict& dict) {
    std::string name, registrationDate;
    
    std::cout << "Enter user name: ";
    std::cin >> name;
    std::cout << "Enter registration date (YYYY-MM-DD): ";
    std::cin >> registrationDate;

    Users* user = new DefUser(name, registrationDate);
    dict.addUser(user);
}

void handleMenu(Dict& dict) {
    int choice;
    do {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                handleAddAdmin(dict);
                break;
            case 2:
                handleAddUser(dict);
                break;
            case 3:
                dict.viewUsers();
                break;
            case 4: {
                int userIndex;
                dict.viewUsers();
                std::cout << "Enter user number to delete: ";
                std::cin >> userIndex;
                dict.deleteUser(userIndex);
                break;
            }
            case 5:
                dict.saveToFile("users.txt");
                std::cout << "Exiting program..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice." << std::endl;
        }
    } while (choice != 5);
}

int main() {
    Dict myDict;
    myDict.loadFromFile("users.txt");

    handleMenu(myDict);

    return 0;
}
