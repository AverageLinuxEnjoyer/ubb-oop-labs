#include "../include/container_entitati.hpp"

#include "../include/cerc.hpp"
#include "../include/dreptunghi.hpp"
#include "../include/triunghi.hpp"
#include "../include/numar_complex.hpp"
#include "../include/patrat.hpp"

#include <iostream>
#include <algorithm>


template<class T>
ContainerEntitati<T>::ContainerEntitati()
    : entitati()
{}

template<class T>
void ContainerEntitati<T>::adauga(T *entitate)
{
    entitati.push_back(*entitate);
}

template<class T>
void ContainerEntitati<T>::sterge(int index)
{
    entitati.erase(entitati.begin() + index);
}

template<class T>
const std::vector<T>& ContainerEntitati<T>::get() const
{
    return this->entitati;
}

template<class T>
const T& ContainerEntitati<T>::get(int index) const
{
    return this->entitati[index];
}

template<class T>
int ContainerEntitati<T>::getNrEntitati() const
{
    return this->entitati.size();
}

template<class T>
int ContainerEntitati<T>::getCapacitate() const
{
    return this->entitati.capacity();
}

template<class T>
const T& ContainerEntitati<T>::getCeaMaiMareEntitate() const
{
    return *std::max_element(this->entitati.begin(), this->entitati.end(), [](const T& a, const T& b) {
        return !(a > b);
    });
};

template<class T>
std::vector<T> ContainerEntitati<T>::entitatiInPrimulCadran() const
{
    std::vector<T> entitatiInCadran;
    
    std::copy_if(
        this->entitati.begin(), 
        this->entitati.end(),
        std::back_inserter(entitatiInCadran),
        [](T x){
            return x.seAflaInCadranul1();
        } 
    );

    return entitatiInCadran;
}

template<class T>
std::pair<int,int> ContainerEntitati<T>::ceaMaiLungaSubsecventa() const
{
    int start = 0, end = 0;

    for (int i = 0; i < this->entitati.size() - 1; i++) {
        for (int j = i + 1; j < this->entitati.size(); j++) 
        {
            if (!(this->entitati[i] == this->entitati[j])) {
                break;
            }
            else if (j == this->entitati.size() - 1) {
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
    for (int i = 0; i < this->entitati.size(); i++) {
        std::cout << this->entitati[i] << std::endl;
    }
}

template class ContainerEntitati<Cerc>;
template class ContainerEntitati<Dreptunghi>;
template class ContainerEntitati<Triunghi>;
template class ContainerEntitati<NumarComplex>;
template class ContainerEntitati<Patrat>;
