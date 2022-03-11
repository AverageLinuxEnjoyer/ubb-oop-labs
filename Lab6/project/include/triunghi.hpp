#ifndef TRIUNGHI_HPP
#define TRIUNGHI_HPP

#include "vector2.hpp"

class Triunghi {
public:
    // constructor
    Triunghi();
    Triunghi(Vector2 v1_, Vector2 v2_, Vector2 v3_);

    // destructor
    ~Triunghi() = default;

    // getteri
    Vector2 getV1() const;
    Vector2 getV2() const;
    Vector2 getV3() const;

    // setteri
    void setV1(const Vector2 &v1_);
    void setV2(const Vector2 &v2_);
    void setV3(const Vector2 &v3_);

    // arie si perimetru
    double arie() const;
    double perimetru() const;

    bool seAflaInCadranul1() const;

    // operatori
    bool operator>(const Triunghi &other) const;
    bool operator==(const Triunghi &other) const;
    friend std::ostream& operator<<(std::ostream& os, const Triunghi& t);

private:
    Vector2 v1;
    Vector2 v2;
    Vector2 v3;
};

#endif // TRIUNGHI_HPP
