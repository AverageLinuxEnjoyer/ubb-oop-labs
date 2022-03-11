#ifndef CHELTUIALA_HPP
#define CHELTUIALA_HPP

#include <iostream>
#include "entitate.hpp"

class Cheltuiala : public Entitate {
public:
    enum class Tip {
        menaj,
        mancare,
        transport,
        haine,
        internet,
        altele
    };

    Cheltuiala(int suma_, Tip tip_, int ziua_ = -1);
    Cheltuiala(const Cheltuiala& c);

    int getZiua() const;
    int getSuma() const;
    Tip getTip() const;

    void setZiua(int ziua_);
    void setSuma(int suma_);
    void setTip(Tip tip_);

    friend std::ostream& operator<<(std::ostream& os, const Cheltuiala& c);
    friend std::istream& operator>>(std::istream& is, Cheltuiala& c);

private:
    int ziua;
    int suma;

    Tip tip;
};

#endif // CHELTUIALA_HPP
