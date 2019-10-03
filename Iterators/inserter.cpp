#include <list>
#include <iterator>

#include "all_function.h"

int inserter() {

    std::list<int> lst = { 1,2,3,4 };
    std::list<int> lst2, lst3;

    copy(lst.begin(), lst.end(), front_inserter(lst2));

    copy(lst.begin(), lst.end(), inserter(lst3, lst3.begin()));

    return 0;
}