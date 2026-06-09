#include "../includes/db.h"
#include <iostream>
#include <fstream>
#include <vector>

void create_repair_record(int id, const std::string& plate, double cost, const std::string& status) {
    std::ofstream file("bin/repairs.txt", std::ios::app);
    if (file.is_open()) {
        file << id << " " << plate << " " << cost << " " << status << "\n";
        file.close();
        std::cout << "Record saved successfully." << std::endl;
    }
}

void read_repair_records() {
    std::ifstream file("bin/repairs.txt");
    if (!file.is_open()) {
        std::cout << "No records found." << std::endl;
        return;
    }
    int id;
    std::string plate;
    double cost;
    std::string status;
    std::cout << "\n--- Repair List ---" << std::endl;
    while (file >> id >> plate >> cost >> status) {
        std::cout << "ID: " << id << " | Plate: " << plate << " | Cost: " << cost << " | Status: " << status << std::endl;
    }
    file.close();
}

void save_mock_image(const std::string& filename) {
    std::ofstream file("bin/" + filename, std::ios::binary);
    if (file.is_open()) {
        unsigned char bmp_pad[3] = {0, 0, 0};
        for (int i = 0; i < 10; i++) {
            file.write((char*)bmp_pad, 3);
        }
        file.close();
        std::cout << "Mock image saved to bin/" << filename << std::endl;
    }
}
