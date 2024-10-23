#ifndef DICT_HPP
#define DICT_HPP

#include <list>
#include <string>
#include "NetUsers.hpp"

class Dict {
private:
    std::list<Users*> users;

public:
    ~Dict();
    void addUser(Users* user);
    void deleteUser(int index);
    void viewUsers() const;
    void saveToFile(const std::string& filename);
    void loadFromFile(const std::string& filename);
    const std::list<Users*>& getUsers() const;
};

#endif
