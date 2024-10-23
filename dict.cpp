#include "Dict.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

Dict::~Dict() {
    for (auto user : users) {
        delete user;
    }
    users.clear();
}

void Dict::addUser(Users* user) {
    users.push_back(user);
}

void Dict::deleteUser(int index) {
    if (index > 0 && index <= users.size()) {
        auto it = users.begin();
        std::advance(it, index - 1);
        delete *it;
        users.erase(it);
        std::cout << "User deleted." << std::endl;
    } else {
        std::cout << "Invalid index." << std::endl;
    }
}

void Dict::viewUsers() const {
    if (users.empty()) {
        std::cout << "No users found." << std::endl;
    } else {
        int index = 1;
        for (const auto& user : users) {
            std::cout << index << ". " << user->getRole() << ": " << user->getName() << std::endl;
            index++;
        }
    }
}

void Dict::saveToFile(const std::string& filename) {
    std::ofstream outFile(filename, std::ofstream::trunc);
    if (outFile.is_open()) {
        for (const auto& user : users) {
            outFile << user->serialize() << std::endl;
        }
        outFile.close();
    }
}

void Dict::loadFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        std::string line;
        while (std::getline(inFile, line)) {
            std::stringstream ss(line);
            std::string role;
            std::getline(ss, role, ',');

            Users* user = nullptr;

            if (role == "admin") {
                user = new Admin();
            } else if (role == "defuser") {
                user = new DefUser();
            }

            if (user) {
                user->deserialize(line);
                users.push_back(user);
            }
        }
        inFile.close();
    }
}

const std::list<Users*>& Dict::getUsers() const {
    return users;
}
