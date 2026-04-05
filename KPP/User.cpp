#include "User.h"

void User::printInfo() {
    std::cout << firstName << " " << lastName << ", возраст: " << age << std::endl;
}

void User::authenticate() {
    if (!(login.empty() || password.empty())) {
        std::cout << "Проверка пройдена" << std::endl;
    }
    else {
        std::cout << "Ошибка: логин или пароль пусты" << std::endl;
    }
}

std::string User::getRole() {
    return "Unknown";
}