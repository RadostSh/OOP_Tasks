#pragma once
#include "Peak.h"

class MPeak : public Peak
{
public:
    MPeak(const char* name, int height, int num);

    void setNum(int num);
    int getNum() const;

    void printName() const override;
private:
    int num = 0;
};
