#ifndef UI_HPP
#define UI_HPP

#include <string>
#include "service.hpp"

class UserInterface
{
public:
    UserInterface(Service &service);
    virtual ~UserInterface() = default;

    virtual void run();

protected:
    virtual void adaugare();
    virtual void stergere();
    virtual void listare();
    virtual void filtrare();
    virtual void undo();
    virtual void redo();
    virtual void altele(std::string command);

protected:
    Service &service;
    std::vector<std::string> arguments;
};

#endif // UI_HPP
