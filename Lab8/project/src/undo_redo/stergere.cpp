#include "../../include/undo_redo/stergere.hpp"

template<class T>
Stergere<T>::Stergere(std::vector<int> indexes_, Service<T> *service_)
    :  indexes(indexes_),
       Operatie<T>(service_)
{
    this->entitati.resize(indexes.size());
    for (int i = 0; i < indexes.size(); i++) {
        this->entitati[i] = this->service->get(i);
    }
}

template<class T>
void Stergere<T>::execute() {
    for (int i = 0; i < indexes.size(); i++) {
        this->service->remove(indexes[i]);
    }   
}

template<class T>
void Stergere<T>::unexecute() {
    for(const auto &entitate : this->entitati) {
        this->service->add(entitate);
    }
}

#include "../../include/entitati/entitate.hpp"
template class Stergere<Entitate>;