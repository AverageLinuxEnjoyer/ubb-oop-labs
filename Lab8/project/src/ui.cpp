#include "../include/ui.hpp"
#include <iostream>
#include <sstream>

UserInterface::UserInterface(Service &service)
    : service(service)
{}

void UserInterface::run() {
    std::string entire_command;

    auto split = [](std::string text, char delim) {
        std::string line;
        std::vector<std::string> vec;
        std::stringstream ss(text);
        while(std::getline(ss, line, delim)) {
            vec.push_back(line);
        }
        return vec;
    };

    while(true) 
    {
        std::cout << "> ";
        std::getline(std::cin, entire_command);
        this->arguments = split(entire_command, ' ');

        std::string command = this->arguments[0];
        this->arguments.erase(this->arguments.begin());

        if (command == " ")
            continue;
        else if (command == "adauga")
            this->adaugare();
        else if (command == "elimina")
            this->stergere();
        else if (command == "listeaza")
            this->listare();
        else if (command == "filtrare")
            this->filtrare();
        else if (command == "undo")
            this->undo();
        else if (command == "redo")
            this->redo();
        else if (command == "iesire")
            break;
        else
            this->altele(command);
    }
}

void UserInterface::undo()
{
    this->service.undo();
    this->arguments.clear();
}

void UserInterface::redo() {
    this->service.redo();
    this->arguments.clear();
}

Cheltuiala::Tip strToTip(std::string str) {

    if (str == "menaj")
        return Cheltuiala::Tip::menaj;
    else if (str == "mancare")
        return Cheltuiala::Tip::mancare;
    else if (str == "transport")
        return Cheltuiala::Tip::transport;
    else if (str == "haine")
        return Cheltuiala::Tip::haine;
    else if (str == "internet")
        return Cheltuiala::Tip::internet;
    else
        return Cheltuiala::Tip::altele;
}


void UserInterface::adaugare() {
    if (this->arguments.size() == 3 || this->arguments.size() == 2)
    {
        int ziua = -1;
        if (this->arguments.size() == 3)
        {
            ziua = std::stoi(this->arguments[0]);
            this->arguments.erase(this->arguments.begin());
        }

        int suma = std::stoi(this->arguments[0]);
        this->arguments.erase(this->arguments.begin());

        Cheltuiala::Tip tip = strToTip(this->arguments[0]);
        this->arguments.erase(this->arguments.begin());

        this->service.add(Cheltuiala(suma, tip, ziua), true);

        std::cout << "Cheltuiala adaugata cu succes!\n";
    }
    else 
        std::cout << "A fost introdus un numar incorect de parametrii.\n";
}

void UserInterface::stergere() {
    std::vector<int> indexes;
    auto cheltuieli = this->service.getAll();

    if (this->arguments.size() == 1)
    {
        if  (std::isdigit(this->arguments[0][0]))
        {
            int ziua = std::stoi(this->arguments[0]);
            
            for (int i = 0; i < cheltuieli.size(); i++)
                if (cheltuieli[i].getZiua() == ziua) 
                    indexes.push_back(i);
        }
        else
        {
            Cheltuiala::Tip tip = strToTip(this->arguments[0]);
            
            for (int i = 0; i < cheltuieli.size(); i++)
                if (cheltuieli[i].getTip() == tip) 
                    indexes.push_back(i);
        }
    }
    else if (this->arguments.size() == 3)
    {
        int ziua1 = std::stoi(this->arguments[0]);
        int ziua2 = std::stoi(this->arguments[2]);

        for (int i = 0; i < cheltuieli.size(); i++)
            for (int j = ziua1; j <= ziua2; j++)
                if (cheltuieli[i].getZiua() == j) 
                    indexes.push_back(i);
    }
    else
        std::cout << "A fost introdus un numar incorect de parametrii.\n";

    if (indexes.size() == 0)
        std::cout << "Nu exista cheltuieli de sters.\n";
    else
    {
        this->service.remove(indexes, true);

        std::cout << "Cheltuielile au fost sterse cu succes!\n";
    }
}

void UserInterface::listare() {
    if (this->arguments.size() == 0)
    {
        std::cout << "Lista cheltuieli:\n";
        std::vector<Cheltuiala> cheltuieli = this->service.getAll();
        for (auto cheltuiala : cheltuieli)
            std::cout << cheltuiala << "\n";
    }
    else if (this->arguments.size() == 1 || this->arguments.size() == 3)
    {
        int suma = 0;
        char relatie = '?';
        if (this->arguments.size() == 3)
        {
            suma = std::stoi(this->arguments[2]);
            this->arguments.pop_back();

            relatie = this->arguments[1][0];
            this->arguments.pop_back();
        }

        Cheltuiala::Tip tip = strToTip(this->arguments[0]);

        std::vector<Cheltuiala> cheltuieli = this->service.getCheltuieliDeTip(tip, relatie, suma);

        std::cout << "Lista cheltuieli:\n";
        for (auto cheltuiala : cheltuieli)
            std::cout << cheltuiala << "\n";

    }
    else
        std::cout << "A fost introdus un numar incorect de parametrii.\n";
}

void UserInterface::filtrare() {
    if (this->arguments.size() == 1 || this->arguments.size() == 3)
    {
        int suma = 0;
        char relatie = '?';
        if (this->arguments.size() == 3)
        {
            suma = std::stoi(this->arguments[2]);
            this->arguments.pop_back();

            relatie = this->arguments[1][0];
            this->arguments.pop_back();
        }

        Cheltuiala::Tip tip = strToTip(this->arguments[0]);

        std::vector<Cheltuiala> cheltuieli = this->service.filter(tip, relatie, suma, true);

        std::cout << "Cheltuielile au fost filtrate\n";
    }
    else
        std::cout << "A fost introdus un numar incorect de parametrii.\n";
}

void UserInterface::altele(std::string command) {
    if (this->arguments.size() != 1)
        std::cout << "A fost introdus un numar incorect de parametrii.\n";
    
    if (command == "suma")
    {
        Cheltuiala::Tip tip = strToTip(this->arguments[0]);
        auto cheltuieli = this->service.getAllCuProprietate([&] (Cheltuiala cheltuiala) { return cheltuiala.getTip() == tip; });

        int suma = 0;
        for (auto cheltuiala : cheltuieli)
            suma += cheltuiala.getSuma();

        std::cout << "Suma cheltuielilor de tip " << this->arguments[0] << " este " << suma << ".\n";
    }
    else if (command == "max")
    {
        auto cheltuieli = this->service.getAll();

        int zile[30] {0};

        for (auto cheltuiala : cheltuieli)
            zile[cheltuiala.getZiua() - 1] += cheltuiala.getSuma();

        // find max in zile
        int max = 0;
        int ziua_max = 0;
        for (int i = 0; i < 30; i++)
            if (zile[i] > max)
            {
                max = zile[i];
                ziua_max = i + 1;
            }

        std::cout << "Ziua " << ziua_max << " are cheltuielile maxime de " << max << ".\n";
    }
    else if (command == "sortare")
    {
        if (this->arguments[0] == "zi")
        {
            auto sorted_by_zi = this->service.getSortedBy([](Cheltuiala cheltuiala1, Cheltuiala cheltuiala2) { return cheltuiala1.getZiua() > cheltuiala2.getZiua(); });

            std::cout << "Lista cheltuielilor sortate descrescator dupa zi:\n";
            for (auto cheltuiala : sorted_by_zi)
                std::cout << "Ziua " << cheltuiala.getZiua() << ": " << cheltuiala << "\n";
        }
    }
}
