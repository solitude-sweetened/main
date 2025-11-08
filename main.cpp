#include "mylib.h"
#include "person.h"

int main() {
    srand(time(nullptr));

    int n;
    cout << "Enter number of students: ";
    cin >> n;

    vector<Person> students(n);

    for (int i = 0; i < n; ++i) {
        cout << "\nStudent #" << i + 1 << ":\n";
        students[i].inputData();
        students[i].calculateFinalAverage();
    }

    cout << "\nName         Surname      Final(Avg)\n";
    cout << "-------------------------------------\n";

    for (auto &s : students)
        s.printData();

    return 0;
}

