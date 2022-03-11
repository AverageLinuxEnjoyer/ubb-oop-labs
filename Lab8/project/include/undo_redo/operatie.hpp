#ifndef OPERATIE_HPP
#define OPERATIE_HPP

#include "../../include/service.hpp"
#include <memory>

template<class T>
class Operatie {
public:
    Operatie(Service<T> *service_ = nullptr);
    virtual ~Operatie() = default;

    virtual void execute() = 0;
    virtual void unexecute() = 0;

protected:
    Service<T>* service;    
};

#endif // OPERATIE_HPP