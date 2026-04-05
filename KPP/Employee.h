#pragma once
#include "User.h"

class Employee : public User {
private:
    std::string position;
public:
    Employee(std::string fN, std::string lN, int a, std::string l, std::string pa, std::string po) :
        User(fN, lN, a, l, pa), position(po) {
    }

    std::string getPosition() const {
        return position;
    }

    void printInfo() override;
    void authenticate() override;
    std::string getRole() override;
};