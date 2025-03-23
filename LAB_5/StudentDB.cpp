#include "StudentDB.hpp"

int StudentDB::hashFunction(const Student& student) const {
    return student.getId() % TABLE_SIZE;
}

StudentDB::StudentDB() {}

StudentDB::~StudentDB() {}

void StudentDB::insert(const Student& student) {
    int index = hashFunction(student);
    table[index].push_back(student);
}

bool StudentDB::search(int id) const {
    int index = id % TABLE_SIZE; // Use the same hash function logic for simplicity
    for (const auto& student : table[index]) {
        if (student.getId() == id) {
            return true;
        }
    }
    return false;
}

// Delete a student by ID
bool StudentDB::remove(int id) {
    int index = id % TABLE_SIZE; // Use the same hash function logic for simplicity
    for (auto it = table[index].begin(); it != table[index].end(); ++it) {
        if (it->getId() == id) {
            table[index].erase(it);
            return true;
        }
    }
    return false;
}

void StudentDB::printAll() const {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        if (!table[i].empty()) {
            std::cout << "Bucket " << i << ":\n";
            for (const auto& student : table[i]) {
                student.printStudent();
            }
        }
    }
}

