#include <iostream>
#include <string>
#include <cassert>

bool validate_user_role(const std::string& role) {
    if (role == "admin") return true;
    if (role == "mechanic") return true;
    return false;
}

bool is_plate_number_valid(const std::string& plate) {
    if (plate.empty()) return false;
    if (plate.length() > 10) return false;
    return true;
}

double calculate_repair_total(double base_cost, double discount) {
    if (base_cost < 0 || discount < 0) return 0.0;
    return base_cost - discount;
}

int main() {
    std::cout << "Running automatic tests..." << std::endl;

    bool r1 = validate_user_role("admin");
    bool r2 = validate_user_role("mechanic");
    bool r3 = validate_user_role("guest");
    assert(r1 && r2 && !r3);

    bool p1 = is_plate_number_valid("A123AA");
    bool p2 = is_plate_number_valid("");
    bool p3 = is_plate_number_valid("VERY_LONG_PLATE");
    assert(p1 && !p2 && !p3);

    double c1 = calculate_repair_total(1000.0, 100.0);
    double c2 = calculate_repair_total(500.0, 0.0);
    double c3 = calculate_repair_total(-50.0, 10.0);
    assert(c1 == 900.0 && c2 == 500.0 && c3 == 0.0);

    std::cout << "All assertions passed!" << std::endl;
    return 0;
}
