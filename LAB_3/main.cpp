#include "Student.hpp"
#include "StudentDLinkDB.hpp"
#include <iostream>

int main() {
    // Create a doubly linked list database
    StudentDLinkDB db;

    // Add students to the list
    db.addStudent(3, "Smith", "John", "Good");
    db.addStudent(1, "Doe", "Jane", "Excellent");
    db.addStudent(4, "Brown", "Charlie", "Average");
    db.addStudent(2, "Taylor", "Alice", "Poor");

    // unsorted
    std::cout << "Unsorted List:" << std::endl;
    db.printList();

    db.mergeSort();

    // sorted
    std::cout << "\nSorted List:" << std::endl;
    db.printList();
    
    std::cout << "\n\n" << std::endl; 

    // TEST 2 -- input file
    StudentDLinkDB fileDb; 
    fileDb.readFromFile("students.txt"); 

    // unsorted
    std::cout << "Unsorted List:" << std::endl;
    fileDb.printList(); 

    fileDb.mergeSort(); 

    // sorted
    std::cout << "\nSorted List:" << std::endl;
    fileDb.printList(); 

    return 0;
}
