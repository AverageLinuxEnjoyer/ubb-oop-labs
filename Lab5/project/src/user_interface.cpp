#include "../include/user_interface.hpp"

#include "../include/cerc.hpp"
#include "../include/dreptunghi.hpp"
#include "../include/patrat.hpp"
#include "../include/triunghi.hpp"
#include "../include/numar_complex.hpp"

#include <iostream>

template<class T>
UserInterface<T>::UserInterface()
    : entitati()
{}

template<class T>
void UserInterface<T>::run()
{
    int optiune;
    while (true) {
        std::cout << "1. Adauga entitate\n";
        std::cout << "2. Sterge entitate\n";
        std::cout << "3. Afiseaza entitati\n";
        std::cout << "4. Afiseaza cea mai mare entitate\n";
        std::cout << "5. Afiseaza entitati in primul cadran\n";
        std::cout << "6. Afiseaza cea mai lunga subsecventa de entitati egale.\n";
        std::cout << "7. Iesire\n\n";

        std::cout << "Optiune: ";
        std::cin >> optiune;
        std::cout << "\n";

        switch (optiune) {
            case 1: {
                T *entitate = new T();
                std::cin >> *entitate; 

                this->entitati.adauga(entitate);
                break;
            }
            case 2: {
                int index;
                std::cout << "Introduceti indexul entitatii: ";
                std::cin >> index;
                this->entitati.sterge(index);
                break;
            }
            case 3: {
                this->entitati.printEntitati();
                break;
            }
            case 4: {
                T *cea_mai_mare_entitate = this->entitati.getCeaMaiMareEntitate();
                std::cout << "Cea mai mare entitate este: " << *cea_mai_mare_entitate << "\n";
                break;
            }
            case 5: {
                std::vector<T> entitati_in_primul_cadran = this->entitati.entitatiInPrimulCadran();
                std::cout << "Entitatile in primul cadran sunt: ";
                for (auto &entitate : entitati_in_primul_cadran) {
                    std::cout << entitate << "\n";
                }
                std::cout << "\n";
                break;
            }
            case 6: {
                std::pair<int, int> cea_mai_lunga_subsecventa = this->entitati.ceaMaiLungaSubsecventa();
                std::cout << "Cea mai lunga subsecventa de entitati egale este: ";
                for (int i = cea_mai_lunga_subsecventa.first; i <= cea_mai_lunga_subsecventa.second; i++) {
                    std::cout << *this->entitati.get(i) << "\n";
                }
                std::cout << "\n";
                break;
            }
            case 7: {
                return;
            }
            default: {
                std::cout << "Optiune invalida! Introduceti din nou.\n";
            }
        }
    }
}

template class UserInterface<Cerc>;
template class UserInterface<Dreptunghi>;
template class UserInterface<Patrat>;
template class UserInterface<Triunghi>;
template class UserInterface<NumarComplex>;