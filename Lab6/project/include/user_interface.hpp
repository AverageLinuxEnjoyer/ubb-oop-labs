#ifndef USER_INTERFACE_HPP
#define USER_INTERFACE_HPP

#include "../include/container_entitati.hpp"

template<class T>
class UserInterface {
public:
    UserInterface();
    ~UserInterface() = default;

    void run();

private:
    void meniu_adaugare();
private:
    ContainerEntitati<T> entitati;

};

#endif // USER_INTERFACE_HPP
