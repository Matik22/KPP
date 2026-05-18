#pragma once
#include <string>
#include <iostream>
#include "../MyArray/IContainable/IContainable.h"

class Photo : public IContainable {
private:
    std::string title;
    std::string date;
    std::string author;

public:
    Photo(std::string t, std::string d,
        std::string auth)
        : title(t), date(d), author(auth) {
    }
    Photo() : title(""), date(""), author("") {}

    std::string getTitle() const { return title; }
    std::string getDate() const { return date; }
    std::string getAuthor() const { return author; }

    void setTitle(std::string t) { title = t; }
    void setDate(std::string d) { date = d; }
    void setAuthor(std::string a) { author = a; }

    void printInfo() {
        std::cout << title << " (" << date << ") от " << author << std::endl;
    }

    bool operator<(const Photo& other) const {
        return title < other.title;
    }

    bool isLessThan(const IContainable& other) const override {
        const Photo* p = dynamic_cast<const Photo*>(&other);
        return p && title < p->title;
    }
};