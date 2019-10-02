#include <vector>

#include "all_function.h"

int function_back_inserter() {

    int array1[] = { 1,2,3 };
    int array2[]{ 10,20,30 };

    //std::copy(array1, array1 + 3, array2 +2 ); error
    //std::copy(array1, array1 + 3, back_inserter(array2)); error

    std::vector<int> foo, bar;
    for (int i = 1; i <= 5; i++)
    {
        foo.push_back(i); bar.push_back(i * 10);
    }

    std::copy(bar.begin(), bar.end(), back_inserter(foo));

    std::cout << "foo contains:";
    for (std::vector<int>::iterator it = foo.begin(); it != foo.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    return 0;
}