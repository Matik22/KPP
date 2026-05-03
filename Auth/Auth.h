#pragma once

#include "User/User.h"
#include <vector>

class Auth {
public:
    Auth(std::vector<User*> users) : users(users), currentUser(nullptr) {}

    bool login();
    bool isAuthenticated();
    User* getCurrentUser();
    void logout();

private:
    std::vector<User*> users;
    User* currentUser;
};
