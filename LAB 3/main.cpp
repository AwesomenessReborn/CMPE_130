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

    // Print unsorted list
    std::cout << "Unsorted List:" << std::endl;
    db.printList();

    // Perform merge sort on the list
    db.mergeSort();

    // Print sorted list
    std::cout << "\nSorted List:" << std::endl;
    db.printList();

    return 0;
}
