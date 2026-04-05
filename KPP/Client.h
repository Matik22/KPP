#pragma once
#include "User.h"

class Client : public User {
private:
    std::string service;
public:
    Client(std::string fN, std::string lN, int a, std::string l, std::string pa, std::string s) :
        User(fN, lN, a, l, pa), service(s) {
    }

    std::string getService() const {
        return service;
    }

    void printInfo() override;
    void authenticate() override;
    std::string getRole() override;
};