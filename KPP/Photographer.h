#pragma once
#include "User.h"

class Photographer : public User {
private:
    std::string specialization;
    double rating;

public:
    Photographer(std::string fN, std::string lN, int a,
        std::string l, std::string pa,
        std::string spec, double rat)
        : User(fN, lN, a, l, pa), specialization(spec), rating(rat) {
    }

    std::string getSpecialization() const { return specialization; }
    double getRating() const { return rating; }
    void setSpecialization(std::string s) { specialization = s; }
    void setRating(double r) { rating = r; }

    void printInfo() override;
    void authenticate() override;
    std::string getRole() override;

    friend std::ostream& operator<<(std::ostream& os, const Photographer& p);
    friend std::istream& operator>>(std::istream& is, Photographer& p);

    bool operator==(const Photographer& other) const;
    bool operator<(const Photographer& other) const;
	bool operator>(const Photographer& other) const;
};