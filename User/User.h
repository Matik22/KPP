#pragma once
#include <string>
#include <iostream>
#include "../MyArray/IContainable/IContainable.h"

class User : public IContainable {
protected:
    std::string firstName;
    std::string lastName;
    int age;
    std::string login;
    std::string password;

    User() = default;
    User(std::string fN, std::string lN, int a, std::string l, std::string p)
        : firstName(fN), lastName(lN), age(a), login(l), password(p) {}

public:
    virtual ~User() = default;

    std::string getFirstName() const { return firstName; }
    std::string getLastName() const { return lastName; }
    int getAge() const { return age; }
    std::string getLogin() const { return login; }
    std::string getPassword() const { return password; }

    void printInfo() { std::cout << firstName << " " << lastName << ", Age: " << age << ", Login: " << login << std::endl; }
    virtual std::string getRole() = 0;

    bool isLessThan(const IContainable& other) const override {
        const User* u = dynamic_cast<const User*>(&other);
        return u && (lastName + firstName) < (u->lastName + u->firstName);
    }
};