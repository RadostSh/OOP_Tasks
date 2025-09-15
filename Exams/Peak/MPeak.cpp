#include "MPeak.h"
#include <iostream>

MPeak::MPeak(const char* name, int height, int num) : Peak(name, height), num(num) {}

void MPeak::setNum(int num)
{
    this->num = num;
}

int MPeak::getNum() const
{
    return this->num;
}

void MPeak::printName() const
{
    std::cout << "kod " << getNum() << std::endl;
}
