#include <iostream>
#include "utilities.h"

int main() {
    if (add(2, 3) == 5) {
        std::cout << "PASS" << std::endl;
    } else {
        std::cout << "FAIL" << std::endl;
    }
    return 0;
}