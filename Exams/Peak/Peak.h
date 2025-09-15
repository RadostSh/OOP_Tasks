#pragma once

class Peak
{
public:
    Peak() = default;
    Peak(const char* name, int height);
    Peak(const Peak& peak);
    Peak& operator=(const Peak& peak);
    virtual ~Peak();

    void setName(const char* newName);
    void setHeight(int newHeight);

    const char* getName() const;
    int getHeight() const;

    virtual void printName() const = 0;

private:
    char* name;
    int height;

    void copyFrom(const Peak& other);
    void free();
};
