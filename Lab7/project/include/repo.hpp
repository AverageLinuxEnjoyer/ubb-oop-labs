#ifndef REPO_HPP
#define REPO_HPP

#include <vector>
#include "../include/entitate.hpp"

class Repo {
public:
    Repo();
    Repo(const Repo& r);
    virtual ~Repo() = default;

    Repo& operator=(const Repo& other);
    bool operator==(const Repo& other) const;

    virtual void add(const Entitate& e);
    const std::vector<Entitate>& getAll() const;
    int getSize() const;
private:
    std::vector<Entitate> entitati;

};

#endif // REPO_HPP
