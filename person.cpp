#include "mylib.h"

class Person {

  public:
  string firstName, surname;
  vector<int> homework;
  int examResults;

  double finalAverage;
  double finalMedian;

  string calcMethod;

  // static counter
  static inline int activeCount = 0;


  double gradeAverage() {
    if (homework.empty()) {
      return 0.0;
    }

    double sum = accumulate(homework.begin(), homework.end(), 0.0);
    return sum / static_cast<double>(homework.size());
  }

  double averagePath() {
    finalAverage = gradeAverage() * 0.4 + examResults * 0.6;
    return finalAverage;
  }

  double medianPath() {
    finalMedian = gradeMedian() * 0.4 + examResults * 0.6;
    return finalMedian;
  }

  vector<int> RandHWGrade(int minimumGrades = 1, int maximumGrades = 10) {
    vector<int> hwSet;

    size_t count = (rand() % 10) + 1;

    for (size_t i = 0; i < count; ++i) {
      int value = minimumGrades + (rand() % (maximumGrades - minimumGrades + 1));
      hwSet.push_back(value);
    }

    return hwSet;
  }

  int randExamResult(int minimumGrade = 1, int maximumGrade = 10) {
    return minimumGrade + (rand() % (maximumGrade - minimumGrade + 1));
  }

  double gradeMedian() {
    if (homework.empty()) {
      return 0.0;
    }

    size_t count = homework.size();
    size_t midpoint = count / 2;

    if (count % 2 == 0) {
      double left = homework.at(midpoint - 1);
      double right = homework.at(midpoint);
      return (left + right) / 2.0;
    }

    return homework.at(midpoint);
  }

  Person()
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

  Person(const Person& other)
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

  Person& operator=(const Person& other) {
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

  ~Person() {
    activeCount--; // for future debugging purposes, if needed
    cout << "Object removed. Active Person instances: " << activeCount << "\n";
  }
};
