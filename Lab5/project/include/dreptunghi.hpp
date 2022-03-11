#ifndef DREPTUNGHI_HPP
#define DREPTUNGHI_HPP

#include "vector2.hpp"

class Dreptunghi {
public:
    // constructor
    Dreptunghi();
    Dreptunghi(int lungime_, int latime_, Vector2 centru_ = {});

    // destructor
    ~Dreptunghi() = default;

    // getteri
    int getLungime() const;
    int getLatime() const;
    Vector2 getCentru() const;

    // setteri
    void setLungime(int lungime_);
    void setLatime(int latime_);
    void setCentru(Vector2 centru_);

    // arie si perimetru
    int arie() const;
    int perimetru() const;

    bool seAflaInCadranul1() const;

    // operatori
    bool operator>(const Dreptunghi &other) const;
    bool operator==(const Dreptunghi &other) const;
    friend std::ostream& operator<<(std::ostream& os, const Dreptunghi& d);
    friend std::istream& operator>>(std::istream& is, Dreptunghi& d);

private:
    int lungime;
    int latime;
    Vector2 centru;
};

#endif // DREPTUNGHI_HPP
