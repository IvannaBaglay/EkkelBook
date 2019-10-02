#include <vector>

#include "all_function.h"

int function_copy() {

    int myints[] = { 10,20,30,40,50,60,70 };
    int myints1[7]; // if not enough element, we take abort

    std::copy(myints, myints + 7, myints1);

    std::vector<int> myvector(7);

    //std::copy(myints, myints + 7, myvector.begin());

    std::cout << "myvector contains:";
    for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
        std::cout << ' ' << *it;

    std::cout << '\n';

    
    {
        std::vector<int> myvector;

        // set some values:
        for (int i = 1; i <= 5; i++)
            myvector.push_back(i * 10);          // myvector: 10 20 30 40 50

        myvector.resize(myvector.size() + 3);  // allocate space for 3 more elements

        std::copy_backward(myvector.begin(), myvector.begin() + 5, myvector.end());

        std::cout << "myvector contains:";
        for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';
    }

    return 0;
}