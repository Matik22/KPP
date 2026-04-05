#include "Employee.h"

void Employee::printInfo() {
    User::printInfo();
    std::cout << "Должность: " << position << std::endl;
}

void Employee::authenticate() {
    User::authenticate();
}

std::string Employee::getRole() {
    return "Employee";
}