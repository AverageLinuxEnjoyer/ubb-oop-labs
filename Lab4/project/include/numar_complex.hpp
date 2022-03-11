#ifndef NUMAR_COMPLEX_HPP
#define NUMAR_COMPLEX_HPP

#include <iostream>

class NumarComplex {
public:
    // constructor
    NumarComplex(double real_ = 0.0, double imaginar_ = 0.0);

    // destructor
    ~NumarComplex() = default;

    // getteri
    double getRe() const;
    double getIm() const;

    // setteri
    void setRe(double real_);
    void setIm(double imaginar_);

    // overload la operatori aritmetici
    NumarComplex operator+(const NumarComplex& other) const;
    NumarComplex operator-(const NumarComplex& other) const;
    NumarComplex operator*(const NumarComplex& other) const;
    NumarComplex operator/(const NumarComplex& other) const;

    // overload la left shift operator
    friend std::ostream& operator<<(std::ostream& os, const NumarComplex& nr);
    friend std::istream& operator>>(std::istream& is, NumarComplex& nr); 

private:
    double real;
    double imaginar;
};

#endif // NUMAR_COMPLEX_HPP
