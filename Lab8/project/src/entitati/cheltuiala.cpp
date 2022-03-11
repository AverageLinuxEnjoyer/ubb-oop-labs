#include "../../include/entitati/cheltuiala.hpp"

#include <chrono>
#include <ctime>


int getDayOfTheMonth()
{
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);
    std::tm bt = *std::localtime(&in_time_t);

    return bt.tm_mday;
}

std::string tipToStr(Cheltuiala::Tip tip)
{
    switch (tip)
    {
    case Cheltuiala::Tip::menaj:
        return "menaj";
    case Cheltuiala::Tip::mancare:
        return "mancare";
    case Cheltuiala::Tip::transport:
        return "transport";
    case Cheltuiala::Tip::haine:
        return "haine";
    case Cheltuiala::Tip::internet:
        return "internet";
    case Cheltuiala::Tip::altele:
        return "altele";
    default:
        return "";
    }
}

Cheltuiala::Cheltuiala(int suma_, Tip tip_, int ziua_)
    : ziua(ziua_),
      suma(suma_),
      tip(tip_)
{
    if (this->ziua == -1)
        this->ziua = getDayOfTheMonth();
}

Cheltuiala::Cheltuiala(const Cheltuiala& c)
    : Cheltuiala(c.suma, c.tip, c.ziua)
{}

int Cheltuiala::getZiua() const {
    return this->ziua;
}

int Cheltuiala::getSuma() const {
    return this->suma;
}

Cheltuiala::Tip Cheltuiala::getTip() const {
    return this->tip;
}

void Cheltuiala::setZiua(int ziua_) {
    this->ziua = ziua_;
}

void Cheltuiala::setSuma(int suma_) {
    this->suma = suma_;
}

void Cheltuiala::setTip(Tip tip_) {
    this->tip = tip_;
}

std::ostream& operator<<(std::ostream& os, const Cheltuiala& c)
{
    os << "Cheltuiala(ziua:" << c.getZiua() << ", suma:" << c.getSuma() << ", tip:" << tipToStr(c.getTip()) << ")";

    return os;
}

std::istream& operator>>(std::istream& is, Cheltuiala& c)
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
    c.setTip(Cheltuiala::Tip::altele);

    if (tip == "menaj")
        c.setTip(Cheltuiala::Tip::menaj);
    else if (tip == "mancare")
        c.setTip(Cheltuiala::Tip::mancare);
    else if (tip == "transport")
        c.setTip(Cheltuiala::Tip::transport);
    else if (tip == "haine")
        c.setTip(Cheltuiala::Tip::haine);
    else if (tip == "internet")
        c.setTip(Cheltuiala::Tip::internet);
    else
        c.setTip(Cheltuiala::Tip::altele);

    return is;
}