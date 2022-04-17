#include "../include/service.hpp"

#include "../include/undoredo/undo_redo_handler.hpp"
#include "../include/undoredo/operatie.hpp"
#include "../include/undoredo/adaugare.hpp"
#include "../include/undoredo/stergere.hpp"

#include <algorithm>

Service::Service(Repo *repo_, UndoRedoHandler *undoRedoHandler_)
    : repo(repo_), undo_redo_handler(undoRedoHandler_)
{}

bool Service::operator==(const Service& other) const {
    return this->repo == other.repo;
}

void Service::setRepo(Repo *repo_) {
    this->repo = repo_;
}

const std::vector<Cheltuiala>& Service::getAll() const {
    return this->repo->getAll();
}

Cheltuiala Service::get(int index) const {
    if (this->repo == nullptr) {
        throw std::exception();
    }

    return this->repo->get(index);
}

std::vector<Cheltuiala> Service::getAllCuProprietate(std::function<bool(const Cheltuiala&)> functie) const {
    std::vector<Cheltuiala> filtered;
    for (const auto& e : this->repo->getAll()) {
        if (functie(e)) {
            filtered.emplace_back(e);
        }
    }

    return filtered;
}

std::vector<Cheltuiala> Service::getSortedBy(std::function<bool(const Cheltuiala&, const Cheltuiala&)> functie) const {
    std::vector<Cheltuiala> sorted(this->repo->getAll());

    std::sort(sorted.begin(), sorted.end(), functie);

    return sorted;
}


void Service::filter(std::function<bool(const Cheltuiala&)> functie, bool undoredo) {
    std::vector<int> indexes;
    for (int i = 0; i < this->repo->getSize(); i++)
        if (!functie(this->repo->get(i)))
            indexes.emplace_back(i);

    this->remove(indexes, undoredo);
}

std::vector<Cheltuiala> Service::getCheltuieliDeTip(Cheltuiala::Tip tip, const char relatie, int suma) const {
    auto filtered = this->getAllCuProprietate([&](const Cheltuiala& c) {
        return (
            c.getTip() == tip &&
            (relatie == '?' ? true : (relatie == '=' ? c.getSuma() == suma : (relatie == '>' ? c.getSuma() > suma : c.getSuma() < suma)))
        );
    });

    return filtered;
}

std::vector<Cheltuiala> Service::filter(Cheltuiala::Tip tip, const char relatie, int suma, bool undoredo) {
    auto filtered = this->getCheltuieliDeTip(tip, relatie, suma);

    auto all = this->getAll();
    std::vector<int> indexes;
    for (int i = 0; i < all.size(); i++)
        for (int j = 0; j < filtered.size(); j++)
            if (all[i] == filtered[j])
            {
                std::cout << "de filtrat: " << i << std::endl;
                indexes.push_back(i);
            }

    this->remove(indexes, undoredo);

    return filtered;
}

int Service::getSumaCheltuieliDeTip(Cheltuiala::Tip tip) const {
    int suma = 0;
    for(const auto& e : this->getAll())
        if(e.getTip() == tip)
            suma += e.getSuma();

    return suma;
}

int Service::getMaxCheltuiala() const {
    int max = 0;
    for(const auto& e : this->getAll())
        if(e.getSuma() > max)
            max = e.getSuma();

    return max;
}

std::vector<Cheltuiala> Service::getCrescatoareDupaSuma() const {
    auto sorted = this->getSortedBy([](const Cheltuiala& c1, const Cheltuiala& c2) {
        return c1.getSuma() < c2.getSuma();
    });

    return sorted;
}

std::vector<Cheltuiala> Service::getCrescatoareDupaZi() const {
    auto sorted = this->getSortedBy([](const Cheltuiala& c1, const Cheltuiala& c2) {
        return c1.getZiua() < c2.getZiua();
    });

    return sorted;
}

void Service::add(const Cheltuiala& e, bool undoredo, int index) {
    if (this->repo == nullptr)
        throw std::exception();
    
    if (index != -1)
        this->repo->add(e, index);
    else
        this->repo->add(e);

    if (undoredo)
        this->undo_redo_handler->add(new Adaugare(e, this));
}

void Service::update(int index, const Cheltuiala& e) {
    if (this->repo == nullptr)
        throw std::exception();

    this->repo->update(index, e);
}

void Service::remove(std::vector<int> indexes, bool undoredo) {
    if (this->repo == nullptr)
        throw std::exception();
        
    if (undoredo)
        this->undo_redo_handler->add(new Stergere(indexes, this));

    this->repo->remove(indexes);
}

int Service::getSize() const {
    if (this->repo == nullptr) {
        throw std::exception();
    }

    return this->repo->getSize();
}

void Service::undo() {
    if (this->undo_redo_handler)
        this->undo_redo_handler->undo();
}

void Service::redo() {
    if (this->undo_redo_handler)
        this->undo_redo_handler->redo();
}
