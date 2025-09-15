#include "MyString.h"
#include <algorithm>
#pragma warning (disable : 4996)
using namespace std;

void MyString::copyFrom(const MyString& other)
{
    data = new char[other.capacity];
    strcpy(data, other.data);
    size = other.size;
    capacity = other.capacity;
}

void MyString::moveFrom(MyString&& other)
{
    data = other.data;
    other.data = nullptr;

    size = other.size;
    other.size = 0;

    capacity = other.capacity;
    other.capacity = 0;
}

void MyString::free()
{
    delete[] data;
    data = nullptr;
    size = 0;
    capacity = 0;
}

void MyString::resize(size_t newCapacity)
{
    char* newData = new char[newCapacity + 1];
    strcpy(newData, data);
    delete[] data;
    data = newData;
    capacity = newCapacity;
}

MyString::MyString(): MyString(""){}

static unsigned roundToPowerOfTwo(unsigned num)
{
    unsigned result = 1;
    while (result < num)
    {
        result *= 2;
    }
    return result;
}

static unsigned getMaxResizeCapacity(unsigned size)
{
    return max(16u, roundToPowerOfTwo(size));
}

MyString::MyString(const char* str)
{
    if (!str)
    {
        str = "";
    }
    size = strlen(str);
    capacity = getMaxResizeCapacity(size);
    data = new char[capacity];
    strcpy(data, str);
}

MyString::MyString(const MyString& other)
{
    copyFrom(other);
}

MyString& MyString::operator=(const MyString& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

MyString::MyString(MyString&& other) noexcept
{
    moveFrom(std::move(other));
}

MyString& MyString::operator=(MyString&& other) noexcept
{
    if (this != &other)
    {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

MyString::~MyString()
{
    free();
}

size_t MyString::getSize() const
{
    return size;
}

size_t MyString::getCapacity() const
{
    return capacity - 1;
}

const char* MyString::c_str() const
{
    return data;
}

char& MyString::operator[](unsigned index)
{
    return data[index];
}

const char& MyString::operator[](unsigned index) const
{
    return data[index];
}

MyString& MyString::operator+=(const MyString& other)
{
    if (size + other.size + 1 > capacity)
    {
        resize(getMaxResizeCapacity((size + other.size)));
    }
    strncat(data, other.data, size);
    size += other.size;
    return *this;
}

MyString operator+(const MyString& lhs, const MyString& rhs)
{
    MyString res(lhs);
    res += rhs;

    return res;
}

std::ostream& operator<<(std::ostream& os, const MyString& str)
{
    return os << str.data;
}

std::istream& operator>>(std::istream& is, MyString& str)
{
    char buff[1024];
    is >> buff;

    size_t buffSize = strlen(buff);
    if (buffSize >= str.capacity)
    {
        str.resize(getMaxResizeCapacity(buffSize));
    }

    strcpy(str.data, buff);
    str.size = buffSize;

    return is;
}

MyString MyString::substr(unsigned begin, size_t count)
{
    if (begin + count > size) {
        return MyString("");
    }

    MyString res;
    res.capacity = getMaxResizeCapacity(count + 1);
    res.data = new char[res.capacity + 1];
    strncat(res.data, data + begin, count);
    res.size = count;
    return res;
}

bool operator==(const MyString& lhs, const MyString& rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}

bool operator!=(const MyString& lhs, const MyString& rhs)
{
    return !(lhs == rhs);
}

bool operator>(const MyString& lhs, const MyString& rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) > 0;
}

bool operator>=(const MyString& lhs, const MyString& rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) >= 0;
}

bool operator<(const MyString& lhs, const MyString& rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}

bool operator<=(const MyString& lhs, const MyString& rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) <= 0;
}