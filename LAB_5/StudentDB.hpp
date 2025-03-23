#ifndef STUDENTDB_HPP
#define STUDENTDB_HPP

#include "Student.hpp"
#include <list>
#include <iostream>

class StudentDB {
private:
    static const int TABLE_SIZE = 1000;
    std::list<Student> table[TABLE_SIZE];

    // Custom hash function that can cause collisions
    int hashFunction(const Student& student) const;

public:
    StudentDB();
    ~StudentDB();

    void insert(const Student& student);
    bool search(int id) const;
    bool remove(int id);
    void printAll() const;
};

#endif // STUDENTDB_HPP
