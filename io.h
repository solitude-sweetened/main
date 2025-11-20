#ifndef IO_H
#define IO_H

#include "mylib.h"
#include "person.h"

// Generates a dataset of random students (header + rows)
void generateDataset(const std::string& filename, size_t count);

// Write student results to file
void writeStudents(const std::vector<Person>& students, const std::string& filename);

std::ostream& operator<<(std::ostream& os, const Person& p);

#endif
