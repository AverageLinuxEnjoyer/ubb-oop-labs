#include "../../include/undo_redo/adaugare.hpp"

template<class T>
Adaugare<T>::Adaugare(T entitate_, Service<T> *service_)
    : entitate(entitate_),
      Operatie<T>(service_)
{
    for (int i = 0; i < this->service->getSize(); i++) {
        if (this->service->get(i) == this->entitate) {
            this->index = i;
            break;
        }
    }
}

template<class T>
void Adaugare<T>::execute() {
    this->service->add(entitate);
}

template<class T>
void Adaugare<T>::unexecute() {
    this->service->remove(index);
}

#include "../../include/entitati/entitate.hpp"
template class Adaugare<Entitate>;