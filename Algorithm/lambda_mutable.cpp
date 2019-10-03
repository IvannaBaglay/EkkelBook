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

int LambdaTransform() {

    std::vector<int> vi{ 1, -1, -2,2 };
    transform(vi.begin(), vi.end(), vi.begin(), [](int i) {return i < 0 ? -i : i; });

    vi = { 1, -1, -2,2 };
    transform(vi.begin(), vi.end(), vi.begin(), [](int i) 
        {
            if (i < 0) return -i; else return i;
        });
    vi = { 1, -1, -2,2 };
    transform(vi.begin(), vi.end(), vi.begin(), [](int i) -> int
        {
            if (i < 0) return -i; else return i;
        });

    return 0;
}