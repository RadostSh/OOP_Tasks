#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"

const double PI = 3.1415;

Circle::Circle(int x, int y, double r) : Shape(1), radius(r)
{
    setPoint(0, x, y);
}

Shape* Circle::clone() const
{
    return new Circle(*this);
}

double Circle::getRadius() const
{
    return radius;
}

double Circle::getArea() const
{
    return PI * radius * radius;
}

double Circle::getPerimeter() const
{
    return 2 * PI * radius;
}

bool Circle::isPointInside(int x, int y) const
{
    Shape::Point point(x, y);
    return point.getDistance(getPointAtIndex(0)) <= radius;
}

bool Circle::intersectsWith(const Shape* other) const
{
    return other->intersectWithCircle(this);
}

bool Circle::intersectWithCircle(const Circle* circle) const
{
    const Point& a = getPointAtIndex(0);
    const Point& b = circle->getPointAtIndex(0);

    double dx = a.x - b.x;
    double dy = a.y - b.y;
    double distSq = dx * dx + dy * dy;
    double rSum = radius + circle->radius;

    return distSq <= rSum * rSum;
}

bool Circle::intersectWithRectangle(const Rectangle* rectangle) const
{
    std::cout << "Circle::intersectWithRectangle" << std::endl;
    return true;
}

bool Circle::intersectWithTriangle(const Triangle* triangle) const
{
    std::cout << "Circle::intersectWithTriangle" << std::endl;
    return true;
}