#ifndef STERGERE_HPP
#define STERGERE_HPP

#include "operatie.hpp"

template<class T>
class Stergere : public Operatie<T> {
public:
    Stergere(std::vector<int> indexes_, Service<T> *service_ = nullptr);
    ~Stergere() = default;

    virtual void execute() override;
    virtual void unexecute() override;

private:
    std::vector<T> entitati;
    std::vector<int> indexes;
};


#endif // STERGERE_HPP
