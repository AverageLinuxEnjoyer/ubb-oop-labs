#include "../include/patrat.hpp"

Patrat::Patrat()
    : latura(),
      centru()
{}

Patrat::Patrat(double latura_, Vector2 centru_) 
    : latura(latura_), centru(centru_) 
{}

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

bool Patrat::seAflaInCadranul1() const {
    return this->centru.x - this->latura / 2.0 > 0 && this->centru.y - this->latura / 2.0 > 0;
}

bool Patrat::operator>(const Patrat &other) const {
    return this->latura > other.latura;
}

bool Patrat::operator==(const Patrat &other) const {
    return this->latura == other.latura && this->centru == other.centru;
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