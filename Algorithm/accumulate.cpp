#include "all_function.h"

int myfunction(int x, int y) { return x + 2 * y; } // x is sum; y is element vector/array
struct myclass {
    int operator()(int x, int y) { return x + 3 * y; }
} myobject;

int function_accumulate() {

    int init = 100;
    int numbers[] = { 10,20,30 };

    std::cout << "using default accumulate: ";
    std::cout << std::accumulate(numbers, numbers + 3, init);
    std::cout << '\n';

    std::cout << "using functional's minus: ";
    std::cout << std::accumulate(numbers, numbers + 3, init, std::minus<int>());
    std::cout << '\n';

    std::cout << "using custom function: ";
    std::cout << std::accumulate(numbers, numbers + 3, init, myfunction); // 120 160 220
    std::cout << '\n';

    std::cout << "using custom object: ";
    std::cout << std::accumulate(numbers, numbers + 3, init, myobject);
    std::cout << '\n';

    return 0;
}