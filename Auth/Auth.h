#pragma once

#include "User/User.h"
#include "MyArray/MyArray.h"

class Auth {
public:
    Auth(const MyArray<User*>& users) : users(users), currentUser(nullptr) {}

    bool login();
    bool isAuthenticated();
    User* getCurrentUser();
    void logout();

private:
    MyArray<User*> users;
    User* currentUser;
};