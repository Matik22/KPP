#include "Photographer.h"

void Photographer::printInfo() {
    User::printInfo();
    std::cout << "Специализация: " << specialization
        << ", Рейтинг: " << rating << std::endl;
}

void Photographer::authenticate() {
    User::authenticate();
}

std::string Photographer::getRole() {
    return "Photographer";
}

std::ostream& operator<<(std::ostream& os, const Photographer& p) {
    os << p.firstName << " " << p.lastName;
	return os;
};

std::istream& operator>>(std::istream& is, Photographer& p) {
    std::cout << "Введите имя: ";
    is >> p.firstName;
    std::cout << "Введите фамилию: ";
    is >> p.lastName;
    std::cout << "Введите возраст: ";
    is >> p.age;
    std::cout << "Введите специализацию: ";
    is >> p.specialization;
    std::cout << "Введите рейтинг: ";
    is >> p.rating;
    return is;
};

bool Photographer::operator==(const Photographer& other) const {
	return rating == other.rating;
};

bool Photographer::operator<(const Photographer& other) const {
    return rating < other.rating;
};

bool Photographer::operator>(const Photographer& other) const {
    return rating > other.rating;
};