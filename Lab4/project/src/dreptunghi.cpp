#include "../include/dreptunghi.hpp"


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

std::ostream& operator<<(std::ostream &os, const Dreptunghi& d) {
    os << "Dreptunghi(centru: " << d.centru << ", lungime:" << d.lungime << ", latime:" << d.latime << ")";

    return os;
}

std::istream& operator>>(std::istream& is, Dreptunghi& d) {
    std::cout << "Introduceti lungimea si latimea: ";
    std::cout << "Lungime: ";
    std::cin >> d.lungime;
    std::cout << "Latime: ";
    std::cin >> d.latime;

    std::cout << "Introduceti coordonatele centrului.\n";
    std::cout << "x: ";
    std::cin >> d.centru.x;
    std::cout << "y: ";
    std::cin >> d.centru.y;

    return is;
}