#ifndef VECTOR2_HPP
#define VECTOR2_HPP

#include <iostream>

class Vector2 {
public:
    // overload la operatori aritmetici
    Vector2 operator+(const Vector2& other) const;
    Vector2 operator-(const Vector2& other) const;

    // overload la comparison operator
    bool operator==(const Vector2& other) const;

    // overload la left shift operator
    friend std::ostream& operator<<(std::ostream& os, const Vector2& v);

    double x;
    double y;
};

#endif // VECTOR2_HPP
