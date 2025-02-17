#include "StudentDB.hpp"
#include <iostream>

int main() {
    Student students[] = {
        {1023, "Smith", "John", "Junior"},
        {1005, "Johnson", "Emma", "Senior"},
        {1011, "Brown", "Michael", "Sophomore"},
        {1040, "Davis", "Olivia", "Freshman"},
        {1033, "Miller", "James", "Junior"},
        {1052, "Wilson", "Sophia", "Sophomore"},
        {1008, "Anderson", "Liam", "Senior"},
        {1077, "Taylor", "Mia", "Freshman"},
        {1029, "Moore", "William", "Junior"},
        {1085, "Thomas", "Charlotte", "Senior"}
    };

    int numStudents = sizeof(students) / sizeof(students[0]);

    studentDB db(numStudents);
    for (int i = 0; i < numStudents; i++) {
        db.A[i] = students[i];  
    }

    std::cout << "====== Original Student List ======" << std::endl;
    db.printStudents();

    // Insertion Sort
    std::cout << "\n After Insertion Sort " << std::endl;
    studentDB dbInsertion = db;   //    use unsorted db.
    dbInsertion.insertionSort();
    dbInsertion.printStudents();

    // Selection Sort
    std::cout << "\n After Selection Sort " << std::endl;
    studentDB dbSelection = db;   //    use unsorted db.
    dbSelection.selectionSort();
    dbSelection.printStudents();

    // Quick Sort
    std::cout << "\n After Quick Sort" << std::endl;
    studentDB dbQuick = db;       //    use unsorted db.
    dbQuick.quickSort();
    dbQuick.printStudents();

    return 0;

}
