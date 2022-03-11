#ifndef REPO_HPP
#define REPO_HPP

#include <vector>

template<class T>
class Repo {
public:
    Repo();
    Repo(const Repo& r) = delete;
    virtual ~Repo() = default;

    Repo& operator=(const Repo& other) = delete;
    bool operator==(const Repo& other) const;

    const std::vector<T>& getAll() const;
    const T& get(int index) const;

    virtual void add(const T& e);
    virtual void update(int index, const T& e);
    virtual void remove(int index);
    int getSize() const;
private:
    std::vector<T> entitati;

};

#endif // REPO_HPP
