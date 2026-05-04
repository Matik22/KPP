#include "Auth/Auth.h"
#include <iostream>
#include <string>

bool Auth::login() {
    while (true) {
        std::string login;
        std::cout << "=== Авторизация ===" << std::endl;
        std::cout << "Введите логин: ";
        std::cin >> login;

        if (login == "0") return false;

        User* found = nullptr;
        for (auto it : m_users) {
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
            m_currentUser = found;
            std::cout << "Добро пожаловать, " << m_currentUser->getFirstName() << "!" << std::endl;
            return true;
        } else {
            std::cout << "Неверный пароль!" << std::endl;
        }
    }
}

bool Auth::isAuthenticated() { return m_currentUser != nullptr; }
User* Auth::getCurrentUser() { return m_currentUser; }
void Auth::logout()          { m_currentUser = nullptr; }
