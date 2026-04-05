#pragma once
#include <string>
#include <iostream>

class Photo {
private:
    std::string title;
    std::string date;
    std::string author;

public:
    Photo(std::string t, std::string d,
        std::string auth)
        : title(t), date(d), author(auth) {
    }

    std::string getTitle() const { return title; }
    std::string getDate() const { return date; }
    std::string getAuthor() const { return author; }

    void setTitle(std::string t) { title = t; }
    void setDate(std::string d) { date = d; }
    void setAuthor(std::string a) { author = a; }

    void printInfo();
};