#include "database.h"
#include <iostream>

/**
 * @brief Function to run tests on the Table class.
 */
void runTests() {
    Table table("test_database.dat");

    // Insert records
    table.insert(1, "Evin", 18);
    table.insert(2, "Ev", 19);
    table.insert(3, "StClair", 20);
    std::cout << "Inserted records.\n";

    // Query a record
    Record *record = table.query(2);
    if (record) {
        std::cout << "Queried Record - ID: " << record->id << ", Name: " << record->name << ", Age: " << record->age << std::endl;
    } else {
        std::cout << "Record not found!" << std::endl;
    }

    // Update a record
    table.update(2, "Evin Updated", 21);
    record = table.query(2);
    if (record) {
        std::cout << "Updated Record - ID: " << record->id << ", Name: " << record->name << ", Age: " << record->age << std::endl;
    } else {
        std::cout << "Record not found!" << std::endl;
    }

    // Remove a record
    table.remove(1);
    std::cout << "Removed record with ID 1.\n";

    // Display all records
    std::cout << "All Records:" << std::endl;
    table.display();
}

/**
 * @brief Main function to run the tests.
 * @return 0 on success.
 */
int main() {
    runTests();
    return 0;
}
