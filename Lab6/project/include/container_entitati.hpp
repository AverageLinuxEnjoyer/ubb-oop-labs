#ifndef CONTAINER_ENTITATI_HPP
#define CONTAINER_ENTITATI_HPP

#include <ostream>
#include <vector>

template<class T>
class ContainerEntitati {
public:
    // constructor
    ContainerEntitati();

    // destructor
    ~ContainerEntitati() = default;

    // adaugare si stergere
    void adauga(T *entitate);
    void sterge(int index);

    // getteri
    const std::vector<T>& get() const;
    const T& get(int index) const;
    int getNrEntitati() const;
    int getCapacitate() const;

    const T& getCeaMaiMareEntitate() const;
    std::vector<T> entitatiInPrimulCadran() const;
    std::pair<int,int> ceaMaiLungaSubsecventa() const;
    void printEntitati() const;

private:
    std::vector<T> entitati;
};

#endif // CONTAINER_ENTITATI_HPP
