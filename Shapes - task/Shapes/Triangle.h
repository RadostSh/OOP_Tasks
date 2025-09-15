#pragma once
#include <iostream>
#include "Shape.h"

class Triangle : public Shape
{
public:
    Triangle() = default;
    Triangle(int x1, int y1, int x2, int y2, int x3, int y3);

    Shape* clone() const override;

    double getArea() const override;
    bool isPointInside(int x, int y) const override;

    bool intersectsWith(const Shape* other) const override;
    bool intersectWithCircle(const Circle* circle) const override;
    bool intersectWithRectangle(const Rectangle* rectangle) const override;
    bool intersectWithTriangle(const Triangle* triangle) const override;
};