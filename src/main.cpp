#include <iostream>
#include <string>
#include "../includes/auth.h"
#include "../includes/db.h"

int main() {
    std::string username, password, role;
    std::cout << "=== Workshop KIS System ===" << std::endl;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    if (!authenticate_user(username, password, role)) {
        std::cout << "Access denied. Invalid credentials." << std::endl;
        return 1;
    }

    std::cout << "Authenticated successfully as: " << role << std::endl;
    int choice = 0;

    while (true) {
        std::cout << "\n1. View Repairs\n2. Add Repair\n3. Save Car Image\n4. Exit\nChoose option: ";
        std::cin >> choice;

        if (choice == 1) {
            if (authorize_action(role, "read")) {
                read_repair_records();
            } else {
                std::cout << "Unauthorized action." << std::endl;
            }
        } else if (choice == 2) {
            if (authorize_action(role, "create")) {
                int id;
                std::string plate, status;
                double cost;
                std::cout << "Enter ID: "; std::cin >> id;
                std::cout << "Enter Plate: "; std::cin >> plate;
                std::cout << "Enter Cost: "; std::cin >> cost;
                std::cout << "Enter Status: "; std::cin >> status;
                create_repair_record(id, plate, cost, status);
            } else {
                std::cout << "Unauthorized action." << std::endl;
            }
        } else if (choice == 3) {
            if (authorize_action(role, "create")) {
                std::string filename;
                std::cout << "Enter image filename (e.g., car.bmp): ";
                std::cin >> filename;
                save_mock_image(filename);
            } else {
                std::cout << "Unauthorized action." << std::endl;
            }
        } else if (choice == 4) {
            break;
        }
    }
    return 0;
}
