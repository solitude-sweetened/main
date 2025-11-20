#include "mylib.h"
#include "person.cpp"

int main(){
    string filename;
    cout << "Enter the name of the student data file: ";
    cin >> filename;

    ifstream studentFile(filename);
    if (!studentFile) {
        cerr << "Couldn't open the file: " << filename << endl;
        return 1;
    }

    vector<Person> students;

    string line;
    getline(studentFile, line); 
    getline(studentFile, line); 

    while (getline(studentFile, line)) {
        if (line.empty()) continue;
        if (line[0] == '-') continue;

        line.erase(remove(line.begin(), line.end(), '|'), line.end());

        stringstream ss(line);
        Person s;
        int hw1, hw2, hw3, hw4, hw5, exam;

        ss >> s.firstName >> s.lastName >> hw1 >> hw2 >> hw3 >> hw4 >> hw5 >> exam;
        if (ss.fail()) continue; 

        s.homework = {hw1, hw2, hw3, hw4, hw5};
        s.examResults = exam;

        students.push_back(s);
    }

    if (students.empty()) {
        cerr << "No student data found in the list." << endl;
        return 1;
    }

    sort(students.begin(), students.end(), [](const Person &a, const Person &b) {
        return a.firstName < b.firstName;
    });

    cout << left << setw(15) << "Name"
         << setw(15) << "Surname"
         << setw(20) << "Final (Avg.)"
         << setw(20) << "Final (Med.)" << endl;
    cout << string(70, '-') << endl;

    for (auto &s : students) {
        cout << left << setw(15) << s.firstName
             << setw(15) << s.lastName
             << setw(20) << fixed << setprecision(2) << s.averagePath()
             << setw(20) << fixed << setprecision(2) << s.medianPath() << endl;
    }

    return 0;
}
