#ifndef UNDOREDO_HANDLER_HPP
#define UNDOREDO_HANDLER_HPP

#include <vector>
#include <memory>
#include "operatie.hpp"

template<class T>
class UndoRedoHandler {
public:
    UndoRedoHandler();
    ~UndoRedoHandler() = default;

    void add(Operatie<T> *operatie_);

    void undo();
    void redo();

private:
    std::vector<std::unique_ptr<Operatie<T>>> undoStack;
    std::vector<std::unique_ptr<Operatie<T>>> redoStack;
};


#endif // UNDOREDO_HANDLER_HPP
