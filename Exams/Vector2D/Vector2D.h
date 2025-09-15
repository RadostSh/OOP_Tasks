#pragma once

class Vector2D
{
public:
    Vector2D();
    Vector2D(double x, double y);

    double getX() const;
    double getY() const;

    Vector2D& operator+=(const Vector2D& other);
    friend Vector2D operator*(double scalar, const Vector2D& vector);
private:
    double x;
    double y;
};

Vector2D operator+(const Vector2D& lhs, const Vector2D& rhs);
double operator^(const Vector2D& lhs, const Vector2D& rhs);
bool operator==(const Vector2D& lhs, const Vector2D& rhs);
bool operator!=(const Vector2D& lhs, const Vector2D& rhs);