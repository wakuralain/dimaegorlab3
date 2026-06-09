#ifndef AUTH_H
#define AUTH_H
#include <string>

bool authenticate_user(const std::string& username, const std::string& password, std::string& role);
bool authorize_action(const std::string& role, const std::string& action);

#endif
