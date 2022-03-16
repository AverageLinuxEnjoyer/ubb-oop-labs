#include "../../include/service/service_cheltuieli.hpp"

std::vector<Cheltuiala> ServiceCheltuieli::getCheltuieliDeTip(Cheltuiala::Tip tip, const char relatie, int suma) const {
    auto filtered = this->getAllCuProprietate([&](const Cheltuiala& c) {
        return (
            c.getTip() == tip &&
            relatie == '?' ? true : (relatie == '=' ? c.getSuma() == suma : (relatie == '>' ? c.getSuma() > suma : c.getSuma() < suma))
        );
    });

    return filtered;
}

int ServiceCheltuieli::getSumaCheltuieliDeTip(Cheltuiala::Tip tip) const {
    int suma = 0;
    for(const auto& e : this->getAll())
        if(e.getTip() == tip)
            suma += e.getSuma();

    return suma;
}

int ServiceCheltuieli::getMaxCheltuiala() const {
    int max = 0;
    for(const auto& e : this->getAll())
        if(e.getSuma() > max)
            max = e.getSuma();

    return max;
}

std::vector<Cheltuiala> ServiceCheltuieli::getCrescatoareDupaSuma() const {
    auto sorted = this->getSortedBy([](const Cheltuiala& c1, const Cheltuiala& c2) {
        return c1.getSuma() < c2.getSuma();
    });

    return sorted;
}

std::vector<Cheltuiala> ServiceCheltuieli::getCrescatoareDupaZi() const {
    auto sorted = this->getSortedBy([](const Cheltuiala& c1, const Cheltuiala& c2) {
        return c1.getZiua() < c2.getZiua();
    });

    return sorted;
}

ServiceCheltuieli::ServiceCheltuieli(Repo<Cheltuiala> *repo_)
    : Service<Cheltuiala>(repo_)
{}

