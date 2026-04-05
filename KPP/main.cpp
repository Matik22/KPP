#include <iostream>
#include <string>
#include "CMenu.h"
#include "CMenuItem.h"
#include "Photographer.h"
#include "Administrator.h"
#include "Photo.h"
#include <vector>

using namespace std;
using namespace XXX;

std::vector<Photographer> photographers = {
    {"Иван",  "Петров",  32, "ivan",  "pass123", "Портрет", 4.8},
    {"Олег",  "Сидоров", 25, "oleg",  "qwerty",  "Пейзаж",  3.5},
    {"Мария", "Козлова", 29, "maria", "abc123",  "Репортаж", 4.2},
};
int photographersCount = 3;

const int ADMINS_COUNT = 2;
Administrator admins[ADMINS_COUNT] = {
    {"Анна",  "Смирнова", 28, "anna",  "admin456", 3, "IT-отдел"},
    {"Пётр",  "Волков",   35, "petr",  "admin789", 2, "Архив"},
};

const int PHOTOS_COUNT = 3;
Photo photos[PHOTOS_COUNT] = {
    {"Закат на море",  "2024-06-15", "Иван Петров"},
    {"Горный пейзаж", "2024-07-20", "Олег Сидоров"},
    {"Портрет",       "2024-08-01", "Мария Козлова"},
};

int showPhotographer() {
    for (int i = 0; i < photographersCount; i++) {
        std::cout << i + 1 << ". " << photographers[i] << std::endl;
    }
    std::cout << std::endl;
    return 1;
}

int authPhotographer() {
    photographers[0].authenticate();
    return 2;
}

int rolePhotographer() {
    std::cout << "Роль: " << photographers[0].getRole() << std::endl;
    return 3;
}

int showAdmin() {
    for (int i = 0; i < ADMINS_COUNT; i++) {
        admins[i].printInfo();
    }
    return 4;
}

int authAdmin() {
    admins[0].authenticate();
    return 5;
}

int roleAdmin() {
    std::cout << "Роль: " << admins[0].getRole() << std::endl;
    return 6;
}

int showPhoto() {
    for (int i = 0; i < PHOTOS_COUNT; i++) {
        photos[i].printInfo();
    }
    return 7;
}

int inputPhotographer() {
    std::cin >> photographers[0];
    return 8;
}

int comparePhotographers() {
    if (photographers[0] == photographers[1])
        std::cout << "Рейтинги равны" << std::endl;
    else if (photographers[0] > photographers[1])
        std::cout << photographers[0].getFirstName() << " лучше" << std::endl;
    else
        std::cout << photographers[1].getFirstName() << " лучше" << std::endl;
    return 9;
}

int addPhotographer() {
    Photographer p{ "", "", 0, "", "", "", 0.0 };
    std::cin >> p;
    photographers.push_back(p);
    photographersCount++;
    return 10;
}

int deletePhotographer() {
    std::cout << "Введите номер для удаления (1-" << photographersCount << "): ";
    int idx;
    std::cin >> idx;
    idx--;
    if (idx < 0 || idx >= photographersCount) {
        std::cout << "Неверный номер!" << std::endl;
        return 11;
    }
    photographers.erase(photographers.begin() + idx);
    photographersCount--;
    std::cout << "Удалено!" << std::endl;
    return 11;
}

int sortPhotographers() {
    for (int i = 0; i < photographersCount - 1; i++) {
        for (int j = 0; j < photographersCount - i - 1; j++) {
            if (photographers[j] > photographers[j + 1]) {
                Photographer tmp = photographers[j];
                photographers[j] = photographers[j + 1];
                photographers[j + 1] = tmp;
            }
        }
    }
    std::cout << "Отсортировано по рейтингу!" << std::endl;
    return 12;
}

const int ITEMS_NUMBER = 12;

CMenuItem items[ITEMS_NUMBER]{
    CMenuItem{"Показать фотографов",          showPhotographer},
    CMenuItem{"Аутентификация фотографа",     authPhotographer},
    CMenuItem{"Роль фотографа",               rolePhotographer},
    CMenuItem{"Показать администраторов",     showAdmin},
    CMenuItem{"Аутентификация администратора",authAdmin},
    CMenuItem{"Роль администратора",          roleAdmin},
    CMenuItem{"Показать фотографии",          showPhoto},
    CMenuItem{"Ввод фотографа",               inputPhotographer},
    CMenuItem{"Сравнение фотографов",         comparePhotographers},
    CMenuItem{"Добавить фотографа",           addPhotographer},
    CMenuItem{"Удалить фотографа",            deletePhotographer},
    CMenuItem{"Сортировать фотографов",       sortPhotographers},
};
int main() {
    CMenu menu("Система управления фотографиями", items, ITEMS_NUMBER);
    while (menu.runCommand()) {};
    return 0;
}