#pragma once
#include <string>
#include <iostream>

class Service {
private:
    std::string name;
    double price;
    std::string description;
public:
    Service(std::string n, double p, std::string d) :
        name(n), price(p), description(d) {
    }

    std::string getName() const {
        return name;
    }

    double getPrice() const {
        return price;
    }

    std::string getDescription() const {
        return description;
    }

    void printInfo();
};