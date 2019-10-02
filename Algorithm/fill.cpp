#include <vector>

#include "all_function.h"

int function_fill() {
    {
        std::vector<int> myvector(8);                       // myvector: 0 0 0 0 0 0 0 0

        std::fill(myvector.begin(), myvector.begin() + 4, 5);   // myvector: 5 5 5 5 0 0 0 0
        std::fill(myvector.begin() + 3, myvector.end() - 2, 8);   // myvector: 5 5 5 8 8 8 0 0

        std::cout << "myvector contains:";
        for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n'; 
    }

    {
        std::vector<int> myvector(8, 10);        // myvector: 10 10 10 10 10 10 10 10

        std::fill_n(myvector.begin(), 4, 20);     // myvector: 20 20 20 20 10 10 10 10
        std::fill_n(myvector.begin() + 3, 3, 33);   // myvector: 20 20 20 33 33 33 10 10

        std::cout << "myvector contains:";
        for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';
    }

    return 0;
}