#include "../include/repo.hpp"

Repo::Repo()
    : entitati()
{}

Repo::Repo(const Repo& r)
    : entitati(r.entitati)
{}

Repo& Repo::operator=(const Repo& other) {
    if (this != &other) {
        this->entitati = other.entitati;
    }
    return *this;
}

bool Repo::operator==(const Repo& other) const {
    return this->entitati == other.entitati;
}

void Repo::add(const Entitate& e) {
    this->entitati.emplace_back(e);
}

const std::vector<Entitate>& Repo::getAll() const {
    return this->entitati;
}

int Repo::getSize() const {
    return this->entitati.size();
}
