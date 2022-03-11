#include "../include/dreptunghi.hpp"


Dreptunghi::Dreptunghi()
{}

Dreptunghi::Dreptunghi(int lungime_, int latime_, Vector2 centru_)
    : lungime(lungime_),
      latime(latime_),
      centru(centru_)
{}

int Dreptunghi::getLungime() const {
    return this->lungime;
}

int Dreptunghi::getLatime() const {
    return this->latime;
}

Vector2 Dreptunghi::getCentru() const {
    return this->centru;
}

void Dreptunghi::setLungime(int lungime_) {
    this->lungime = lungime_;
}

void Dreptunghi::setLatime(int latime_) {
    this->latime = latime_;
}

void Dreptunghi::setCentru(Vector2 centru_) {
    this->centru = centru_;
}

int Dreptunghi::arie() const {
    return this->lungime * this->latime;
}

int Dreptunghi::perimetru() const {
    return 2 * (this->lungime + this->latime);
}

bool Dreptunghi::seAflaInCadranul1() const {
    return this->centru.x - this->lungime / 2.0 > 0 && this->centru.y - this->latime / 2.0 > 0;
}

bool Dreptunghi::operator>(const Dreptunghi &other) const {
    return this->arie() > other.arie();
}

bool Dreptunghi::operator==(const Dreptunghi &other) const {
    return this->lungime == other.lungime && this->latime == other.latime;
}

std::ostream& operator<<(std::ostream &os, const Dreptunghi& d) {
    os << "Dreptunghi(centru: " << d.centru << ", lungime:" << d.lungime << ", latime:" << d.latime << ")";

    return os;
}