#include "Photo.h"

void Photo::printInfo() {
    std::cout << "Название: " << title
        << "\nДата: " << date
        << "\nАвтор: " << author << std::endl;
}