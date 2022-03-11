#include <cassert>
#include <iostream>

#include "../include/teste.hpp"
#include "../include/entitate.hpp"
#include "../include/repo.hpp"

Teste::Teste()
{
    this->testEntitate();
    this->testRepo();

    std::cout << "Testele au rulat cu succes!\n";    
}

void Teste::testEntitate() {
    Entitate e1("unu");
    Entitate e2("doi");

    assert(e1.getNume() == "unu");
    assert(e2.getNume() == "doi");

    Entitate e3 = e1;

    assert(e1 == e3);
    e3.setNume("trei");
    assert(e3.getNume() == "trei");
}

void Teste::testRepo() {
    Repo r;
    Entitate e1("1");
    Entitate e2("4");
    Entitate e3("7");
    r.add(e1);
    r.add(e2);
    r.add(e3);
    assert(r.getSize() == 3);
    assert(r.getAll()[0] == e1);
    assert(r.getAll()[1] == e2);
    assert(r.getAll()[2] == e3);

    Repo r2 = r;
    assert(r2 == r);
    
    r2.add(Entitate("12"));
    assert(!(r2 == r));
}
