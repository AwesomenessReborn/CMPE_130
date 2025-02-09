
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

#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include "roster.h"

void showMenu() {
    std::cout << " --------------------- "; 
    std::cout << "\nClass Roster Management System\n";
    std::cout << "1. List Students\n";
    std::cout << "2. Add Student\n";
    std::cout << "3. Drop Student\n";
    std::cout << "4. Update Student\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    Roster roster("roster.txt");
    
    int choice;
    do {
        showMenu();
        std::cin >> choice;
        std::cin.ignore(); // Clear newline character

        int id;
        std::string last, first, level;

        switch (choice) {
            case 1:
                std::cout << std::endl; 
                roster.listStudents();
                break;
            case 2:
                std::cout << std::endl; 
                std::cout << "Enter Student ID: ";
                while (!(std::cin >> id)) { // Ensure valid integer input
                    std::cin.clear(); // Clear error flag
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard bad input
                    std::cout << "Invalid input. Enter a valid Student ID: ";
                }
                std::cin.ignore(); // Consume leftover newline

                std::cout << "Enter Last Name: ";
                std::getline(std::cin, last);

                std::cout << "Enter First Name: ";
                std::getline(std::cin, first);

                std::cout << "Enter Academic Level: ";
                std::getline(std::cin, level);

                roster.addStudent(Student(id, last, first, level));
                break;
            case 3:

                std::cout << std::endl; 
                std::cout << "Enter Student ID to drop: ";
                std::cin >> id;
                roster.dropStudent(id);
                break;
            case 4:

                std::cout << std::endl; 
                std::cout << "Enter Student ID to update: ";
                std::cin >> id;
                std::cin.ignore();
                
                std::cout << "Enter new Last Name: ";
                std::getline(std::cin, last);

                std::cout << "Enter new First Name: ";
                std::getline(std::cin, first);

                std::cout << "Enter new Academic Level: ";
                std::getline(std::cin, level);

                roster.updateStudent(id, last, first, level);
                break;
            case 5:

                std::cout << std::endl; 
                std::cout << "Saving and exiting..." << std::endl;
                break;
            default:

                std::cout << std::endl; 
                std::cout << "Invalid choice, try again." << std::endl;

                std::cout << std::endl; 
        }
    } while (choice != 5);

    return 0;
}
