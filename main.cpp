#include <iostream>
#include <string>
#include <vector>
#include "Menu/CMenu.h"
#include "Menu/CMenuItem.h"
#include "Photographer/Photographer.h"
#include "Administrator/Administrator.h"
#include "Photo/Photo.h"
#include "Auth/Auth.h"
#include "MyArray/MyArray.h"

using namespace std;
using namespace XXX;

// MyArray только для Photo
MyArray photos;

// Все остальные — std::vector
vector<Photographer> photographers;
vector<Administrator> admins;
vector<CMenuItem>    items;

// Прототипы функций
int showPhotographer();
int rolePhotographer();
int showAdmin();
int roleAdmin();
int showPhoto();
int inputPhotographer();
int comparePhotographers();
int addPhotographer();
int deletePhotographer();
int sortPhotographers();

void initializeData() {
    photographers.push_back(Photographer("Иван",  "Петров",  32, "ivan",  "pass123",  "Портрет",   4.8));
    photographers.push_back(Photographer("Олег",  "Сидоров", 25, "oleg",  "qwerty",   "Пейзаж",    3.5));
    photographers.push_back(Photographer("Мария", "Козлова", 29, "maria", "abc123",   "Репортаж",  4.2));

    admins.push_back(Administrator("Анна", "Смирнова", 28, "anna", "admin456", 3, "IT-отдел"));
    admins.push_back(Administrator("Пётр", "Волков",   35, "petr", "admin789", 2, "Архив"));

    photos.add(Photo("Закат на море",  "2024-06-15", "Иван Петров"));
    photos.add(Photo("Горный пейзаж",  "2024-07-20", "Олег Сидоров"));
    photos.add(Photo("Портрет",        "2024-08-01", "Мария Козлова"));

    items.push_back(CMenuItem{"Показать фотографов",   showPhotographer});
    items.push_back(CMenuItem{"Роль фотографа",         rolePhotographer});
    items.push_back(CMenuItem{"Показать администраторов", showAdmin});
    items.push_back(CMenuItem{"Роль администратора",    roleAdmin});
    items.push_back(CMenuItem{"Показать фотографии",    showPhoto});
    items.push_back(CMenuItem{"Ввод фотографа",         inputPhotographer});
    items.push_back(CMenuItem{"Сравнение фотографов",   comparePhotographers});
    items.push_back(CMenuItem{"Добавить фотографа",     addPhotographer});
    items.push_back(CMenuItem{"Удалить фотографа",      deletePhotographer});
    items.push_back(CMenuItem{"Сортировать фотографов", sortPhotographers});
}

int showPhotographer() {
    for (int i = 0; i < (int)photographers.size(); i++)
        std::cout << i + 1 << ". " << photographers[i] << std::endl;
    std::cout << std::endl;
    return 1;
}

int rolePhotographer() {
    std::cout << "Роль: " << photographers[0].getRole() << std::endl;
    return 2;
}

int showAdmin() {
    for (auto& a : admins)
        a.printInfo();
    return 3;
}

int roleAdmin() {
    std::cout << "Роль: " << admins[0].getRole() << std::endl;
    return 4;
}

int showPhoto() {
    for (int i = 0; i < photos.getSize(); i++)
        photos.get(i).printInfo();
    return 5;
}

int inputPhotographer() {
    std::cin >> photographers[0];
    return 6;
}

int comparePhotographers() {
    if (photographers[0] == photographers[1])
        std::cout << "Рейтинги равны" << std::endl;
    else if (photographers[0] > photographers[1])
        std::cout << photographers[0].getFirstName() << " лучше" << std::endl;
    else
        std::cout << photographers[1].getFirstName() << " лучше" << std::endl;
    return 7;
}

int addPhotographer() {
    Photographer p{"", "", 0, "", "", "", 0.0};
    std::cin >> p;
    photographers.push_back(p);
    return 8;
}

int deletePhotographer() {
    std::cout << "Введите номер для удаления (1-" << photographers.size() << "): ";
    int idx;
    std::cin >> idx;
    idx--;
    if (idx < 0 || idx >= (int)photographers.size()) {
        std::cout << "Неверный номер!" << std::endl;
        return 9;
    }
    photographers.erase(photographers.begin() + idx);
    std::cout << "Удалено!" << std::endl;
    return 9;
}

int sortPhotographers() {
    std::sort(photographers.begin(), photographers.end());
    std::cout << "Отсортировано по рейтингу!" << std::endl;
    return 10;
}

int main() {
    initializeData();

    vector<User*> allUsers;
    for (auto& p : photographers) allUsers.push_back(&p);
    for (auto& a : admins)        allUsers.push_back(&a);

    Auth auth(allUsers);
    if (!auth.login()) return 0;

    CMenu menu("Система управления фотографиями", items.data(), items.size());
    while (menu.runCommand()) {}
    return 0;
}
