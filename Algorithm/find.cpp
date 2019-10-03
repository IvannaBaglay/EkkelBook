#include "all_function.h"
#include <vector>
#include <string>

int function_find() {
    
    // using std::find with array and pointer:
    int myints[] = { 10, 20, 30, 40 };
    int* p;

    p = std::find(myints, myints + 4, 30);
    if (p != myints + 4)
        std::cout << "Element found in myints: " << *p << '\n';
    else
        std::cout << "Element not found in myints\n";

    // using std::find with vector and iterator:
    std::vector<int> myvector(myints, myints + 4);
    std::vector<int>::iterator it;

    it = find(myvector.begin(), myvector.end(), 30);
    if (it != myvector.end())
        std::cout << "Element found in myvector: " << *it << '\n';
    else
        std::cout << "Element not found in myvector\n";

    {
        std::vector<std::string> words;
        words.push_back("a");
        words.push_back("aa");
        words.push_back("aaa");
        int sz = 2;
        auto wc = find_if(words.begin(), words.end(), [sz](const std::string& a)
            {return a.size() >= sz; });

    }

    return 0;
}