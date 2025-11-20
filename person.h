#ifndef PERSON_H
#define PERSON_H

#include "mylib.h"

class Person {

public:
    string firstName;
    string surname;
    vector<int> homework;
    int examResults;

    double finalAverage;
    double finalMedian;

    string calcMethod;

    // static instance counter
    static inline int activeCount = 0;

    double gradeAverage() const;
    double averagePath() const;
    double medianPath() const;
    double gradeMedian() const;

    vector<int> RandHWGrade(int minimumGrades = 1, int maximumGrades = 10);
    int randExamResult(int minimumGrade = 1, int maximumGrade = 10);

    // special member functions
    Person();
    Person(const Person& other);
    Person& operator=(const Person& other);
    ~Person();
};

#endif
