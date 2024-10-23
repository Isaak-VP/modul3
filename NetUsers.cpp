#include "NetUsers.hpp"
#include <sstream>


Users::Users() = default;

Users::Users(const std::string& name, const std::string& role)
    : name(name), role(role) {}

std::string Users::getName() const {
    return name;
}

std::string Users::getRole() const {
    return role;
}


Admin::Admin() = default;

Admin::Admin(const std::string& name, int yearsOfExperience)
    : Users(name, "Admin"), yearsOfExperience(yearsOfExperience) {}

std::string Admin::serialize() const {
    return "admin," + name + "," + std::to_string(yearsOfExperience);
}

void Admin::deserialize(const std::string& data) {
    std::stringstream ss(data);
    std::string role, expStr;
    
    std::getline(ss, role, ',');  
    std::getline(ss, name, ',');
    std::getline(ss, expStr, ',');
    
    yearsOfExperience = std::stoi(expStr);
}

int Admin::getYearsOfExperience() const {
    return yearsOfExperience;
}


DefUser::DefUser() = default;

DefUser::DefUser(const std::string& name, const std::string& registrationDate)
    : Users(name, "User"), registrationDate(registrationDate) {}

std::string DefUser::serialize() const {
    return "defuser," + name + "," + registrationDate;
}

void DefUser::deserialize(const std::string& data) {
    std::stringstream ss(data);
    std::string role;
    
    std::getline(ss, role, ',');  
    std::getline(ss, name, ',');
    std::getline(ss, registrationDate, ',');
}

std::string DefUser::getRegistrationDate() const {
    return registrationDate;
}
