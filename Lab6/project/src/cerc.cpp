#include "../include/cerc.hpp"
#include <cmath>

Cerc::Cerc()
    : centru(),
      raza()
{}

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

bool Cerc::seAflaInCadranul1() const {
    return this->centru.x - this->raza > 0 && this->centru.y - this->raza > 0;
}

bool Cerc::operator>(const Cerc &other) const {
    return this->raza > other.raza;
}

bool Cerc::operator==(const Cerc &other) const {
    return this->centru == other.centru && this->raza == other.raza;
}

std::ostream& operator<<(std::ostream &os, const Cerc& c) {
    os << "Cerc(centru: " << c.centru << ", raza:" << c.raza << ")";
    return os;
}