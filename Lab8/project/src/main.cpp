#include <iostream>
#include "../include/entitati/cheltuiala.hpp"
#include "../include/entitati/tranzactie.hpp"
#include "../include/service/service_tranzactii.hpp"
#include "../include/service/service_cheltuieli.hpp"
#include "../include/teste.hpp"

void test_service_cheltuieli();

int main() {
    Teste();

    Repo<Tranzactie> repo;
    ServiceTranzactie service(&repo);

    service.add(Tranzactie(500, Tranzactie::Tip::out, "chirie"));
    service.add(Tranzactie(2300, Tranzactie::Tip::in, "salariu"));

    auto all = service.getAll();

    for (const auto &t : all)
        std::cout << t << "\n";


}

inline void test_service_cheltuieli() {
    Repo<Cheltuiala> repo;
    ServiceCheltuieli service(&repo);

    service.add(Cheltuiala(15, Cheltuiala::Tip::haine, 10));
    service.add(Cheltuiala(50, Cheltuiala::Tip::haine, 13));
    service.add(Cheltuiala(148, Cheltuiala::Tip::haine, 23));
    service.add(Cheltuiala(43, Cheltuiala::Tip::haine, 5));
    service.add(Cheltuiala(40, Cheltuiala::Tip::internet, 5));

    auto filtered = service.getCheltuieliDeTip(Cheltuiala::Tip::haine, '=', 50);

    for (const auto& e : filtered) {
        std::cout << e << std::endl;
    }

    int sumaHaine = service.getSumaCheltuieliDeTip(Cheltuiala::Tip::haine);

    std::cout << "Suma haine: " << sumaHaine << std::endl;

    int maxCheltuiala = service.getMaxCheltuiala();

    std::cout << "Max cheltuiala: " << maxCheltuiala << std::endl;

    auto sorted_suma = service.getCrescatoareDupaSuma();

    for (const auto& e : sorted_suma) {
        std::cout << e << std::endl;
    }

    auto sorted_zi = service.getCrescatoareDupaZi();

    for (const auto& e : sorted_zi) {
        std::cout << e << std::endl;
    }

    auto filtrate = service.getCheltuieliDeTip(Cheltuiala::Tip::internet);

    for (const auto& e : filtrate) {
        std::cout << e << std::endl;
    }
}
