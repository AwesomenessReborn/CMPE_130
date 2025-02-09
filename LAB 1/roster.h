#ifndef ROSTER_H
#define ROSTER_H

#include <iostream>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <string>

/**
 * Student Class
 */
class Student {
public:
    int id;
    std::string lastName;
    std::string firstName;
    std::string level;

    Student() = default;
    Student(int id, std::string last, std::string first, std::string lvl)
        : id(id), lastName(std::move(last)), firstName(std::move(first)), level(std::move(lvl)) {}

    std::string toString() const {
        return std::to_string(id) + ", " + lastName + ", " + firstName + ", " + level;
    }
};

/**
 * Roster Class
 */
class Roster {
private:
    std::unordered_map<int, Student> students;
    std::string filename;

public:
    Roster(const std::string& file) : filename(file) { loadFromFile(); }
    ~Roster() { saveToFile(); }

    void loadFromFile() {
        std::ifstream file(filename);
        if (!file) {
            std::cerr << "Error opening file: " << filename << std::endl;
            return;
        }

        std::string line;
        while (getline(file, line)) {
            std::istringstream ss(line);
            int id;
            std::string last, first, level;
            
            if (ss >> id && getline(ss, last, ',') && getline(ss, first, ',') && getline(ss, level, ',')) {
                students[id] = Student(id, last, first, level);
            }
        }
    }

    void saveToFile() {
        std::ofstream file(filename);
        if (!file) {
            std::cerr << "Error writing to file: " << filename << std::endl;
            return;
        }

        for (const auto& [id, student] : students) {
            file << student.toString() << std::endl;
        }
    }

    void addStudent(const Student& student) {
        students[student.id] = student;
        std::cout << "Added student: " << student.toString() << std::endl;
    }

    void dropStudent(int id) {
        if (students.erase(id)) {
            std::cout << "Dropped student ID " << id << std::endl;
        } else {
            std::cout << "Student not found." << std::endl;
        }
    }

    void updateStudent(int id, const std::string& last, const std::string& first, const std::string& level) {
        auto it = students.find(id);
        if (it != students.end()) {
            it->second = Student(id, last, first, level);
            std::cout << "Updated student ID " << id << std::endl;
        } else {
            std::cout << "Student not found." << std::endl;
        }
    }

    void listStudents() const {
        for (const auto& [id, student] : students) {
            std::cout << student.toString() << std::endl;
        }
    }
};

#endif
