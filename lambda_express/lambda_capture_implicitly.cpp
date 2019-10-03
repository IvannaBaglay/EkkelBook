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
        std::ostream& os = std::cout;
        char c = ' ';
        auto wc = find_if(words.begin(), words.end(), [=](const std::string& a)
            {return a.size() >= sz; });

        //os implicitly capture by reference
        // c capture by value 
        for_each(words.begin(), words.end(), [&, c](const std::string& s)
            {os << s << c; });
        // os capture by reference
        // c implicitly capture by value
        for_each(words.begin(), words.end(), [=, &os](const std::string& s)
            {os << s << c; });
        
    }

    return 0;
}