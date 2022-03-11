#include "../include/vector2.hpp"

Vector2 Vector2::operator+(const Vector2& other) const {   
    return {this->x + other.x, this->y + other.y};
}

Vector2 Vector2::operator-(const Vector2& other) const {
    return {this->x - other.x, this->y - other.y};
}

bool Vector2::operator==(const Vector2& other) const {
    return this->x == other.x && this->y == other.y;
}

std::ostream& operator<<(std::ostream &os, const Vector2& other)
{
    os << "("<< other.x << ", " << other.y << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Vector2& v)
{
    std::cout << "Introdu coordonatele vectorului: ";
    std::cout << "x: ";
    is >> v.x;
    std::cout << "y: ";
    is >> v.y;
    
    return is;
}