#include "Auth/Auth.h"

#include <iostream>
#include <string>

bool Auth::login() {
    while (true) {
        std::string login;
        std::cout << "=== Авторизация ===" << std::endl;
        std::cout << "Введите логин: ";
        std::cin >> login;

        if (login == "0") {
            return false;
        }

        User* found = nullptr;
        for (auto it : users) {
            if (login == it->getLogin()) {
                found = it;
                break;
            }
        }

        if (!found) {
            std::cout << "Неверный логин!" << std::endl;
            continue;
        }

        std::string password;
        std::cout << "Пароль: ";
        std::cin >> password;

        if (password == found->getPassword()) {
            currentUser = found;
            std::cout << "Добро пожаловать, " << currentUser->getFirstName() << "!" << std::endl;
            return true;
        } else {
            std::cout << "Неверный пароль!" << std::endl;
        }
    }
}

bool Auth::isAuthenticated() {
    return currentUser != nullptr;
}

User* Auth::getCurrentUser() {
    return currentUser;
}

void Auth::logout() {
    currentUser = nullptr;
}