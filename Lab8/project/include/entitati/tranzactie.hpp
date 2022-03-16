#ifndef TRANZACTIE_HPP
#define TRANZACTIE_HPP

#include <iostream>
#include "entitate.hpp"

class Tranzactie : public Entitate {
public:
    enum class Tip {
        in,
        out
    };

    Tranzactie(int suma_, Tip tip_, std::string descriere_, int ziua_ = -1);
    Tranzactie(const Tranzactie& c);

    int getZiua() const;
    int getSuma() const;
    Tip getTip() const;
    std::string getDescriere() const;

    void setZiua(int ziua_);
    void setSuma(int suma_);
    void setTip(Tip tip_);
    void setDescriere(std::string descriere_);

    friend std::ostream& operator<<(std::ostream& os, const Tranzactie& c);
    friend std::istream& operator>>(std::istream& is, Tranzactie& c);

private:
    int ziua;
    int suma;

    Tip tip;
    std::string descriere;
};

#endif // CHELTUIALA_HPP
