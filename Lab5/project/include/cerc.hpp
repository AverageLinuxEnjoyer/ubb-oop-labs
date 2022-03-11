#ifndef CERC_HPP
#define CERC_HPP

#include "vector2.hpp"

class Cerc {
public:
    // constructor
    Cerc();
    Cerc(double raza_, Vector2 centru_ = {0,0});

    // destructor
    ~Cerc() = default;

    // getteri
    Vector2 getCentru() const;
    double getRaza() const;

    // setteri
    void setCentru(const Vector2 &centru_);
    void setRaza(double raza_);

    // arie si perimetru
    double arie() const;
    double perimetru() const;

    bool seAflaInCadranul1() const;

    // operatori
    bool operator>(const Cerc &other) const;
    bool operator==(const Cerc &other) const;
    friend std::ostream& operator<<(std::ostream& os, const Cerc& c);
    friend std::istream& operator>>(std::istream& is, Cerc& c);

private:
    Vector2 centru;
    double raza;
};

#endif // CERC_HPP
