#include "../include/triunghi.hpp"
#include <cmath>

Triunghi::Triunghi(Vector2 v1_, Vector2 v2_, Vector2 v3_)
    : v1(v1_), v2(v2_), v3(v3_)
{}

Vector2 Triunghi::getV1() const {
    return this->v1;
}

Vector2 Triunghi::getV2() const {
    return this->v2;
}

Vector2 Triunghi::getV3() const {
    return this->v3;
}

void Triunghi::setV1(const Vector2 &v1_) {
    this->v1 = v1_;
}

void Triunghi::setV2(const Vector2 &v2_) {
    this->v2 = v2_;
}

void Triunghi::setV3(const Vector2 &v3_) {
    this->v3 = v3_;
}

auto distanta = [](const Vector2 &v1, const Vector2 &v2) {
        return sqrt(pow(v1.x - v2.x, 2) + pow(v1.y - v2.y, 2));
};

double Triunghi::arie() const {
    double area = ((v1.x - v3.x) * (v2.y - v3.y) - (v2.x - v3.x) * (v1.y - v3.y)) / 2;

    return area > 0 ? area : -area;
}

double Triunghi::perimetru() const {
    return distanta(this->v1, this->v2) + distanta(this->v2, this->v3) + distanta(this->v3, this->v1);
}

std::ostream& operator<<(std::ostream &os, const Triunghi& t) {
    os << "Triunghi(v1: " << t.v1 << ", v2: " << t.v2 << ", v3: " << t.v3 << ")";

    return os;
}

std::istream& operator>>(std::istream& is, Triunghi& t) {
    std::cout << "Introduceti coordonatele primului punct.\n";
    std::cout << "x: ";
    std::cin >> t.v1.x;
    std::cout << "y: ";
    std::cin >> t.v1.y;

    std::cout << "Introduceti coordonatele celui de-al doilea punct.\n";
    std::cout << "x: ";
    std::cin >> t.v2.x;
    std::cout << "y: ";
    std::cin >> t.v2.y;

    std::cout << "Introduceti coordonatele celui de-al treilea punct.\n";
    std::cout << "x: ";
    std::cin >> t.v3.x;
    std::cout << "y: ";
    std::cin >> t.v3.y;

    return is;
}