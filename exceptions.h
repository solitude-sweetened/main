#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <string>

struct FileOpenError : std::runtime_error {
    explicit FileOpenError(const std::string& path)
    : std::runtime_error("Cannot open file: " + path) {}
};

struct ParseError : std::runtime_error {
  explicit ParseError(const std::string& msg)
  : std::runtime_error("Parse error: " + msg) {}
};

#endif