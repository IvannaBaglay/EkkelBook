#include <vector>
#include <string>

#include "all_function.h"

int ImplicitlyLambdaCapture() {

    {
        std::vector<std::string> words;
        words.push_back("a");
        words.push_back("aa");
        words.push_back("aaa");
        int sz = 2;
        auto wc = find_if(words.begin(), words.end(), [=](const std::string& a)
            {return a.size() >= sz; });
        
    }

    return 0;
}