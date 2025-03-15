// Student.hpp
#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>
#include <string>

class Student {
private:
    int id;
    std::string lastName;
    std::string firstName;
    std::string academicStanding;
public:
    Student();

    Student *next, *prev; 

    Student(int id, const std::string& lastName, const std::string& firstName, const std::string& academicStanding);

    int getId() const;
    std::string getLastName() const;
    std::string getFirstName() const;
    std::string getAcademicStanding() const;

    void setId(int id);
    void setLastName(const std::string& lastName);
    void setFirstName(const std::string& firstName);
    void setAcademicStanding(const std::string& academicStanding);

    void printStudent() const;

    bool operator>(const Student& other) const;
    
    bool operator<(const Student& other) const; 
};

#endif // STUDENT_HPP