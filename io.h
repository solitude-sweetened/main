#ifndef IO_H
#define IO_H

#include "mylib.h"
#include "person.h"

void generateDataset(const std::string& filename, size_t count);

void writeStudents(const std::vector<Person>& students, const std::string& filename);

std::ostream& operator<<(std::ostream& os, const Person& p);

#endif
