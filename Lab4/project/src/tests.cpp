#include "../include/tests.hpp"
#include "../include/numar_complex.hpp"
#include "../include/patrat.hpp"
#include "../include/triunghi.hpp"
#include "../include/cerc.hpp"
#include "../include/dreptunghi.hpp"

#include <cmath>
#include <cassert>

Tests::Tests()
{
    this->test_numar_complex();
    this->test_patrat();
    this->test_cerc();
    this->test_triunghi();
    this->test_dreptunghi();
}

void Tests::test_numar_complex() {
    NumarComplex a(1.0, 1.0);
    NumarComplex b(2.0, 2.0);

    NumarComplex c = a * b;

    assert(c.getRe() == 0.0);
    assert(c.getIm() == 4.0);

    NumarComplex d = a + 4;

    assert(d.getRe() == 5.0);
    assert(d.getIm() == 1.0);

    NumarComplex e = a - 4;

    assert(e.getRe() == -3.0);
    assert(e.getIm() == 1.0);

    NumarComplex f = a / b;

    assert(f.getRe() == 0.5);
    assert(f.getIm() == 0.0);
}

void Tests::test_patrat() {
    Patrat p(2.0);
    assert(p.getLatura() == 2.0);
    assert((p.getCentru() == Vector2{0.0, 0.0}));

    p.setLatura(3.0);
    assert(p.getLatura() == 3.0);

    p.setCentru({1.0, 1.0});
    assert((p.getCentru() == Vector2{1.0, 1.0}));

    assert(p.arie() == 9.0);
    assert(p.perimetru() == 12.0);
}

void Tests::test_triunghi() {
    Triunghi t({-5, -2}, {-2,-2}, {-5,2});
    assert(t.arie() == 6.0);
    assert(t.perimetru() == 12.0);

    t.setV1({1, 0});
    assert(t.getV1() == Vector2({1, 0}));

    t.setV2({0, 1});
    assert(t.getV2() == Vector2({0, 1}));

    t.setV3({0, 0});
    assert(t.getV3() == Vector2({0, 0}));
}

void Tests::test_cerc() {
    Cerc c(2.0);
    assert(c.getRaza() == 2.0);
    assert((c.getCentru() == Vector2{0.0, 0.0}));

    c.setRaza(3.0);
    assert(c.getRaza() == 3.0);

    c.setCentru({1.0, 1.0});
    assert((c.getCentru() == Vector2{1.0, 1.0}));

    assert(c.arie() == M_PI * 3.0 * 3.0);
    assert(c.perimetru() == 2 * M_PI * 3.0);    
}

void Tests::test_dreptunghi() {
    Dreptunghi d(5, 12, {1, 1});
    assert(d.getLungime() == 5);
    assert(d.getLatime() == 12);
    assert((d.getCentru() == Vector2{1, 1}));

    d.setLungime(3);
    assert(d.getLungime() == 3);

    d.setLatime(4);
    assert(d.getLatime() == 4);

    d.setCentru({2, 2});
    assert((d.getCentru() == Vector2{2, 2}));

    assert(d.arie() == 12);
    assert(d.perimetru() == 14);
}
