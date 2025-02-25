// // StudentDLinkDB.hpp
// #ifndef STUDENTDLINKDB_HPP
// #define STUDENTDLINKDB_HPP

// #include <iostream>
// #include <string> 
// #include <Student.hpp>

// class StudentDLinkDB
// {
// private:
//     /* data */
//     int size; 
//     Student *head; 
// public:
//     StudentDLinkDB(/* args */);

//     void mergeSort(); 

//     ~StudentDLinkDB();
// };

// #endif

#ifndef STUDENTDLINKDB_HPP
#define STUDENTDLINKDB_HPP

#include "Student.hpp"

class StudentDLinkDB {
private:
    int size;
    Student* head;

    // Helper functions
    Student* split(Student* head);
    Student* merge(Student* left, Student* right);

    Student* mergeSortHelper(Student* node); 

public:
    StudentDLinkDB();
    void addStudent(int id, const std::string& lastName, const std::string& firstName, const std::string& academicStanding);
    void printList() const;
    void mergeSort();
    ~StudentDLinkDB();
};

#endif
