#include "../../include/undo_redo/undo_redo_handler.hpp"

template<class T>
UndoRedoHandler<T>::UndoRedoHandler()
    : undoStack(),
      redoStack()
{}

template<class T>
void UndoRedoHandler<T>::add(Operatie<T> *operatie_) {
	undoStack.push_back(std::unique_ptr<Operatie<T>>(std::move(operatie_)));
    redoStack.clear();
}

template<class T>
void UndoRedoHandler<T>::undo() {
	if (undoStack.size() > 0) {
		auto operatie = std::move(undoStack.back());
		undoStack.pop_back();
		operatie->unexecute();
		redoStack.push_back(std::move(operatie));
	}
}

template<class T>
void UndoRedoHandler<T>::redo() {
	if (redoStack.size() > 0) {
		auto operatie = std::move(redoStack.back());
		redoStack.pop_back();
		operatie->execute();
		undoStack.push_back(std::move(operatie));
	}
}

#include "../../include/entitati/entitate.hpp"
template class UndoRedoHandler<Entitate>;