#pragma once
#include "Shape.h"

class Circle : public Shape
{
public:
    Circle() = default;
    Circle(int x, int y, double r);

    Shape* clone() const override;

    double getRadius() const;

    double getArea() const override;
    double getPerimeter() const override;
    bool isPointInside(int x, int y) const override;

    bool intersectsWith(const Shape* other) const override;
    bool intersectWithCircle(const Circle* circle) const override;
    bool intersectWithRectangle(const Rectangle* rectangle) const override;
    bool intersectWithTriangle(const Triangle* triangle) const override;

private:
    double radius;
};
