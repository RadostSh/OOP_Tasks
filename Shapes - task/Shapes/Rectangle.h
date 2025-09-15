#pragma once
#include "Circle.h"
#include "Shape.h"
#include "Triangle.h"

class Rectangle : public Shape
{
public:
    Rectangle() = default;
    Rectangle(int x1, int y1, int x3, int y3);

    Shape* clone() const override;

    double getArea() const override;
    bool isPointInside(int x, int y) const override;

    bool intersectsWith(const Shape* other) const override;
    bool intersectWithCircle(const Circle* circle) const override;
    bool intersectWithRectangle(const Rectangle* rectangle) const override;
    bool intersectWithTriangle(const Triangle* triangle) const override;
};
