#ifndef PERSON_H
#define PERSON_H

#include "mylib.h"

class Person {
public:
    string firstName;
    string lastName;
    vector<int> homework;
    int examResult;
    double finalGrade;

    // --- Functions ---
    void inputData();
    double gradeAverage() const;
    double calcFinalAverage() const;
    void calculateFinalAverage();
    void printData();
};

#endif
