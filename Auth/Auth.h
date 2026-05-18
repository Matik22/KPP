#pragma once
#include "MyArray/MyArray.h"
#include "User/User.h"

class Auth {
public:
    Auth(const MyArray<User*>& users) : m_users(users), m_currentUser(nullptr) {}

    bool login();
    bool isAuthenticated();
    User* getCurrentUser();
    void logout();

private:
    MyArray<User*> m_users;
    User* m_currentUser;
};
