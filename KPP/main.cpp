#include <iostream>
#include <string>
#include "CMenu.h"
#include "CMenuItem.h"
#include "Photographer.h"
#include "Administrator.h"
#include "Photo.h"

using namespace std;
using namespace XXX;

Photographer photographer{ "Иван", "Петров", 32, "ivan", "pass123", "Портрет", 4.8 };
Administrator admin{ "Анна", "Смирнова", 28, "anna", "admin456", 3, "IT-отдел" };
Photo photo{ "Закат на море", "2024-06-15", "Иван Петров"};

int showPhotographer() {
    photographer.printInfo();
    return 1;
}
int authPhotographer() {
    photographer.authenticate();
    return 2;
}
int rolePhotographer() {
    std::cout << "Роль: " << photographer.getRole() << std::endl;
    return 3;
}

int showAdmin() {
    admin.printInfo();
    return 4;
}
int authAdmin() {
    admin.authenticate();
    return 5;
}
int roleAdmin() {
    std::cout << "Роль: " << admin.getRole() << std::endl;
    return 6;
}

int showPhoto() {
    photo.printInfo();
    return 7;
}

const int ITEMS_NUMBER = 7;

int main() {
    CMenuItem items[ITEMS_NUMBER]{
        CMenuItem{"Информация о фотографе",       showPhotographer},
        CMenuItem{"Аутентификация фотографа",     authPhotographer},
        CMenuItem{"Роль фотографа",               rolePhotographer},
        CMenuItem{"Информация об администраторе", showAdmin},
        CMenuItem{"Аутентификация администратора",authAdmin},
        CMenuItem{"Роль администратора",          roleAdmin},
        CMenuItem{"Информация о фотографии",      showPhoto},
    };

    CMenu menu("Система управления фотографиями", items, ITEMS_NUMBER);
    while (menu.runCommand()) {};
    return 0;
}