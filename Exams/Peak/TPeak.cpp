#include "TPeak.h"

#include <iostream>

TPeak::TPeak(const char* namePeak, const char* name, int height) : Peak(name, height)
{
    setPeakName(namePeak);
}

const char* TPeak::getPeakName() const {
    return namePeek;
}

void TPeak::printName() const
{
    std::cout << "Peak: " << getPeakName() << "\n";
}

void TPeak::free() {
    delete[] namePeek;
    namePeek = nullptr;
}

void TPeak::setPeakName(const char* str) {
    if (!str || this->namePeek == str) {
        return;
    }

    if (this->namePeek) {
        delete[] namePeek;
    }

    this->namePeek = new char[strlen(str) + 1];
    strcpy(this->namePeek, str);
}

void TPeak::copyFrom(const TPeak& other) {
    setPeakName(other.getPeakName());
}

TPeak::TPeak(const TPeak& other) : Peak(other) {
    copyFrom(other);
}

TPeak& TPeak::operator=(const TPeak& other) {
    if (this != &other) {
        Peak::operator=(other);
        free();
        copyFrom(other);
    }
    return *this;
}

TPeak::~TPeak() {
    free();
}