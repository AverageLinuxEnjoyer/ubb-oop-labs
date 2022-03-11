#ifndef PATRAT_HPP
#define PATRAT_HPP

#include "vector2.hpp"

class Patrat {
public:
    // constructor
    Patrat();
    Patrat(double latura_, Vector2 centru_ = {0, 0});

    // destructor
    ~Patrat() = default;

    // getteri
    double getLatura() const;
    Vector2 getCentru() const;

    // setteri
    void setLatura(double latura_);
    void setCentru(const Vector2 &centru);

    // arie si perimetru
    double arie() const;
    double perimetru() const;

    bool seAflaInCadranul1() const;

    // operatori
    bool operator>(const Patrat &other) const;
    bool operator==(const Patrat &other) const;
    friend std::ostream& operator<<(std::ostream& os, const Patrat& p);

private:
    double latura;
    Vector2 centru;    
};

#endif // PATRAT_HPP
