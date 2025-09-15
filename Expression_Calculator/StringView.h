#pragma once
#include "MyString.h"

class StringView
{
public:
    StringView() = default;
    StringView(const char* begin, const char* end);
    StringView(const char* str);
    StringView(const MyString& str);

    size_t size() const;
    char operator[](size_t index) const;

    StringView substr(size_t from, size_t size) const;
    friend std::ostream& operator<<(std::ostream& os, const StringView& stringView);
private:
    const char* begin = nullptr;
    const char* end = nullptr;
};

bool operator==(const StringView& lhs, const StringView& rhs);
bool operator!=(const StringView& lhs, const StringView& rhs);