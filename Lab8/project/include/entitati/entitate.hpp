#ifndef ENTITATE_HPP
#define ENTITATE_HPP

#include <iostream>

class Entitate {
public:
    Entitate(const char* nume_ = "");
    Entitate(const Entitate& e);

    virtual ~Entitate() = default;

    const char* getNume() const;
    void setNume(const char* nume_);

    Entitate& operator=(const Entitate& other);
    bool operator==(const Entitate& other) const;
 
    friend std::ostream& operator<<(std::ostream& os, const Entitate& e);
private:
    const char* nume;
};

#endif // ENTITATE_HPP
