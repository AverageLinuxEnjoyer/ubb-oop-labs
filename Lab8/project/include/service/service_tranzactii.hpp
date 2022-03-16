#ifndef SERVICE_TRANZACTII_HPP
#define SERVICE_TRANZACTII_HPP

#include "service.hpp"
#include "../entitati/tranzactie.hpp"

class ServiceTranzactie : public Service<Tranzactie> {
public:
    ServiceTranzactie(Repo<Tranzactie> *repo_ = nullptr);

    std::vector<Tranzactie> getTranzactiiDeTip(Tranzactie::Tip tip, const char relatie = '?', int suma = 0) const;

    int getSumaTranzactiiDeTip(Tranzactie::Tip tip) const;

    int getMaxTranzactie() const;

    std::vector<Tranzactie> getCrescatoareDupaSuma() const;
    std::vector<Tranzactie> getCrescatoareDupaZi() const;

private:

};

#endif // SERVICE_TRANZACTII_HPP