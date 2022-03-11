#include "../include/cerc.hpp"
#include <cmath>

Cerc::Cerc(double raza_, Vector2 centru_)
    : centru(centru_), raza(raza_)
{}

Vector2 Cerc::getCentru() const {
    return this->centru;
}

double Cerc::getRaza() const {
    return this->raza;
}

void Cerc::setCentru(const Vector2 &centru_) {
    this->centru = centru_;
}

void Cerc::setRaza(double raza_) {
    this->raza = raza_;
}

double Cerc::arie() const {
    return M_PI * this->raza * this->raza;
}

double Cerc::perimetru() const {
    return 2 * M_PI * this->raza;
}

std::ostream& operator<<(std::ostream &os, const Cerc& c) {
    os << "Cerc(centru: " << c.centru << ", raza:" << c.raza << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Cerc& c)
{
    std::cout << "Introduceti raza: ";
    std::cin >> c.raza;
    
    std::cout << "Introduceti coordonatele centrului.\n";
    std::cout << "x: ";
    std::cin >> c.centru.x;
    std::cout << "y: ";
    std::cin >> c.centru.y;

    return is;
}