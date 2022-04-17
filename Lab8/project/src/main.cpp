#include <iostream>

#include "../include/undoredo/undo_redo_handler.hpp"
#include "../include/repo.hpp"
#include "../include/service.hpp"
#include "../include/ui.hpp"

int main() {
    UndoRedoHandler undoredo;
    Repo repo;
    Service service(&repo, &undoredo);
    UserInterface ui(service);

    ui.run();

    return 0;
}
