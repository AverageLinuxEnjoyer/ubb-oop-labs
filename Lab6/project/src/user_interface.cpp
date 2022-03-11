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
                this->meniu_adaugare();
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
                T cea_mai_mare_entitate = this->entitati.getCeaMaiMareEntitate();
                std::cout << "Cea mai mare entitate este: " << cea_mai_mare_entitate << "\n";
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
                    std::cout << this->entitati.get(i) << "\n";
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

template<>
void UserInterface<Cerc>::meniu_adaugare()
{
    int raza;
    double x, y;

    std::cout << "Introduceti raza: ";
    std::cin >> raza;
    
    std::cout << "Introduceti coordonatele centrului.\n";
    std::cout << "x: ";
    std::cin >> x;
    std::cout << "y: ";
    std::cin >> y;

    this->entitati.adauga(new Cerc(raza, {x, y}));
}

template<>
void UserInterface<Dreptunghi>::meniu_adaugare()
{
    double lungime, latime;
    double x, y;

    std::cout << "Introduceti lungimea si latimea: ";
    std::cin >> lungime >> latime;

    std::cout << "Introduceti coordonatele centrului.\n";
    std::cout << "x: ";
    std::cin >> x;
    std::cout << "y: ";
    std::cin >> y;

    this->entitati.adauga(new Dreptunghi(lungime, latime, {x, y}));
}

template<>
void UserInterface<Patrat>::meniu_adaugare()
{
    double latura;
    double x, y;

    std::cout << "Introduceti latura: ";
    std::cin >> latura;

    std::cout << "Introduceti coordonatele centrului.\n";
    std::cout << "x: ";
    std::cin >> x;
    std::cout << "y: ";
    std::cin >> y;

    this->entitati.adauga(new Patrat(latura, {x, y}));
}

template<>
void UserInterface<Triunghi>::meniu_adaugare()
{
    double x1, y1,  x2, y2, x3, y3;

    std::cout << "Introduceti coordonatele celor 3 puncte.\n";
    
    std::cout << "x1: "; 
    std::cin >> x1;
    std::cout << "y1: ";
    std::cin >> y1;

    std::cout << "x2: ";
    std::cin >> x2;
    std::cout << "y2: ";
    std::cin >> y2;

    std::cout << "x3: ";
    std::cin >> x3;
    std::cout << "y3: ";
    std::cin >> y3;

    this->entitati.adauga(new Triunghi({x1, y1}, {x2, y2}, {x3, y3}));
}

template<>
void UserInterface<NumarComplex>::meniu_adaugare()
{
    double real, imaginar;

    std::cout << "Introduceti partea reala si partea imaginara.\n";
    std::cout << "Partea reala: ";
    std::cin >> real;
    std::cout << "Partea imaginara: ";
    std::cin >> imaginar;

    this->entitati.adauga(new NumarComplex(real, imaginar));
}

template class UserInterface<Cerc>;
template class UserInterface<Dreptunghi>;
template class UserInterface<Patrat>;
template class UserInterface<Triunghi>;
template class UserInterface<NumarComplex>;