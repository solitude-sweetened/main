README.md (v0.2)

**Overview**

This program processes large student datasets by generating files, reading student records, calculating final grades, sorting the data, splitting students into passed and failed groups, and measuring execution time.

**Features**

**Automatic Dataset Generation**
The program creates four datasets:
- 10 000 records
- 100 000 records
- 1 000 000 records
- 10 000 000 records
Names are generated automatically.

**Student Processing**
For each dataset, the program:
- Reads all records;
- Sorts students by first name;
- Calculates final grades using average and median;
- Splits students into passed (≥5.0) and failed (<5.0);
- Writes two output files for each dataset.

**Performance Measurement**
Execution time is measured for:
- Reading;
- Sorting;
- Splitting;
- Writing passed output;
- Writing failed output.
Results are printed for every dataset.

**Exception Handling**
The program throws and catches:
- FileOpenError for unreadable files;
- ParseError for invalid data lines.

**Project Structure**
- main.cpp
- person.h
- person.cpp
- processing.h
- processing.cpp
- io.h
- io.cpp
- timer.h
- exceptions.h
- mylib.h
