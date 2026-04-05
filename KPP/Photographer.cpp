#include "Photographer.h"

void Photographer::printInfo() {
    User::printInfo();
    std::cout << "Специализация: " << specialization
        << ", Рейтинг: " << rating << std::endl;
}

void Photographer::authenticate() {
    User::authenticate();
}

std::string Photographer::getRole() {
    return "Photographer";
}