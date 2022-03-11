#include "../include/numar_complex.hpp"

NumarComplex::NumarComplex(double real_, double imaginar_)
    : real(real_),
      imaginar(imaginar_)
{}

double NumarComplex::getRe() const {
    return this->real;
}

double NumarComplex::getIm() const {
    return this->imaginar;
}

void NumarComplex::setRe(double real_) {
    this->real = real_;
}

void NumarComplex::setIm(double imaginar_) {
    this->imaginar = imaginar_;
}

NumarComplex NumarComplex::operator+(const NumarComplex& other) const {
    return NumarComplex(this->real + other.real, this->imaginar + other.imaginar);
}

NumarComplex NumarComplex::operator-(const NumarComplex& other) const {
    return NumarComplex(this->real - other.real, this->imaginar - other.imaginar);
}

NumarComplex NumarComplex::operator*(const NumarComplex& other) const {
    return NumarComplex(this->real * other.real - this->imaginar * other.imaginar,
                        this->real * other.imaginar + this->imaginar * other.real);
}

NumarComplex NumarComplex::operator/(const NumarComplex& other) const {
    return NumarComplex((this->real * other.real + this->imaginar * other.imaginar) / (other.real * other.real + other.imaginar * other.imaginar),
                        (this->imaginar * other.real - this->real * other.imaginar) / (other.real * other.real + other.imaginar * other.imaginar));
}

bool NumarComplex::seAflaInCadranul1() const {
    return this->real > 0 && this->imaginar > 0;
}

bool NumarComplex::operator>(const NumarComplex& other) const {
    return this->real > other.real;
}

bool NumarComplex::operator==(const NumarComplex& other) const {
    return this->real == other.real && this->imaginar == other.imaginar;
}

std::ostream& operator<<(std::ostream& os, const NumarComplex& nr) {
    os << nr.real << "+" << nr.imaginar << "i";
    return os;
}