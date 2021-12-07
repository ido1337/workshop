#include <iostream>
#include "stringBasic.h"


int main() {
    StringBasic a("hey this is the best class in the world");
    StringBasic b("the");
    StringBasic c("not the");

    a.replace(b, c);

    std::cout << a;
}