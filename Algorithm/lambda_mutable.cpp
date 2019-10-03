#include <vector>
#include <string>

#include "all_function.h"

int LambdaMutable() {

    {
        size_t v1 = 42;
        // auto f = [v1]() { return ++v1; }; //error
        v1 = 0;
        //auto j = f();
    }
    {
        size_t v1 = 42;
        auto f = [v1]() mutable { return ++v1; };
        v1 = 0;
        auto j = f(); // j = 43
    }
    {
        size_t v1 = 42;
        auto f = [&v1]() mutable { return ++v1; };
        v1 = 0;
        auto j = f(); // j = 1
    }
    return 0;
}