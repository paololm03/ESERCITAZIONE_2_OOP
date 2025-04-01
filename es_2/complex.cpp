#include <iostream>
#include "complex.hpp"


int main(void) {
    using comp = complex<int>;
    
    comp z1(5);
    comp z2(3,1);
    comp z3(2,-8);
    comp z4(-7,9);
    
    
    std::cout << z1 << " + " << z2 << " = " << z1+z2 << std::endl;

    std::cout << z3 << " + " << z4 << " = " << z3+z4 << std::endl;

    std::cout << "i complessi coniugati di: " << z4 << " sono: " << conj(z4) << std::endl;

    std::cout << z3 << " * " << z4 << " = " << z3*z4 << std::endl;
    
    return 0;
}
