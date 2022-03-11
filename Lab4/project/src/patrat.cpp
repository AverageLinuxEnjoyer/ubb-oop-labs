#include "../include/patrat.hpp"

Patrat::Patrat(double latura_, Vector2 centru_) 
    : latura(latura_), centru(centru_) 
{
}

double Patrat::getLatura() const {
    return this->latura;
}

void Patrat::setLatura(double latura_) {
    this->latura = latura_;
}

double Patrat::arie() const {
    return this->latura * this->latura;
}

double Patrat::perimetru() const {
    return 4 * this->latura;
}

Vector2 Patrat::getCentru() const {
    return this->centru; 
}

void Patrat::setCentru(const Vector2 &centru) {
    this->centru = centru;
}

std::ostream& operator<<(std::ostream &os, const Patrat& p) {
    os << "Patrat(centru: " << p.centru << ", latura:" << p.latura << ")";

    return os;
}

std::istream& operator>>(std::istream& is, Patrat& p) {
    std::cout << "Introduceti latura: ";
    std::cin >> p.latura;

    std::cout << "Introduceti coordonatele centrului.\n";
    std::cout << "x: ";
    std::cin >> p.centru.x;
    std::cout << "y: ";
    std::cin >> p.centru.y;

    return is;
}