#pragma once
#include "Peak.h"

class TPeak : public Peak
{
public:
    TPeak() = default;
    TPeak(const char* namePeak, const char* name, int height);

    TPeak(const TPeak& other);
    TPeak& operator=(const TPeak& other);
    ~TPeak();

    const char* getPeakName() const;
    void setPeakName(const char* str);

    void printName() const override;
private:
    char* namePeek;

    void free();
    void copyFrom(const TPeak& other);
};