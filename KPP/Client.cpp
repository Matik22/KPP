#include "Client.h"

void Client::printInfo() {
    User::printInfo();
    std::cout << "Услуга: " << service << std::endl;
}

void Client::authenticate() {
    User::authenticate();
}

std::string Client::getRole() {
    return "Client";
}