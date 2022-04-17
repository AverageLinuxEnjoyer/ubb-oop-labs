#ifndef UNDOREDO_HANDLER_HPP
#define UNDOREDO_HANDLER_HPP

#include <stack>
#include <memory>
#include "../../include/undoredo/operatie.hpp"
#include "../../include/cheltuiala.hpp"


class UndoRedoHandler {
public:
  
	UndoRedoHandler() : undoStack(), redoStack() {}
    ~UndoRedoHandler() = default;

    void add(Operatie *operatie_) {
		undoStack.push(std::unique_ptr<Operatie>(std::move(operatie_)));
		
		while(redoStack.size() > 0) {
			redoStack.pop();
		}
	}

    void undo() {
    	if (undoStack.size() > 0) {
    		auto operatie = std::move(undoStack.top());
    		undoStack.pop();
    		operatie->unexecute();
    		redoStack.push(std::move(operatie));
    	}
    } 
    
    void redo() {
    	if (redoStack.size() > 0) {
    		auto operatie = std::move(redoStack.top());
    		redoStack.pop();
    		operatie->execute();
    		undoStack.push(std::move(operatie));
    	}
    }

private:
    std::stack<std::unique_ptr<Operatie>> undoStack;
    std::stack<std::unique_ptr<Operatie>> redoStack;
};


#endif // UNDOREDO_HANDLER_HPP
