#include <iostream>
#include <string>
#include <vector>

struct Repair {
    std::string plate;
    double cost;
};

int main() {
    std::string plate;
    double cost, discount;

    std::cout << "=== Workshop Management System ===" << std::endl;
    
    std::cout << "Enter plate number: ";
    std::cin >> plate;
    
    std::cout << "Enter repair cost: ";
    std::cin >> cost;
    
    std::cout << "Enter discount: ";
    std::cin >> discount;

    if (plate.length() > 0 && plate.length() <= 10) {
        double total = cost - discount;
        std::cout << "--- Result ---" << std::endl;
        std::cout << "Plate: " << plate << std::endl;
        std::cout << "Total to pay: " << (total > 0 ? total : 0.0) << std::endl;
    } else {
        std::cerr << "Error: Invalid plate number format!" << std::endl;
    }

    return 0;
}
