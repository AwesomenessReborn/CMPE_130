// Student.cpp
#include "Student.hpp"

Student::Student() : id(0), lastName(""), firstName(""), academicStanding("") {}
Student::Student(int id, const std::string& lastName, const std::string& firstName, const std::string& academicStanding)
    : id(id), lastName(lastName), firstName(firstName), academicStanding(academicStanding) {}

int Student::getId() const { return id; }
std::string Student::getLastName() const { return lastName; }
std::string Student::getFirstName() const { return firstName; }
std::string Student::getAcademicStanding() const { return academicStanding; }

void Student::setId(int id) { this->id = id; }
void Student::setLastName(const std::string& lastName) { this->lastName = lastName; }
void Student::setFirstName(const std::string& firstName) { this->firstName = firstName; }
void Student::setAcademicStanding(const std::string& academicStanding) { this->academicStanding = academicStanding; }

void Student::printStudent() const {
    std::cout << id << " " << lastName << " " << firstName << " " << academicStanding << std::endl;
}

bool Student::operator>(const Student& other) const {
    return id > other.id;
}

bool Student::operator<(const Student& other) const {
    return id < other.id;
}
