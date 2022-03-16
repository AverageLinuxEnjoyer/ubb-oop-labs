#ifndef SERVICE_CHELTUIELI_HPP
#define SERVICE_CHELTUIELI_HPP

#include "service.hpp"
#include "../entitati/cheltuiala.hpp"

class ServiceCheltuieli : public Service<Cheltuiala> {
public:
    ServiceCheltuieli(Repo<Cheltuiala> *repo_ = nullptr);

    std::vector<Cheltuiala> getCheltuieliDeTip(Cheltuiala::Tip tip, const char relatie = '?', int suma = 0) const;

    int getSumaCheltuieliDeTip(Cheltuiala::Tip tip) const;
    int getMaxCheltuiala() const;
    std::vector<Cheltuiala> getCrescatoareDupaSuma() const;
    std::vector<Cheltuiala> getCrescatoareDupaZi() const;

private:

};

#endif // SERVICE_CHELTUIELI_HPP
