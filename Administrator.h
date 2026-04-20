#pragma once
#include "User.h"

class Administrator : public User {
private:
    int accessLevel;     
    std::string department;

public:
    Administrator(std::string fN, std::string lN, int a,
        std::string l, std::string pa,
        int lvl, std::string dep)
        : User(fN, lN, a, l, pa), accessLevel(lvl), department(dep) {
    }

    int getAccessLevel() const { return accessLevel; }
    std::string getDepartment() const { return department; }

    void setAccessLevel(int lvl) { accessLevel = lvl; }
    void setDepartment(std::string dep) { department = dep; }

    void printInfo() override;
    void authenticate() override;
    std::string getRole() override;
};