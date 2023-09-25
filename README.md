PROBLEM: Allow to easily bind multiple callable structs and lambdas with not empty capture list to function pointers.
For example while using C libraries in C++ code (check example.cpp)

Limitation resulting from using __LINE__ is that you cannot create 2 or more wrappers of same type callable in one line

As it have been written to bind capturing lambdas as callbacks in C libraries 
std::forward in returned lambda may be a bit of form over content due to lack of rvalue/lvalue references in C


This code works fine with Clang and G++ compilers
To use it with Microsoft Compiler:
1. Remove std::forward
2. Use evil macro trick to make compiler treat __LINE__ as constexpr:

#define _wrapperConcatenator(a, b) a ## b
#define _wrapperConcatenatorWrapper(a, b)  _wrapperConcatenator(a, b)
#define _wrapperConstexprLine unsigned(_wrapperConcatenatorWrapper(__LINE__,U))	//suddenly __LINE__ becomes constexpr
//swap __LINE__ in #define wrapper with _wrapperConstexprLine

