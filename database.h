#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include <string>
#include <unordered_map>

/**
 * @struct Record
 * @brief Structure to hold individual record data.
 *
 * This structure represents a single record with an ID, name, and age.
 */
struct Record {
    int id;             ///< Record ID
    std::string name;   ///< Record name
    int age;            ///< Record age

    /**
     * @brief Constructor to initialize a record.
     * @param id The record ID.
     * @param name The record name.
     * @param age The record age.
     */
    Record(int id, std::string name, int age);
};

/**
 * @class Table
 * @brief Class to manage a collection of records.
 *
 * This class provides functionality to insert, query, update, remove, display,
 * save, and load records.
 */
class Table {
private:
    std::vector<Record> records;                 ///< Vector to store records
    std::unordered_map<int, size_t> index;       ///< Map for quick lookup by ID
    std::string filename;                        ///< Filename for saving/loading records

public:
    /**
     * @brief Constructor to initialize the table with a file.
     * @param filename The name of the file for persistence.
     */
    Table(const std::string &filename);

    /**
     * @brief Destructor to save records to the file.
     */
    ~Table();

    /**
     * @brief Insert a new record.
     * @param id The record ID.
     * @param name The record name.
     * @param age The record age.
     */
    void insert(int id, const std::string &name, int age);

    /**
     * @brief Query a record by ID.
     * @param id The record ID.
     * @return Pointer to the record, or nullptr if not found.
     */
    Record* query(int id);

    /**
     * @brief Update an existing record.
     * @param id The record ID.
     * @param name The new record name.
     * @param age The new record age.
     */
    void update(int id, const std::string &name, int age);

    /**
     * @brief Remove a record by ID.
     * @param id The record ID.
     */
    void remove(int id);

    /**
     * @brief Display all records.
     */
    void display();

    /**
     * @brief Save records to the file.
     */
    void save();

    /**
     * @brief Load records from the file.
     */
    void load();
};

#endif // DATABASE_H
