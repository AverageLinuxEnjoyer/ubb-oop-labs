#include <iostream>
#include "../include/entitati/cheltuiala.hpp"
#include "../include/service.hpp"
#include "../include/teste.hpp"

int main() {
    Teste teste;

    Repo<Cheltuiala> repo;
    Service<Cheltuiala> service(&repo);

    service.add(Cheltuiala(15, Cheltuiala::Tip::haine, 10));
    service.add(Cheltuiala(400, Cheltuiala::Tip::haine));
    service.add(Cheltuiala(200, Cheltuiala::Tip::haine, 23));
    service.add(Cheltuiala(100, Cheltuiala::Tip::haine, 100));

    auto filtered = service.getAllCuProprietate([](const Cheltuiala& c) {
        return c.getSuma() > 100;
    });

    for (const auto& e : filtered) {
        std::cout << e << std::endl;
    }
}