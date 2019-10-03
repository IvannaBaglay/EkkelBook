#include <vector>
#include <string>

#include "all_function.h"

int LambdaCapturesReference() {

    {
        size_t v1 = 42;
        auto f2 = [&v1] { return v1; };
        v1 = 0;
        auto j = f2();
    }

    {
        std::vector<std::string> words{ "a", "aa", "aaa" };
        std::vector<std::string>::size_type sz = words.size();
        std::ostream& os = std::cout;
        char c = ' ';

        for_each(words.begin(), words.end(), [&os, c](const std::string& s)
            { os << s << c; });


    }

    return 0;
}