// StudentDB.cpp
#include "StudentDB.hpp"
#include <iostream>

studentDB::studentDB(int s) : size(s) {}

// heapify
void studentDB::heapify(Student arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// heap sort
void studentDB::heapSort() {
    // max heap
    for (int i = size / 2 - 1; i >= 0; i--) {heapify(A, size, i);}

    // extract
    for (int i = size - 1; i > 0; i--) {
        std::swap(A[0], A[i]);
        heapify(A, i, 0);
    }
}

// debug
void studentDB::printStudents() const {
    for (int i = 0; i < size; ++i) {
        A[i].printStudent();
        std::cout << std::endl;
    }
}
