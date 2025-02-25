#include "StudentDLinkDB.hpp"
#include <iostream>

// Constructor
StudentDLinkDB::StudentDLinkDB() : size(0), head(nullptr) {}

// Destructor
StudentDLinkDB::~StudentDLinkDB() {
    while (head) {
        Student* temp = head;
        head = head->next;
        delete temp;
    }
}

// Add a student to the list (at the front for simplicity)
void StudentDLinkDB::addStudent(int id, const std::string& lastName, const std::string& firstName, const std::string& academicStanding) {
    Student* newStudent = new Student(id, lastName, firstName, academicStanding);
    newStudent->next = head;
    if (head) {
        head->prev = newStudent;
    }
    head = newStudent;
    size++;
}

// Print the list
void StudentDLinkDB::printList() const {
    Student* current = head;
    while (current) {
        current->printStudent();
        current = current->next;
    }
}

// Split the list into two halves
Student* StudentDLinkDB::split(Student* head) {
    if (!head || !head->next) return nullptr;

    Student* slow = head;
    Student* fast = head;

    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Student* mid = slow->next;
    slow->next = nullptr; // Break the list into two halves
    if (mid) mid->prev = nullptr;

    return mid;
}

// Merge two sorted lists
Student* StudentDLinkDB::merge(Student* left, Student* right) {
    if (!left) return right;
    if (!right) return left;

    if (*left < *right) {
        left->next = merge(left->next, right);
        left->next->prev = left;
        left->prev = nullptr;
        return left;
    } else {
        right->next = merge(left, right->next);
        right->next->prev = right;
        right->prev = nullptr;
        return right;
    }
}

// Recursive merge sort
void StudentDLinkDB::mergeSort() {
    if (!head || !head->next) return;

    head = mergeSortHelper(head);
}

// use helper, since we need to pass node list node manually. 
Student* StudentDLinkDB::mergeSortHelper(Student* node) {
    if (!node || !node->next) return node;

    Student* mid = split(node);

    // Sort each half recursively
    Student* leftSorted = mergeSortHelper(node);
    Student* rightSorted = mergeSortHelper(mid);

    // Merge sorted halves
    return merge(leftSorted, rightSorted);
} 