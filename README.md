# Building-A-Database

A C++ project to implement a basic database with the functionalities to insert, query, update, remove, display, save, and load records. This project also includes a test file to demonstrate the usage of the database.

## Table of Contents
- [Features](#features)
- [Installation & Usage](#installation--usage)

## Features

- Insert new records into the database
- Query records by ID
- Update existing records
- Remove records by ID
- Display all records
- Save records to a file for persistence
- Load records from a file

## Installation & Usage

1. **Clone the Repository**:
    ```bash
    git clone https://github.com/evinbsc/Building-A-Database.git
    cd Building-A-Database
    ```

2. **Compile the Project**:
    Ensure you have a C++ compiler installed (e.g., g++ or clang).

    ```bash
    g++ -std=c++11 -o test_database src/database.cpp src/test_database.cpp
    ```

3. **Run the Test Executable**:
    ```bash
    ./test_database
    ```
