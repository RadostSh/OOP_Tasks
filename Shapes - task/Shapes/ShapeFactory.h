#pragma once
#include "Shape.h"

class ShapeFactory
{
public:
    ShapeFactory();
    ShapeFactory(const ShapeFactory& other);
    ShapeFactory& operator=(const ShapeFactory& other);
    ~ShapeFactory();

    void addCircle(int x, int y, double radius);
    void addRectangle(int x1, int y1, int x3, int y3);
    void addTriangle(int x1, int y1, int x2, int y2, int x3, int y3);

    double getAreaByIndex(int index) const;
    double getPerByIndex(int index) const;
    bool pointIsInside(int index, int x, int y) const;

private:
    Shape** shapes;
    int size;
    int capacity;

    void resize();
    void addShape(Shape* shape);

    void copyFrom(const ShapeFactory& other);
    void free();
};