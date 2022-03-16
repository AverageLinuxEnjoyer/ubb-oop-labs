#include "../../include/service/service_tranzactii.hpp"

ServiceTranzactie::ServiceTranzactie(Repo<Tranzactie> *repo_)
    : Service(repo_)
{}

std::vector<Tranzactie> ServiceTranzactie::getTranzactiiDeTip(Tranzactie::Tip tip, const char relatie, int suma) const {
    auto filtered = this->getAllCuProprietate([&](const Tranzactie& t) {
        return (
            t.getTip() == tip &&
            relatie == '?' ? true : (relatie == '=' ? t.getSuma() == suma : (relatie == '>' ? t.getSuma() > suma : t.getSuma() < suma))
        );
    });

    return filtered;
}

int ServiceTranzactie::getSumaTranzactiiDeTip(Tranzactie::Tip tip) const {
    int suma = 0;
    for(const auto& e : this->getAll())
        if(e.getTip() == tip)
            suma += e.getSuma();

    return suma;
}

int ServiceTranzactie::getMaxTranzactie() const {
    int max = 0;
    for(const auto& e : this->getAll())
        if(e.getSuma() > max)
            max = e.getSuma();

    return max;
}

std::vector<Tranzactie> ServiceTranzactie::getCrescatoareDupaSuma() const {
    auto sorted = this->getSortedBy([](const Tranzactie& t1, const Tranzactie& t2) {
        return t1.getSuma() < t2.getSuma();
    });

    return sorted;
}

std::vector<Tranzactie> ServiceTranzactie::getCrescatoareDupaZi() const {
    auto sorted = this->getSortedBy([](const Tranzactie& t1, const Tranzactie& t2) {
        return t1.getZiua() < t2.getZiua();
    });

    return sorted;
}

