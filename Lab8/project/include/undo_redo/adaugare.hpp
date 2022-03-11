#ifndef ADAUGARE_HPP
#define ADAUGARE_HPP

#include "operatie.hpp"

template<class T>
class Adaugare : public Operatie<T> {
public:
    Adaugare(T entitate_, Service<T> *service_ = nullptr);
    ~Adaugare() = default;

    virtual void execute() override;
    virtual void unexecute() override;

private:
    T entitate;
    int index;
};

#endif // ADAUGARE_HPP
