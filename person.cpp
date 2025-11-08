#include "person.h"

// enter student data
void Person::inputData() {
    cout << "Enter first name: ";
    cin >> firstName;

    cout << "Enter last name: ";
    cin >> lastName;

    cout << "Enter homework grades (type -1 to stop): ";
    homework.clear();
    while (true) {
        int g;
        cin >> g;
        if (g == -1) break;
        homework.push_back(g);
    }

    cout << "Enter exam grade: ";
    cin >> examResult;
}

// Calculate aver. of homework
double Person::gradeAverage() const {
    if (homework.empty()) return 0.0;
    double sum = accumulate(homework.begin(), homework.end(), 0.0);
    return sum / homework.size();
}

// Calculate weighted final average (40% homework, 60% exam)
double Person::calcFinalAverage() const {
    return gradeAverage() * 0.4 + examResult * 0.6;
}

// Store result
void Person::calculateFinalAverage() {
    finalGrade = calcFinalAverage();
}

// Print
void Person::printData() {
    cout << left << setw(12) << firstName
         << setw(12) << lastName
         << right << setw(10) << fixed << setprecision(2)
         << finalGrade << endl;
}
