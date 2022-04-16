#include "Dictionary.h"
#include <iostream>
#include <string>
#include <vector>

void checkSpelling(std::vector<std::vector<std::string>>& input, Dictionary& dictionary) {
    for (size_t i = 0; i < input.size(); ++i) {
        for (size_t j = 0; j < input[i].size(); ++j) {
            dictionary.Search(input[i][j]);
        }
    }
}