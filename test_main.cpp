#include <iostream>
#include <string>
#include <cassert>

bool validate_user_role(const std::string& role) {
    if (role == "admin") return true;
    if (role == "mechanic") return true;
    return false;
}

bool is_plate_valid(const std::string& plate) {
    if (plate.empty()) return false;
    if (plate.length() > 10) return false;
    return true;
}

double calc_total(double base, double discount) {
    if (base < 0) return 0.0;
    return base - discount;
}

int main() {
    assert(validate_user_role("admin") == true);
    assert(validate_user_role("mechanic") == true);
    assert(validate_user_role("guest") == false);

    assert(is_plate_valid("A123AA") == true);
    assert(is_plate_valid("") == false);
    assert(is_plate_valid("VERYLONGPLATE") == false);

    assert(calc_total(100.0, 10.0) == 90.0);
    assert(calc_total(50.0, 0.0) == 50.0);
    assert(calc_total(-10.0, 5.0) == 0.0);

    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}
