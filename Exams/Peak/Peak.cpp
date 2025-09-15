#include "Peak.h"
#include <cstring>

void Peak::copyFrom(const Peak& other)
{
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
    height = other.height;
}

void Peak::free()
{
    delete [] name;
}

Peak::Peak(const char* name, int height)
{
    setName(name);
    setHeight(height);
}

Peak::Peak(const Peak& peak)
{
    copyFrom(peak);
}

Peak::~Peak()
{
    free();
}

Peak& Peak::operator=(const Peak& peak)
{
    if (this != &peak)
    {
        free();
        copyFrom(peak);
    }
    return *this;
}

const char* Peak::getName() const
{
    return name;
}

int Peak::getHeight() const
{
    return height;
}

void Peak::setName(const char* newName)
{
    if (!newName || name == newName)
    {
        return;
    }
    delete [] name;
    name = new char[strlen(newName) + 1];
    strcpy(name, newName);
}

void Peak::setHeight(int newHeight)
{
    if (newHeight < 1)
    {
        return;
    }
    height = newHeight;
}
