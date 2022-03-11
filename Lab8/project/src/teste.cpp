#include <cassert>
#include <iostream>
#include <memory>

#include "../include/teste.hpp"
#include "../include/entitati/entitate.hpp"
#include "../include/repo.hpp"
#include "../include/service.hpp"
#include "../include/undo_redo/adaugare.hpp"
#include "../include/undo_redo/stergere.hpp"
#include "../include/undo_redo/operatie.hpp"
#include "../include/undo_redo/undo_redo_handler.hpp"

Teste::Teste()
{
    this->testEntitate();
    this->testRepo();
    this->testService();
    this->testUndoRedoHandler();

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
    Repo<Entitate> r;
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
}

void Teste::testService() {
    Repo<Entitate> r;
    Entitate e1("1");
    Entitate e2("4");
    Entitate e3("7");
    r.add(e1);
    r.add(e2);
    r.add(e3);
    Service<Entitate> s(&r);
    assert(s.getSize() == 3);
    assert(s.get(0) == e1);
    assert(s.get(1) == e2);
    assert(s.get(2) == e3);
    Entitate e4("8");
    s.add(e4);
    assert(s.getSize() == 4);
    assert(s.get(3) == e4);
    s.remove(0);
    assert(s.getSize() == 3);
    assert(s.get(0) == e2);
    assert(s.get(1) == e3);
    assert(s.get(2) == e4);
    s.remove(1);
    assert(s.getSize() == 2);
    assert(s.get(0) == e2);
    assert(s.get(1) == e4);
    s.remove(0);
    assert(s.getSize() == 1);
    assert(s.get(0) == e4);
    s.remove(0);
    assert(s.getSize() == 0);
}

void Teste::testUndoRedoHandler() {
    Repo<Entitate> r;
    Service<Entitate> s(&r);

    UndoRedoHandler<Entitate> h;

    Entitate e1("1");
    s.add(e1);
    h.add(new Adaugare<Entitate>(e1, &s));

    assert(r.getSize() == 1);

    Entitate *e2 = new Entitate("2");
    s.add(*e2);
    h.add(new Adaugare<Entitate>(*e2, &s));
    assert(s.getSize() == 2);

    h.undo();
    assert(s.getSize() == 1);

    h.redo();
    assert(s.getSize() == 2);

    h.undo();
    h.undo();
    assert(s.getSize() == 0);

    h.redo();
    h.redo();
    assert(s.getSize() == 2);

    h.add(new Stergere<Entitate>({0}, &s));
    s.remove(0);
    assert(s.getSize() == 1);

    h.undo();
    assert(s.getSize() == 2);

    h.redo();
    assert(s.getSize() == 1);

    h.add(new Stergere<Entitate>({0}, &s));
    s.remove(0);
    assert(s.getSize() == 0);

    h.undo();
    h.undo();
    assert(s.getSize() == 2);

    h.add(new Stergere<Entitate>({0,1}, &s));
    s.remove(0);
    s.remove(0);

    assert(s.getSize() == 0);

    h.undo();

    assert(s.getSize() == 2);
}
