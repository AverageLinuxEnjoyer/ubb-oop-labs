#include "../include/repo.hpp"

template<class T>
Repo<T>::Repo()
    : entitati()
{}

template<class T>
bool Repo<T>::operator==(const Repo<T>& other) const {
    return this->entitati == other.entitati;
}

template<class T>
void Repo<T>::add(const T& e) {
    this->entitati.emplace_back(e);
}

template<class T>
void Repo<T>::update(int index, const T& e) {
    this->entitati[index] = e;
}

template<class T>
void Repo<T>::remove(int index) {
    this->entitati.erase(this->entitati.begin() + index);
}

template<class T>
const std::vector<T>& Repo<T>::getAll() const {
    return this->entitati;
}

template<class T>
const T& Repo<T>::get(int index) const {
    return this->entitati[index];
}

template<class T>
int Repo<T>::getSize() const {
    return this->entitati.size();
}

#include "../include/entitati/entitate.hpp"
#include "../include/entitati/cheltuiala.hpp"
#include "../include/entitati/tranzactie.hpp"
template class Repo<Entitate>;
template class Repo<Cheltuiala>;
template class Repo<Tranzactie>;