#include "User.h"

void User::printInfo() {
    std::cout << firstName << " " << lastName << ", возраст: " << age << std::endl;
}

std::string User::getRole() {
    return "Unknown";
}