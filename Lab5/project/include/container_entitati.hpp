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
    ~ContainerEntitati();

    // adaugare si stergere
    void adauga(T *entitate);
    void sterge(int index);

    // getteri
    T* get() const;
    T* get(int index) const;
    int getNrEntitati() const;
    int getCapacitate() const;

    T* getCeaMaiMareEntitate() const;
    std::vector<T> entitatiInPrimulCadran() const;
    std::pair<int,int> ceaMaiLungaSubsecventa() const;
    void printEntitati() const;

private:
    T* entitati;
    int nr_entitati;
    int capacitate;
};

#endif // CONTAINER_ENTITATI_HPP
