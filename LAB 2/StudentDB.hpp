// StudentDB.hpp
#ifndef STUDENTDB_HPP
#define STUDENTDB_HPP

#include "Student.hpp"

class studentDB {
public:
    studentDB(int s);

    void insertionSort();
    void selectionSort();
    void quickSort();
    void printStudents() const;

    int size;
    Student A[100];

private:

    void quickSortHelper(int low, int high);
    int partition(int low, int high);
};

#endif // STUDENTDB_HPP
