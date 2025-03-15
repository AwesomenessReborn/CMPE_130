// StudentDB.cpp
#include "StudentDB.hpp"
#include <iostream>

studentDB::studentDB(int s) : size(s) {}

void studentDB::insertionSort() {
    for (int i = 1; i < size; i++) {
        Student key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

void studentDB::selectionSort() {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (A[j] < A[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(A[i], A[minIndex]);
    }
}

int studentDB::partition(int low, int high) {
    Student pivot = A[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (A[j] < pivot) {
            i++;
            std::swap(A[i], A[j]);
        }
    }
    std::swap(A[i + 1], A[high]);
    return i + 1;
}

void studentDB::quickSortHelper(int low, int high) {
    if (low < high) {
        int pivotIndex = partition(low, high);
        quickSortHelper(low, pivotIndex - 1);
        quickSortHelper(pivotIndex + 1, high);
    }
}

void studentDB::quickSort() {
    quickSortHelper(0, size - 1);
}

void studentDB::printStudents() const {
    for (int i = 0; i < size; i++) {
        A[i].printStudent();
    }
}
