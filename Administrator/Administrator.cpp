#include "Administrator.h"

void Administrator::printInfo() {
    User::printInfo();
    std::cout << "Отдел: " << department
        << ", Уровень доступа: " << accessLevel << std::endl;
}

void Administrator::authenticate() {
    User::authenticate();
}

std::string Administrator::getRole() {
    return "Administrator";
}