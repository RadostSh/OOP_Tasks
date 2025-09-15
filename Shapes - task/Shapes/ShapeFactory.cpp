#include "ShapeFactory.h"

#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

void ShapeFactory::resize()
{
    Shape** newShapes = new Shape* [capacity *= 2];
    for (int i = 0; i < size; i++)
    {
        newShapes[i] = shapes[i];
    }
    delete[] shapes;
    shapes = newShapes;
}

void ShapeFactory::addShape(Shape* shape)
{
    if (size == capacity)
    {
        resize();
    }
    shapes[size++] = shape;
}

void ShapeFactory::copyFrom(const ShapeFactory& other)
{
    shapes = new Shape*[other.capacity];
    for (int i = 0; i < other.capacity; i++)
    {
        shapes[i] = other.shapes[i]->clone();
    }
    capacity = other.capacity;
    size = other.size;
}

void ShapeFactory::free()
{
    for (int i = 0; i < size; i++)
    {
        delete shapes[i];
    }
    delete [] shapes;
}

ShapeFactory::ShapeFactory()
{
    size = 0;
    capacity = 4;
    shapes = new Shape*[capacity];
}

ShapeFactory::ShapeFactory(const ShapeFactory& other) {
    copyFrom(other);
}

ShapeFactory& ShapeFactory::operator=(const ShapeFactory& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }

    return *this;
}

ShapeFactory::~ShapeFactory()
{
    free();
}

void ShapeFactory::addCircle(int x, int y, double radius)
{
    addShape(new Circle(x, y, radius));
}

void ShapeFactory::addRectangle(int x1, int y1, int x3, int y3)
{
    addShape(new Rectangle(x1, y1, x3, y3));
}

void ShapeFactory::addTriangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
    addShape(new Triangle(x1, y1, x2, y2, x3, y3));
}

double ShapeFactory::getAreaByIndex(int index) const
{
    if (index >= size)
    {
        throw std::out_of_range("index out of range");
    }

    return shapes[index]->getArea();
}

double ShapeFactory::getPerByIndex(int index) const
{
    if (index >= size)
    {
        throw std::out_of_range("index out of range");
    }

    return shapes[index]->getPerimeter();
}

bool ShapeFactory::pointIsInside(int index, int x, int y) const
{
    if (index >= size)
    {
        throw std::out_of_range("index out of range");
    }

    return shapes[index]->isPointInside(x, y);
}
