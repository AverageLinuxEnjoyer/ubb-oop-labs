#include "../include/container_entitati.hpp"
#include <iostream>

template<class T>
ContainerEntitati<T>::ContainerEntitati()
    : entitati(nullptr), nr_entitati(0), capacitate(10)
{
    this->entitati = new T[this->capacitate];
}

template<class T>
ContainerEntitati<T>::~ContainerEntitati()
{
    if(entitati)
        delete[] this->entitati;
}

template<class T>
void ContainerEntitati<T>::adauga(T *entitate)
{
    if (this->nr_entitati == this->capacitate) {
        this->capacitate *= 2;
        T *aux = new T[this->capacitate];
        for (int i = 0; i < this->nr_entitati; i++) {
            aux[i] = this->entitati[i];
        }
        delete[] this->entitati;
        this->entitati = aux;
    }
    this->entitati[this->nr_entitati++] = *entitate;
}

template<class T>
void ContainerEntitati<T>::sterge(int index)
{
    for (int i = index; i < this->nr_entitati - 1; i++) {
        this->entitati[i] = this->entitati[i + 1];
    }
    this->nr_entitati--;
}

template<class T>
T *ContainerEntitati<T>::get() const
{
    return this->entitati;
}

template<class T>
T *ContainerEntitati<T>::get(int index) const
{
    return &(this->entitati[index]);
}

template<class T>
int ContainerEntitati<T>::getNrEntitati() const
{
    return this->nr_entitati;
}

template<class T>
int ContainerEntitati<T>::getCapacitate() const
{
    return this->capacitate;
}

template<class T>
T *ContainerEntitati<T>::getCeaMaiMareEntitate() const
{
    T *max = &this->entitati[0];
    for (int i = 1; i < this->nr_entitati; i++) {
        if (this->entitati[i] > *max) {
            max = &this->entitati[i];
        }
    }
    return max;
};

template<class T>
std::vector<T> ContainerEntitati<T>::entitatiInPrimulCadran() const
{
    std::vector<T> entitatiInCadran;
    
    for (int i = 0; i < this->nr_entitati; i++) {
        if (this->entitati[i].seAflaInCadranul1()) {
            entitatiInCadran.emplace_back(this->entitati[i]);
        }
    }

    return entitatiInCadran;
}

template<class T>
std::pair<int,int> ContainerEntitati<T>::ceaMaiLungaSubsecventa() const
{
    int start = 0, end = 0;

    for (int i = 0; i < this->nr_entitati - 1; i++) {
        for (int j = i + 1; j < this->nr_entitati; j++) 
        {
            if (!(this->entitati[i] == this->entitati[j])) {
                break;
            }
            else if (j == this->nr_entitati - 1) {
                end = j;
                start = i;
            }
        }
    }

    return std::make_pair(start, end);
}

template<class T>
void ContainerEntitati<T>::printEntitati() const
{
    for (int i = 0; i < this->nr_entitati; i++) {
        std::cout << this->entitati[i] << std::endl;
    }
}

#include "../include/cerc.hpp"
#include "../include/dreptunghi.hpp"
#include "../include/triunghi.hpp"
#include "../include/numar_complex.hpp"
#include "../include/patrat.hpp"

template class ContainerEntitati<Cerc>;
template class ContainerEntitati<Dreptunghi>;
template class ContainerEntitati<Triunghi>;
template class ContainerEntitati<NumarComplex>;
template class ContainerEntitati<Patrat>;
