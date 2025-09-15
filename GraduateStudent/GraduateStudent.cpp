#include "GraduateStudent.h"

void GraduateStudent::copy(const GraduateStudent& other)
{
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);

    grades = new int[other.grades_count];
    for (int i = 0; i < other.grades_count; i++)
    {
        grades[i] = other.grades[i];
    }

    grades_count = other.grades_count;
    strcpy(quote, other.quote);
}

void GraduateStudent::free()
{
    delete[] name;
    delete[] grades;
    name = nullptr;
    grades = nullptr;
    grades_count = 0;
    strcpy(quote, "");
}

void GraduateStudent::setName(const char* new_name)
{
    if (!new_name || new_name == name)
    {
        return;
    }

    delete[] name;
    name = new char[strlen(new_name) + 1];
    strcpy(name, new_name);
}

void GraduateStudent::setGrades(const int* new_grades, size_t new_grades_count)
{
    if (!new_grades || grades == new_grades)
    {
        return;
    }

    delete[] grades;
    grades = new int[new_grades_count];
    for (int i = 0; i < new_grades_count; i++)
    {
        grades[i] = new_grades[i];
    }
}

void GraduateStudent::setQuote(const char* new_quote)
{
    if (!new_quote || strlen(new_quote) > constants::MAX_SIZE)
    {
        return;
    }
    strcpy(quote, new_quote);
}

GraduateStudent::GraduateStudent(const char* name, const int* grades, size_t grades_count, const char* quote)
{
    setName(name);
    setGrades(grades, grades_count);
    setQuote(quote);
}

GraduateStudent::GraduateStudent(const GraduateStudent& other)
{
    copy(other);
}

GraduateStudent& GraduateStudent::operator=(const GraduateStudent& other)
{
    if (this != &other)
    {
        free();
        copy(other);
    }
    return *this;
}

GraduateStudent::~GraduateStudent()
{
    free();
}

const char* GraduateStudent::getName() const
{
    return name;
}

const int* GraduateStudent::getGrades() const
{
    return grades;
}

size_t GraduateStudent::getGradesCount() const
{
    return grades_count;
}

const char* GraduateStudent::getQuote() const
{
    return quote;
}