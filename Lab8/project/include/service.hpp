#ifndef SERVICE_HPP
#define SERVICE_HPP

#include "../include/repo.hpp"
#include <functional>

template<class T>
class Service {
public:
    Service(Repo<T> *repo = nullptr);
    Service(const Service& s) = delete;
    virtual ~Service() = default;

    Service& operator=(const Service& other) = delete;
    bool operator==(const Service& other) const;

    void setRepo(Repo<T> *repo_);

    const std::vector<T>& getAll() const;
    const T& get(int index) const;
    std::vector<T> getAllCuProprietate(std::function<bool(const T&)> functie) const; 
    
    void add(const T& e);
    void update(int index, const T& e);
    void remove(int index);
    int getSize() const;

private:
    Repo<T> *repo;
};

#endif // SERVICE_HPP
