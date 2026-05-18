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

MyArray<Photo> photos;

MyArray<Photographer> photographers;
MyArray<Administrator> admins;
MyArray<CMenuItem>    items;

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
    photographers.add(Photographer("Иван",  "Петров",  32, "ivan",  "pass123",  "Портрет",   4.8));
    photographers.add(Photographer("Олег",  "Сидоров", 25, "oleg",  "qwerty",   "Пейзаж",    3.5));
    photographers.add(Photographer("Мария", "Козлова", 29, "maria", "abc123",   "Репортаж",  4.2));

    admins.add(Administrator("Анна", "Смирнова", 28, "anna", "admin456", 3, "IT-отдел"));
    admins.add(Administrator("Пётр", "Волков",   35, "petr", "admin789", 2, "Архив"));

    photos.add(Photo("Закат на море",  "2024-06-15", "Иван Петров"));
    photos.add(Photo("Горный пейзаж",  "2024-07-20", "Олег Сидоров"));
    photos.add(Photo("Портрет",        "2024-08-01", "Мария Козлова"));

    items.add(CMenuItem{"Показать фотографов",   showPhotographer});
    items.add(CMenuItem{"Роль фотографа",         rolePhotographer});
    items.add(CMenuItem{"Показать администраторов", showAdmin});
    items.add(CMenuItem{"Роль администратора",    roleAdmin});
    items.add(CMenuItem{"Показать фотографии",    showPhoto});
    items.add(CMenuItem{"Ввод фотографа",         inputPhotographer});
    items.add(CMenuItem{"Сравнение фотографов",   comparePhotographers});
    items.add(CMenuItem{"Добавить фотографа",     addPhotographer});
    items.add(CMenuItem{"Удалить фотографа",      deletePhotographer});
    items.add(CMenuItem{"Сортировать фотографов", sortPhotographers});
}

int showPhotographer() {
    for (int i = 0; i < (int)photographers.getSize(); i++)
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
    photographers.add(p);
    return 8;
}

int deletePhotographer() {
    std::cout << "Введите номер для удаления (1-" << photographers.getSize() << "): ";
    int idx;
    std::cin >> idx;
    idx--;
    if (idx < 0 || idx >= (int)photographers.getSize()) {
        std::cout << "Неверный номер!" << std::endl;
        return 9;
    }
    photographers.removeAt(idx);
    std::cout << "Удалено!" << std::endl;
    return 9;
}

int sortPhotographers() {
    photographers.sort();
    std::cout << "Отсортировано по рейтингу!" << std::endl;
    return 10;
}

int main() {
    initializeData();

    MyArray<User*> allUsers;
    for (auto& p : photographers) allUsers.add(&p);
    for (auto& a : admins)        allUsers.add(&a);

    Auth auth(allUsers);
    if (!auth.login()) return 0;

    CMenu menu("Система управления фотографиями", items.begin(), items.getSize());
    while (menu.runCommand()) {}
    return 0;
}
