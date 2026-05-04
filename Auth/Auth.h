#pragma once
#include <vector>
#include "User/User.h"

class Auth {
public:
    Auth(const std::vector<User*>& users) : m_users(users), m_currentUser(nullptr) {}

    bool login();
    bool isAuthenticated();
    User* getCurrentUser();
    void logout();

private:
    std::vector<User*> m_users;
    User* m_currentUser;
};
