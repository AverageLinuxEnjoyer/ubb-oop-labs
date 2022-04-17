#ifndef STERGERE_HPP
#define STERGERE_HPP

#include "operatie.hpp"
#include <vector>
#include <algorithm>

class Stergere : public Operatie {
public:
    Stergere(std::vector<int> indexes, Service *service_ = nullptr)
        : Operatie(service_)
    {
        for(int i = 0; i < indexes.size(); i++)
        {
            this->elements.push_back(
                std::make_pair(
                    this->service->get(indexes[i]),
                    indexes[i]
                )
            );
        }

        std::sort(this->elements.begin(), this->elements.end(),
            [](const std::pair<Cheltuiala, int> &a, const std::pair<Cheltuiala, int> &b)
            {
                return a.second < b.second;
            }
        );
    }

    ~Stergere() = default;

    virtual void execute() override {
        Operatie::execute();

        std::vector<int> indexes;
        for(auto &element : this->elements)
            indexes.push_back(element.second);

        std::sort(indexes.begin(), indexes.end());

        this->service->remove(indexes);
    }

    virtual void unexecute() override {
        Operatie::unexecute();
        for (int i = 0; i  < elements.size(); i++)
            this->service->add(elements[i].first, false, elements[i].second);
    }

private:
    std::vector<std::pair<Cheltuiala, int>> elements;
};


#endif // STERGERE_HPP
