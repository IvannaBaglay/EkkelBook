#include <list>
#include <iterator>
#include <vector>
#include <algorithm>

#include "all_function.h"

bool myfunction(int i, int j) {
    return (i == j);
}

int inserter() {

    std::list<int> lst = { 1,2,3,4 };
    std::list<int> lst2, lst3;

    copy(lst.begin(), lst.end(), front_inserter(lst2));

    copy(lst.begin(), lst.end(), inserter(lst3, lst3.begin()));

    return 0;
}

int function_unique() {

    {
        int myints[] = { 10,20,20,20,30,30,20,20,10 };           // 10 20 20 20 30 30 20 20 10
        std::vector<int> myvector(myints, myints + 9);

        // using default comparison:
        std::vector<int>::iterator it;
        it = std::unique(myvector.begin(), myvector.end());   // 10 20 30 20 10 ?  ?  ?  ?
                                                               //                ^

        myvector.resize(std::distance(myvector.begin(), it)); // 10 20 30 20 10

        // using predicate comparison:
        std::unique(myvector.begin(), myvector.end(), myfunction);   // (no changes)

        // print out content:
        std::cout << "myvector contains:";
        for (it = myvector.begin(); it != myvector.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';
    }

    {
        int myints[] = { 10,20,20,20,30,30,20,20,10 };
        std::vector<int> myvector(9);                            // 0  0  0  0  0  0  0  0  0

        // using default comparison:
        std::vector<int>::iterator it;
        it = std::unique_copy(myints, myints + 9, myvector.begin());   // 10 20 30 20 10 0  0  0  0
                                                                  //                ^

        std::sort(myvector.begin(), it);                          // 10 10 20 20 30 0  0  0  0
                                                                  //                ^

        // using predicate comparison:
        it = std::unique_copy(myvector.begin(), it, myvector.begin(), myfunction);
        // 10 20 30 20 30 0  0  0  0
        //          ^

        myvector.resize(std::distance(myvector.begin(), it));    // 10 20 30

        // print out content:
        std::cout << "myvector contains:";
        for (it = myvector.begin(); it != myvector.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';
    }

    return 0;
}