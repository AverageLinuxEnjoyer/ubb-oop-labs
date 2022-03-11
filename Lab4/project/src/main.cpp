#include <iostream>

#include "../include/numar_complex.hpp"
#include "../include/patrat.hpp"
#include "../include/triunghi.hpp"
#include "../include/tests.hpp"


int main() {
    Tests tests;

    Patrat p(4.0, {2.0, 1.0});
    
    std::cout << p << std::endl;

    std::cin >> p;
    std::cout << p << std::endl;
    std::cout << p.arie() << std::endl;
    std::cout << p.perimetru() << std::endl;
}