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
    void heapSort(); // Add heapSort declaration here
    void printStudents() const;

    int size;
    Student A[100];

private:
    void quickSortHelper(int low, int high);
    int partition(int low, int high);

    // Helper functions for heap sort
    void heapify(Student arr[], int n, int i);
};

#endif // STUDENTDB_HPP
