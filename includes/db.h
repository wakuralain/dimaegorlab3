#ifndef DB_H
#define DB_H
#include <string>

void create_repair_record(int id, const std::string& plate, double cost, const std::string& status);
void read_repair_records();
void save_mock_image(const std::string& filename);

#endif
