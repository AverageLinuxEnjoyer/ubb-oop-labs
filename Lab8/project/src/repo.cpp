#include "../include/repo.hpp"

Repo::Repo()
    : entitati()
{}

bool Repo::operator==(const Repo& other) const {
    return this->entitati == other.entitati;
}

void Repo::add(const Cheltuiala& e, int index) {
    if (index != -1)
        this->entitati.insert(this->entitati.begin() + index, e);
    else
        this->entitati.push_back(e);
}

void Repo::update(int index, const Cheltuiala& e) {
    this->entitati[index] = e;
}

void Repo::remove(std::vector<int> indexes) {
    for (int i = indexes.size() - 1; i >= 0; i--) {
        this->entitati.erase(this->entitati.begin() + indexes[i]);
    }
}

const std::vector<Cheltuiala>& Repo::getAll() const {
    return this->entitati;
}

Cheltuiala Repo::get(int index) const {
    return this->entitati[index];
}

int Repo::getSize() const {
    return this->entitati.size();
}
