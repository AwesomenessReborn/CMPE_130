
// std io imports
#include <numeric>
#include <stack> 
#include <bitset>
#include <map>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <array>
#include <iterator> 
#include <vector>
#include <ios>
#include <climits>
#include <sstream> 
#include <string> 

// file imports
#include "Student.hpp"
#include "StudentDB.hpp"

int main() {
    StudentDB db;
    db.printAll();

    Student student1(1, "Doe", "John", "Good");
    Student student2(2, "Smith", "Jane", "Fair");
    Student student3(3, "Johnson", "Bob", "Poor");
    Student student4(1001, "Williams", "Alice", "Good"); // Same hash index as student1

    // random inserts. 
    db.insert(student1);
    db.insert(student2);
    db.insert(student3);
    db.insert(student4);

    // generated test cases. 
    std::cout << "\nSearching for student ID 1: " << (db.search(1) ? "Found" : "Not Found") << std::endl;
    std::cout << "\nRemoving student ID 1: " << (db.remove(1) ? "Removed" : "Not Found") << std::endl;
    std::cout << "\nSearching for student ID 1 after removal: " << (db.search(1) ? "Found" : "Not Found") << std::endl;
    Student newStudent(1000, "Doe", "John", "Good");
    db.insert(newStudent);
    std::cout << "\nSearching for student ID 1000: " << (db.search(1000) ? "Found" : "Not Found") << std::endl;
    std::cout << "\nRemoving student ID 1000: " << (db.remove(1000) ? "Removed" : "Not Found") << std::endl;
    std::cout << "\nSearching for student ID 1000 after removal: " << (db.search(1000) ? "Found" : "Not Found") << std::endl;
    std::cout << "\nPrinting all remaining students:\n";
    db.printAll();

    return 0;
}
