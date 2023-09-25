#include <iostream>
#include "callableWrapper.hpp"
/*
    this file contains example usage of wrapper
*/


typedef double (*ptr)(int);

void irq(ptr a) {
    a(5);
}

struct foo {
    double operator()(int a) {
        return 3.0+static_cast<double>(a);
    }
    foo()=default;
    ~foo()=default;
    foo(const foo&) {
        std::cout<<"copy ctor\n";
    }
    foo(foo&&) {
        std::cout<<"move ctor\n";
    }
    foo& operator=(const foo&) {
        std::cout<<"copy op\n";
        return *this;
    }
    foo& operator=(foo&&) {
        std::cout<<"move op\n";
        return *this;
    }
};



int main() {
        irq(wrapper(foo{}));
}