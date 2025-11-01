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
    void calculateFinalAverage();
    void printData();
};

// Input student data
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

// Calculate final grade (average)
void Person::calculateFinalAverage() {
    double avg = accumulate(homework.begin(), homework.end(), 0.0) / homework.size();
    finalGrade = 0.4 * avg + 0.6 * examResult;
}

// Print data
void Person::printData() {
    cout << left << setw(12) << firstName
         << setw(12) << lastName
         << right << setw(10) << fixed << setprecision(2) << finalGrade << endl;
}
