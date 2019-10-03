#include <list>
#include <iterator>
#include <vector>
#include <algorithm>
#include <deque>

#include "all_function.h"

bool myfunction(int i, int j) {
    return (i == j);
}

int inserter() {

    std::list<int> lst = { 1,2,3,4 };
    std::list<int> lst2, lst3;

    copy(lst.begin(), lst.end(), front_inserter(lst2));

    copy(lst.begin(), lst.end(), inserter(lst3, lst3.begin()));

    {
        std::list<int> foo, bar;
        for (int i = 1; i <= 5; i++)
        {
            foo.push_back(i); bar.push_back(i * 10);
        }

        std::list<int>::iterator it = foo.begin();
        advance(it, 3); // move iterator on 4 element foo[3]

        std::copy(bar.begin(), bar.end(), std::inserter(foo, it));

        std::cout << "foo contains:";
        for (std::list<int>::iterator it = foo.begin(); it != foo.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';
    }

    {
        std::vector<int> source{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        std::vector<int> ivec;
        std::deque<int> ideq;
        std::list<int> ilist;

        // back_inserter: output 1 2 3 4 5 6 7 8 9
        copy(source.cbegin(), source.cend(), back_inserter(ivec));
        // front inserter: output 9 8 7 6 5 4 3 2 1
        copy(source.cbegin(), source.cend(), front_inserter(ideq));
        // inserter: output 1 2 3 4 5 6 7 8 9
        copy(source.cbegin(), source.cend(), inserter(ilist, ilist.begin()));

        std::cout << "back_inserter and vector: ";
        for (const auto& elem : ivec)
            std::cout << elem << ' ';
        std::cout << '\n';

        std::cout << "front_inserter and deque: ";
        for (const auto& elem : ideq)
            std::cout << elem << ' ';
        std::cout << '\n';

        std::cout << "inserter and list: ";
        for (const auto& elem : ilist)
            std::cout << elem << ' ';
        std::cout << '\n';

    }

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