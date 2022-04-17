#ifndef OPERATIE_HPP
#define OPERATIE_HPP

#include <memory>
#include "../../include/cheltuiala.hpp"
#include "../../include/service.hpp"

class Operatie {
public:
    Operatie(Service *service_ = nullptr) : service(service_) {}
    virtual ~Operatie() = default;

    virtual void execute() { if (!this->service) return; };
    virtual void unexecute() { if (!this->service) return; };

protected:
    Service* service;    
};

#endif // OPERATIE_HPP