#include "../../include/entitati/entitate.hpp"
#include <string.h>

Entitate::Entitate(const char* nume_)
    : nume(nume_)
{}

Entitate::Entitate(const Entitate& e)
    : Entitate(e.nume)
{}

const char* Entitate::getNume() const {
    return this->nume;
}

void Entitate::setNume(const char* nume_) {
    this->nume = nume_;
}

Entitate& Entitate::operator=(const Entitate& other) {
    if (this != &other) {
        this->nume = other.nume;
    }
    return *this;
}

bool Entitate::operator==(const Entitate& other) const {
    return strcmp(this->nume, other.nume) == 0;
}

std::ostream& operator<<(std::ostream& os, const Entitate& e) {
    os << "Entitate(\"" << e.nume << "\")";
    return os;
}