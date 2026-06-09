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

void test_user_roles() {
    assert(validate_user_role("admin") == true);
    assert(validate_user_role("mechanic") == true);
    assert(validate_user_role("guest") == false);
}

void test_plate_numbers() {
    assert(is_plate_number_valid("A123AA") == true);
    assert(is_plate_number_valid("") == false);
    assert(is_plate_number_valid("VERY_LONG_PLATE") == false);
}

void test_repair_costs() {
    assert(calculate_repair_total(1000.0, 100.0) == 900.0);
    assert(calculate_repair_total(500.0, 0.0) == 500.0);
    assert(calculate_repair_total(-50.0, 10.0) == 0.0);
}

int main() {
    std::cout << "Starting tests..." << std::endl;
    test_user_roles();
    test_plate_numbers();
    test_repair_costs();
    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}
