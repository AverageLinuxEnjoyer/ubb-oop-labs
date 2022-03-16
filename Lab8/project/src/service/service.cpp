#include "../../include/service/service.hpp"
#include <algorithm>

template<class T>
Service<T>::Service(Repo<T> *repo_)
    : repo(repo_)
{}

template<class T>
bool Service<T>::operator==(const Service<T>& other) const {
    return this->repo == other.repo;
}

template<class T>
void Service<T>::setRepo(Repo<T> *repo_) {
    this->repo = repo_;
}

template<class T>
const std::vector<T>& Service<T>::getAll() const {
    return this->repo->getAll();
}

template<class T>
const T& Service<T>::get(int index) const {
    if (this->repo == nullptr) {
        throw std::exception();
    }

    return this->repo->get(index);
}

template<class T>
std::vector<T> Service<T>::getAllCuProprietate(std::function<bool(const T&)> functie) const {
    std::vector<T> filtered;
    for (const auto& e : this->repo->getAll()) {
        if (functie(e)) {
            filtered.emplace_back(e);
        }
    }

    return filtered;
}

template<class T>
inline std::vector<T> Service<T>::getSortedBy(std::function<bool(const T&, const T&)> functie) const {
    std::vector<T> sorted(this->repo->getAll());

    std::sort(sorted.begin(), sorted.end(), functie);

    return sorted;
}

template<class T>
void Service<T>::add(const T& e) {
    if (this->repo == nullptr) {
        throw std::exception();
    }

    this->repo->add(e);
}

template<class T>
void Service<T>::update(int index, const T& e) {
    if (this->repo == nullptr) {
        throw std::exception();
    }

    this->repo->update(index, e);
}

template<class T>
void Service<T>::remove(int index) {
    if (this->repo == nullptr) {
        throw std::exception();
    }

    this->repo->remove(index);
}

template<class T>
int Service<T>::getSize() const {
    if (this->repo == nullptr) {
        throw std::exception();
    }

    return this->repo->getSize();
}

#include "../../include/entitati/entitate.hpp"
#include "../../include/entitati/cheltuiala.hpp"
#include "../../include/entitati/tranzactie.hpp"
template class Service<Entitate>;
template class Service<Cheltuiala>;
template class Service<Tranzactie>;