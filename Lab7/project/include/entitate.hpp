#ifndef ENTITATE_HPP
#define ENTITATE_HPP

class Entitate {
public:
    Entitate(const char* nume_ = "");
    Entitate(const Entitate& e);

    virtual ~Entitate() = default;

    const char* getNume() const;
    void setNume(const char* nume_);

    Entitate& operator=(const Entitate& other);
    bool operator==(const Entitate& other) const;
private:
    const char* nume;
};

#endif // ENTITATE_HPP
