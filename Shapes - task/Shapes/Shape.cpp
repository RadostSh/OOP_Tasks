#include "Shape.h"
#include <assert.h>

void Shape::copyFrom(const Shape& other)
{
    points = new Point[other.pointsCount];
    for (int i = 0; i < other.pointsCount; i++)
    {
        points[i] = other.points[i];
    }
    pointsCount = other.pointsCount;
}

void Shape::moveFrom(Shape&& other)
{
    points = other.points;
    other.points = nullptr;
    pointsCount = other.pointsCount;
    other.pointsCount = 0;
}

void Shape::free()
{
    delete[] points;
    pointsCount = 0;
}

Shape::Shape(int pointsCount) : pointsCount(pointsCount)
{
    points = new Point[pointsCount];
}

Shape::Shape(const Shape& other)
{
    copyFrom(other);
}

Shape::Shape(Shape&& other) noexcept
{
    moveFrom(std::move(other));
}

Shape& Shape::operator=(const Shape& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

Shape& Shape::operator=(Shape&& other) noexcept
{
    if (this != &other)
    {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

Shape::~Shape()
{
    free();
}

void Shape::setPoint(int index, int x, int y)
{
    if (index >= pointsCount)
    {
        throw std::out_of_range("Shape::setPoint");
    }
    points[index].x = x;
    points[index].y = y;
}

const Shape::Point& Shape::getPointAtIndex(int index) const
{
    if (index >= pointsCount)
    {
        throw std::out_of_range("Shape::getPointAtIndex");
    }
    return points[index];
}

double Shape::getPerimeter() const
{
    assert(pointsCount >= 3);

    double result = 0;

    for (int i = 1; i < pointsCount; i++)
    {
        result += points[i - 1].getDistance(points[i]);
    }

    return result + points[pointsCount - 1].getDistance(points[0]);
}