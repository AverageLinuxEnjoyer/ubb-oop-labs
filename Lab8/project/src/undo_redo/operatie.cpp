#include "../../include/undo_redo/operatie.hpp"

template<class T>
Operatie<T>::Operatie(Service<T> *service_)
    : service(service_)
{
}

#include "../../include/entitati/entitate.hpp"
template class Operatie<Entitate>;