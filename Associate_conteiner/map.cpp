#include <map>
#include <string>

#include "all_function.h"

int map() {

    std::map<std::string, size_t> word_count; // key - string; value - size_t
    std::string word;
    while (std::cin >> word)
        ++word_count[word];
    for (const auto& w : word_count)
        std::cout << w.first << "occurs" << w.second << std::endl;
    return 0;
}