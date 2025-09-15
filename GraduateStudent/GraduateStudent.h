#pragma once
#include <iostream>
#include <sstream>
using namespace std;

namespace constants
{
    constexpr int MAX_SIZE = 30;
}

class GraduateStudent
{
public:
    GraduateStudent() = default;
    GraduateStudent(const char* name, const int* grades, size_t grades_count, const char* quote);
    GraduateStudent(const GraduateStudent& other);
    GraduateStudent& operator=(const GraduateStudent& other);
    ~GraduateStudent();

    void setName(const char* new_name);
    void setGrades(const int* new_grades, size_t new_grades_count);
    void setQuote(const char* new_quote);

    const char* getName() const;
    const int* getGrades() const;
    size_t getGradesCount() const;
    const char* getQuote() const;

private:
    char* name = nullptr;
    int* grades = nullptr;
    size_t grades_count = 0;
    char quote[constants::MAX_SIZE + 1]{};

    void copy(const GraduateStudent& other);
    void free();
};