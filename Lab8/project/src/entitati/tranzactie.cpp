#include "../../include/entitati/tranzactie.hpp"

#include <chrono>
#include <ctime>


int getDayOfTheMonth2()
{
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);
    std::tm bt = *std::localtime(&in_time_t);

    return bt.tm_mday;
}

std::string tipToStr2(Tranzactie::Tip tip)
{
    switch (tip)
    {
    case Tranzactie::Tip::in:
        return "in";
    case Tranzactie::Tip::out:
        return "out";
    default:
        return "";
    }
}

Tranzactie::Tranzactie(int suma_, Tip tip_, std::string descriere_, int ziua_)
    : ziua(ziua_),
      suma(suma_),
      tip(tip_),
      descriere(descriere_)
{
    if (this->ziua == -1)
        this->ziua = getDayOfTheMonth2();
}

Tranzactie::Tranzactie(const Tranzactie& t)
    : Tranzactie(t.suma, t.tip, t.descriere, t.ziua)
{}

int Tranzactie::getZiua() const {
    return this->ziua;
}

int Tranzactie::getSuma() const {
    return this->suma;
}

Tranzactie::Tip Tranzactie::getTip() const {
    return this->tip;
}

void Tranzactie::setZiua(int ziua_) {
    this->ziua = ziua_;
}

void Tranzactie::setSuma(int suma_) {
    this->suma = suma_;
}

void Tranzactie::setTip(Tip tip_) {
    this->tip = tip_;
}

std::ostream& operator<<(std::ostream& os, const Tranzactie& c)
{
    os << "Cheltuiala(ziua:" << c.getZiua() << ", suma:" << c.getSuma() << ", tip:" << tipToStr2(c.getTip()) << ")";

    return os;
}

std::istream& operator>>(std::istream& is, Tranzactie& c)
{
    int ziua;
    int suma;
    std::string tip;

    std::cout << "Ziua: ";
    is >> ziua;

    std::cout << "Suma: ";
    is >> suma;

    std::cout << "Tip: ";
    is >> tip;

    c.setZiua(ziua);
    c.setSuma(suma);
    c.setTip(Tranzactie::Tip::in);

    if (tip == "in")
        c.setTip(Tranzactie::Tip::in);
    else if (tip == "out")
        c.setTip(Tranzactie::Tip::out);

    return is;
}

void Tranzactie::setDescriere(std::string descriere_) {
    this->descriere = descriere_;
}
