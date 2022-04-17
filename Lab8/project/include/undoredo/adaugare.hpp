#ifndef ADAUGARE_HPP
#define ADAUGARE_HPP

#include "operatie.hpp"
#include <iostream>

class Adaugare : public Operatie {
public:
    Adaugare(Cheltuiala entitate_, Service *service_ = nullptr)
        : entitate(entitate_),
          Operatie(service_)
    {   
        this->index = this->service->getSize() - 1;
    }

    ~Adaugare() = default;

    virtual void execute() override {
        Operatie::execute();
        this->service->add(this->entitate);
    }
    virtual void unexecute() override {
        Operatie::unexecute();
        this->service->remove({this->index});
    }

private:
    Cheltuiala entitate;
    int index;
};

#endif // ADAUGARE_HPP
