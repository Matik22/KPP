#include "Administrator.h"

void Administrator::printInfo() {
    User::printInfo();
    std::cout << "Отдел: " << department
        << ", Уровень доступа: " << accessLevel << std::endl;
}

std::string Administrator::getRole() {
    return "Administrator";
}