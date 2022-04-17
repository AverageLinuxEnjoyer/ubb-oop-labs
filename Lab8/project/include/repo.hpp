#ifndef REPO_HPP
#define REPO_HPP

#include <vector>
#include "../include/cheltuiala.hpp"

class Repo {
public:
    Repo();
    Repo(const Repo& r) = delete;
    virtual ~Repo() = default;

    Repo& operator=(const Repo& other) = delete;
    bool operator==(const Repo& other) const;

    const std::vector<Cheltuiala>& getAll() const;
    Cheltuiala get(int index) const;

    virtual void add(const Cheltuiala& e, int index = -1);
    virtual void update(int index, const Cheltuiala& e);
    virtual void remove(std::vector<int> indexes);
    int getSize() const;
private:
    std::vector<Cheltuiala> entitati;

};

#endif // REPO_HPP
