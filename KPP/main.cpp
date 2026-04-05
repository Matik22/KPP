#include <iostream>
#include <string>
#include "CMenu.h"
#include "CMenuItem.h"
#include "Employee.h"
#include "Client.h"
#include "Service.h"

using namespace std;
using namespace XXX;

Employee employee{ "Матвей", "Иванов", 30, "matvey", "1234", "Механик" };
Client client{ "Никита", "Петров", 25, "nikita", "5678", "Ремонт велосипеда" };
Service service{ "Ремонт велосипеда", 1500.0, "Полный ремонт велосипеда с заменой деталей" };

int showEmployee() {
    employee.printInfo();
    return 1;
}

int authEmployee() {
    employee.authenticate();
    return 2;
}

int roleEmployee() {
    std::cout << "Роль: " << employee.getRole() << std::endl;
    return 3;
}

int showClient() {
    client.printInfo();
    return 4;
}

int authClient() {
    client.authenticate();
    return 5;
}

int roleClient() {
    std::cout << "Роль: " << client.getRole() << std::endl;
    return 6;
}

int showService() {
    service.printInfo();
    return 7;
}

int f5() {
    std::cout << "." << std::endl;
    std::cout << "┊┊┊┊┊┊╱▔▔╲▔▔╲" << std::endl;
    std::cout << "┊╱▔▔▔▔▏┊┊┊┈╭╮" << std::endl;
    std::cout << "╭▏  ┈┈┈┈▏┊┊┊┈┈┈╲" << std::endl;
    std::cout << "┋   ┈┈┈┈╲▂▂╱┈╰┈┊▏" << std::endl;
    std::cout << "╯┃ ┈┈┈┈┈┈┈┈ ╭▔▔▏▏" << std::endl;
    std::cout << "┊┃┈┈┈┣┫┈┈┈┃  ┊┊▏▏" << std::endl;
    std::cout << "┈┃╭┳┳┫┃╭┳┳┫┈  ╱╱" << std::endl;
    std::cout << "┈╰┻┻┻╯╰┻┻┻╯┈▔" << std::endl;
    return 8;
}

int f6() {
    string name{};
    std::cout << "Введите имя" << std::endl;
    std::cin >> name;
    std::cout << "Добро пожаловать, " << name << endl;
    return 9;
}

const int ITEMS_NUMBER = 9;

int main() {

    CMenuItem items[ITEMS_NUMBER]{
        CMenuItem{"Информация о сотруднике", showEmployee},
        CMenuItem{"Аутентификация сотрудника", authEmployee},
        CMenuItem{"Роль сотрудника", roleEmployee},
        CMenuItem{"Информация о клиенте", showClient},
        CMenuItem{"Аутентификация клиента", authClient},
        CMenuItem{"Роль клиента", roleClient},
        CMenuItem{"Информация об услуге", showService},
        CMenuItem{"Слоник", f5},
        CMenuItem{"Приветствие", f6}
    };

    CMenu menu("Система управления", items, ITEMS_NUMBER);
    while (menu.runCommand()) {};

    return 0;
}