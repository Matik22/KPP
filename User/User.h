#pragma once
#include <string>
#include <iostream>

class User {
protected:
    std::string firstName;
    std::string lastName;
    int age;
    std::string login;
    std::string password;

    User(std::string fN, std::string lN, int a, std::string l, std::string p)
        : firstName(fN), lastName(lN), age(a), login(l), password(p) {
    }

public:
    virtual ~User() = default;

    std::string getFirstName() const { return firstName; }
    std::string getLastName() const { return lastName; }
    int getAge() const { return age; }
    std::string getLogin() const { return login; }
    std::string getPassword() const { return password; }

    virtual void printInfo() = 0;
    virtual void authenticate() = 0;
    virtual std::string getRole() = 0;
};