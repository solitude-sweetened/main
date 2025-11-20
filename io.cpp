#include "io.h"

void generateDataset(const std::string& filename, size_t count) {
    std::ofstream out(filename);
    if (!out) {
        throw FileOpenError(filename);
    }

    // Header row
    out << "Name Surname HW1 HW2 HW3 HW4 HW5 Exam\n";

    for (size_t i = 1; i <= count; ++i) {
        out << "Name" << i << " "
            << "Surname" << i << " ";

        // Generate 5 random HW grades
        for (int j = 0; j < 5; ++j) {
            out << (1 + rand() % 10) << " ";
        }

        // Exam grade
        out << (1 + rand() % 10) << "\n";
    }

    out.close();
}

void writeStudents(const std::vector<Person>& students, const std::string& filename) {
    std::ofstream out(filename);
    if (!out) {
        throw FileOpenError(filename);
    }

    out << std::left << std::setw(12) << "Name"
        << std::setw(12) << "Surname"
        << std::right << std::setw(12) << "Final(Avg)"
        << " | " 
        << std::setw(12) << "Final(Med)"
        << "\n";

    out << std::string(12 + 12 + 12 + 3 + 12, '-') << "\n";

    for (const auto& s : students) {
        out << s << "\n";
    }

    out.close();
}

std::ostream& operator<<(std::ostream& os, const Person& p) {
    os << std::left << std::setw(12) << p.firstName
       << std::setw(12) << p.surname
       << std::right << std::setw(12) << std::fixed << std::setprecision(2)
       << p.averagePath()
       << " | "
       << std::setw(12) << std::fixed << std::setprecision(2)
       << p.medianPath();

    return os;
}
