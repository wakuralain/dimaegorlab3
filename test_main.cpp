#include <iostream>
#include <string>
#include <cassert>

bool validate_user_role(const std::string& role) {
    return (role == "admin" || role == "mechanic");
}

bool is_plate_number_valid(const std::string& plate) {
    return !plate.empty() && plate.length() <= 10;
}

double calculate_repair_total(double base_cost, double discount) {
    if (base_cost < 0 || discount < 0) return 0.0;
    return base_cost - discount;
}

void test_user_roles() {
    assert(validate_user_role("admin") == true);      
    assert(validate_user_role("mechanic") == true);    
    assert(validate_user_role("hacker") == false);     
    std::cout << "test_user_roles passed!" << std::endl;
}

void test_plate_numbers() {
    assert(is_plate_number_valid("A123AA") == true);   
    assert(is_plate_number_valid("") == false);        
    assert(is_plate_number_valid("VERY_LONG_PLATE_NUMBER") == false); 
    std::cout << "test_plate_numbers passed!" << std::endl;
}

void test_repair_costs() {
    assert(calculate_repair_total(1000.0, 100.0) == 900.0); 
    assert(calculate_repair_total(500.0, 0.0) == 500.0);    
    assert(calculate_repair_total(-50.0, 10.0) == 0.0);    
    std::cout << "test_repair_costs passed!" << std::endl;
}

int main() {
    std::cout << "Running tests..." << std::endl;
    test_user_roles();
    test_plate_numbers();
    test_repair_costs();
    std::cout << "All tests executed successfully!" << std::endl;
    return 0;
}
