#pragma once
#include <iostream>

class Triangle;
class Circle;
class Rectangle;

class Shape
{
public:
    Shape() = default;
    explicit Shape(int pointsCount);

    Shape(const Shape& other);
    Shape& operator=(const Shape& other);
    Shape(Shape&& other) noexcept;
    Shape& operator=(Shape&& other) noexcept;
    virtual ~Shape();

    virtual Shape* clone() const = 0;

    void setPoint(int index, int x, int y);

    virtual double getArea() const = 0;
    virtual double getPerimeter() const;
    virtual bool isPointInside(int x, int y) const = 0;

    virtual bool intersectsWith(const Shape* other) const = 0;
    virtual bool intersectWithCircle(const Circle* circle) const = 0;
    virtual bool intersectWithRectangle(const Rectangle* rectangle) const = 0;
    virtual bool intersectWithTriangle(const Triangle* triangle) const = 0;
protected:
    struct Point
    {
        int x;
        int y;

        Point() : x(0), y(0) {}
        Point(int x, int y) : x(x), y(y) {}

        double getDistance(const Point& other) const
        {
            int dx = x - other.x;
            int dy = y - other.y;
            return sqrt(dx*dx + dy*dy);
        }
    };
    const Point& getPointAtIndex(int index) const;
private:
    Point* points;
    int pointsCount;

    void copyFrom(const Shape& other);
    void moveFrom(Shape&& other);
    void free();
};