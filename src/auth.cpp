#include "../includes/auth.h"

bool authenticate_user(const std::string& username, const std::string& password, std::string& role) {
    if (username == "admin" && password == "admin123") {
        role = "admin";
        return true;
    }
    if (username == "mechanic" && password == "mech123") {
        role = "mechanic";
        return true;
    }
    return false;
}

bool authorize_action(const std::string& role, const std::string& action) {
    if (role == "admin") return true;
    if (role == "mechanic") {
        if (action == "read" || action == "create") return true;
    }
    return false;
}
