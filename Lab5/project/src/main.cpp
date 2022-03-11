#include <iostream>

#include "../include/tests.hpp"
#include "../include/user_interface.hpp"
#include "../include/triunghi.hpp"

int main() {
    Tests tests;

    UserInterface<Triunghi> ui;
    ui.run();
}