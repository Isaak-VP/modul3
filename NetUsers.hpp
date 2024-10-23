#ifndef NETUSERS_HPP
#define NETUSERS_HPP

#include <string>

// Базовий клас Users
class Users {
protected:
    std::string name;
    std::string role;

public:
    Users();
    Users(const std::string& name, const std::string& role);
    virtual ~Users() = default;

    virtual std::string serialize() const = 0;  
    virtual void deserialize(const std::string& data) = 0;

    std::string getName() const;
    std::string getRole() const;
};

// Клас Admin, похідний від Users
class Admin : public Users {
private:
    int yearsOfExperience;

public:
    Admin();
    Admin(const std::string& name, int yearsOfExperience);
    
    std::string serialize() const override;
    void deserialize(const std::string& data) override;

    int getYearsOfExperience() const;
};

// Клас DefUser (Звичайний користувач), похідний від Users
class DefUser : public Users {
private:
    std::string registrationDate;

public:
    DefUser();
    DefUser(const std::string& name, const std::string& registrationDate);
    
    std::string serialize() const override;
    void deserialize(const std::string& data) override;

    std::string getRegistrationDate() const;
};

#endif 
