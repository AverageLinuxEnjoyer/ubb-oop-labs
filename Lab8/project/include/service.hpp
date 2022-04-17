#ifndef SERVICE_HPP
#define SERVICE_HPP

#include "../include/repo.hpp"
#include "../include/cheltuiala.hpp"
#include <functional>

class UndoRedoHandler;

class Service {
public:
    Service(Repo *repo_ = nullptr, UndoRedoHandler *undoRedoHandler_ = nullptr);
    Service(const Service& s) = delete;
    virtual ~Service() = default;

    Service& operator=(const Service& other) = delete;
    bool operator==(const Service& other) const;

    void setRepo(Repo *repo_);

    const std::vector<Cheltuiala>& getAll() const;
    Cheltuiala get(int index) const;
    
    std::vector<Cheltuiala> getAllCuProprietate(std::function<bool(const Cheltuiala&)> functie) const; 
    std::vector<Cheltuiala> getSortedBy(std::function<bool(const Cheltuiala&, const Cheltuiala&)> functie) const;
    void filter(std::function<bool(const Cheltuiala&)> functie, bool undoredo = false);

    std::vector<Cheltuiala> getCheltuieliDeTip(Cheltuiala::Tip tip, const char relatie = '?', int suma = 0) const;
    std::vector<Cheltuiala> filter(Cheltuiala::Tip tip, const char relatie = '?', int suma = 0, bool undoredo = false);

    int getSumaCheltuieliDeTip(Cheltuiala::Tip tip) const;
    int getMaxCheltuiala() const;
    std::vector<Cheltuiala> getCrescatoareDupaSuma() const;
    std::vector<Cheltuiala> getCrescatoareDupaZi() const;
    
    void add(const Cheltuiala& e, bool undoredo = false, int index = -1);
    void update(int index, const Cheltuiala& e);
    void remove(std::vector<int> indexes, bool undoredo = false);
    int getSize() const;

    void undo();
    void redo();

protected:
    Repo *repo;
    UndoRedoHandler* undo_redo_handler;

};


#endif // SERVICE_HPP
