#include "database.h"
#include <iostream>
#include <fstream>

/**
 * @brief Constructor to initialize a record.
 * @param id The record ID.
 * @param name The record name.
 * @param age The record age.
 */
Record::Record(int id, std::string name, int age) : id(id), name(name), age(age) {}

/**
 * @brief Constructor to initialize the table with a file.
 * @param filename The name of the file for persistence.
 */
Table::Table(const std::string &filename) : filename(filename) {
    load();
}

/**
 * @brief Destructor to save records to the file.
 */
Table::~Table() {
    save();
}

/**
 * @brief Insert a new record.
 * @param id The record ID.
 * @param name The record name.
 * @param age The record age.
 */
void Table::insert(int id, const std::string &name, int age) {
    if (index.find(id) != index.end()) {
        std::cerr << "Error: Duplicate ID" << std::endl;
        return;
    }
    records.emplace_back(id, name, age);
    index[id] = records.size() - 1;
}

/**
 * @brief Query a record by ID.
 * @param id The record ID.
 * @return Pointer to the record, or nullptr if not found.
 */
Record* Table::query(int id) {
    auto it = index.find(id);
    if (it != index.end()) {
        return &records[it->second];
    }
    return nullptr;
}

/**
 * @brief Update an existing record.
 * @param id The record ID.
 * @param name The new record name.
 * @param age The new record age.
 */
void Table::update(int id, const std::string &name, int age) {
    auto it = index.find(id);
    if (it != index.end()) {
        records[it->second].name = name;
        records[it->second].age = age;
    } else {
        std::cerr << "Error: Record not found" << std::endl;
    }
}

/**
 * @brief Remove a record by ID.
 * @param id The record ID.
 */
void Table::remove(int id) {
    auto it = index.find(id);
    if (it != index.end()) {
        records.erase(records.begin() + it->second);
        index.erase(it);
        // Rebuild index
        for (size_t i = 0; i < records.size(); ++i) {
            index[records[i].id] = i;
        }
    } else {
        std::cerr << "Error: Record not found" << std::endl;
    }
}

/**
 * @brief Display all records.
 */
void Table::display() {
    for (const auto &record : records) {
        std::cout << "ID: " << record.id << ", Name: " << record.name << ", Age: " << record.age << std::endl;
    }
}

/**
 * @brief Save records to the file.
 */
void Table::save() {
    std::ofstream file(filename, std::ios::binary);
    for (const auto &record : records) {
        file.write(reinterpret_cast<const char*>(&record.id), sizeof(record.id));
        size_t name_size = record.name.size();
        file.write(reinterpret_cast<const char*>(&name_size), sizeof(name_size));
        file.write(record.name.c_str(), name_size);
        file.write(reinterpret_cast<const char*>(&record.age), sizeof(record.age));
    }
    file.close();
}

/**
 * @brief Load records from the file.
 */
void Table::load() {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) return;

    while (!file.eof()) {
        int id;
        size_t name_size;
        std::string name;
        int age;

        file.read(reinterpret_cast<char*>(&id), sizeof(id));
        file.read(reinterpret_cast<char*>(&name_size), sizeof(name_size));
        name.resize(name_size);
        file.read(&name[0], name_size);
        file.read(reinterpret_cast<char*>(&age), sizeof(age));

        if (file) {
            insert(id, name, age);
        }
    }
    file.close();
}
