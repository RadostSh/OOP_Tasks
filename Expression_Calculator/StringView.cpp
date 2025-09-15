#include "StringView.h"
#include <exception>

StringView::StringView(const char* begin, const char* end) : begin(begin), end(end) {}

StringView::StringView(const char* str) : StringView(str, str + strlen(str)) {}

StringView::StringView(const MyString& str) : StringView(str.c_str()) {}

size_t StringView::size() const
{
    return end - begin;
}

char StringView::operator[](size_t index) const
{
    return begin[index];
}

StringView StringView::substr(size_t from, size_t size) const
{
    if (begin + from + size > end)
    {
        throw std::out_of_range("Error");
    }
    StringView substr(begin + from, begin + from + size);
    return substr;
}

bool operator==(const StringView& lhs, const StringView& rhs)
{
    if (lhs.size() != rhs.size())
    {
        return false;
    }

    for (size_t i = 0; i < lhs.size(); i++)
    {
        if (lhs[i] != rhs[i])
        {
            return false;
        }
    }
    return true;
}

bool operator!=(const StringView& lhs, const StringView& rhs)
{
    return !(lhs == rhs);
}

std::ostream& operator<<(std::ostream& os, const StringView& stringView)
{
    const char* iter = stringView.begin();

    while (iter != stringView.end())
    {
        os << *iter;
        iter++;
    }
    return os;
}
