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

