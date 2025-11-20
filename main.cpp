#include "mylib.h"
#include "person.h"
#include "processing.h"
#include "io.h"
#include "timer.h"
#include "exceptions.h"

int main() {
    try {

        // Dataset generation
        cout << "Generating datasets. Please wait...\n";

        generateDataset("dataset_10k.txt", 10000);
        generateDataset("dataset_100k.txt", 100000);
        generateDataset("dataset_1m.txt", 1000000);
        generateDataset("dataset_10m.txt", 10000000);

        cout << "Datasets generated.\n\n";

        // List of datasets to process
        vector<string> datasets = {
            "dataset_10k.txt",
            "dataset_100k.txt",
            "dataset_1m.txt",
            "dataset_10m.txt"
        };

        // Processing
        for (const auto& file : datasets) {

            cout << "Processing: " << file << "\n";

            Timer timer;

            // Reading
            timer.reset();

            ifstream inp(file);
            if (!inp) throw FileOpenError(file);

            vector<Person> students;
            string line;

            getline(inp, line);
            getline(inp, line);

            while (getline(inp, line)) {
                if (line.empty()) continue;
                if (line[0] == '-') continue;

                line.erase(remove(line.begin(), line.end(), '|'), line.end());

                stringstream ss(line);
                Person s;
                int hw1, hw2, hw3, hw4, hw5, exam;

                ss >> s.firstName >> s.surname >> hw1 >> hw2 >> hw3 >> hw4 >> hw5 >> exam;

                if (ss.fail()) {
                    throw ParseError("Invalid student line in file " + file + ": " + line);
                }

                s.homework = {hw1, hw2, hw3, hw4, hw5};
                s.examResults = exam;

                students.push_back(s);
            }

            inp.close();

            double readTime = timer.elapsedMs();


            // Sorting
            timer.reset();

            sort(students.begin(), students.end(), [](const Person& a, const Person& b) {
                return a.firstName < b.firstName;
            });

            double sortTime = timer.elapsedMs();


            // Splitting
            timer.reset();

            vector<Person> failed;
            vector<Person> passed;

            splitPassedFailed(students, failed, passed);

            double splitTime = timer.elapsedMs();


            // Writing passed
            timer.reset();
            writeStudents(passed, "passed_" + file);
            double passedWriteTime = timer.elapsedMs();

            // Writing failed
            timer.reset();
            writeStudents(failed, "failed_" + file);
            double failedWriteTime = timer.elapsedMs();


            // Summary output
            cout << "Summary for " << file << "\n"
                 << "Read time: " << readTime << " ms\n"
                 << "Sort time: " << sortTime << " ms\n"
                 << "Split time: " << splitTime << " ms\n"
                 << "Write passed time: " << passedWriteTime << " ms\n"
                 << "Write failed time: " << failedWriteTime << " ms\n"
                 << "----------------------------------------------\n\n";
        }

    } catch (const std::exception& e) {
        cerr << "Runtime error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
