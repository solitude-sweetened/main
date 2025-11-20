#include "person.h"

double Person::gradeAverage() const {
    if (homework.empty()) {
        return 0.0;
    }

    double sum = accumulate(homework.begin(), homework.end(), 0.0);
    return sum / static_cast<double>(homework.size());
}

double Person::averagePath() const {
    return gradeAverage() * 0.4 + examResults * 0.6;
}

double Person::medianPath() const {
    return gradeMedian() * 0.4 + examResults * 0.6;
}

double Person::gradeMedian() const {
    if (homework.empty()) {
        return 0.0;
    }

    size_t count = homework.size();
    size_t midpoint = count / 2;

    if (count % 2 == 0) {
        double left = homework[midpoint - 1];
        double right = homework[midpoint];
        return (left + right) / 2.0;
    }

    return homework[midpoint];
}

vector<int> Person::RandHWGrade(int minimumGrades, int maximumGrades) {
    vector<int> hwSet;
    size_t count = (rand() % 10) + 1;

    for (size_t i = 0; i < count; ++i) {
        int value = minimumGrades + (rand() % (maximumGrades - minimumGrades + 1));
        hwSet.push_back(value);
    }

    return hwSet;
}

int Person::randExamResult(int minimumGrade, int maximumGrade) {
    return minimumGrade + (rand() % (maximumGrade - minimumGrade + 1));
}

Person::Person()
    : firstName(""),
      surname(""),
      homework(),
      examResults(0),
      finalAverage(0.0),
      finalMedian(0.0),
      calcMethod("") 
{
    activeCount++;
}

Person::Person(const Person& other)
    : firstName(other.firstName),
      surname(other.surname),
      homework(other.homework),
      examResults(other.examResults),
      finalAverage(other.finalAverage),
      finalMedian(other.finalMedian),
      calcMethod(other.calcMethod)
{
    activeCount++;
}

Person& Person::operator=(const Person& other) {
    if (this != &other) {
        firstName = other.firstName;
        surname = other.surname;
        homework = other.homework;
        examResults = other.examResults;
        finalAverage = other.finalAverage;
        finalMedian = other.finalMedian;
        calcMethod = other.calcMethod;
    }
    return *this;
}

Person::~Person() {
    activeCount--;
    cout << "Object removed. Active Person instances: " << activeCount << "\n";
}
