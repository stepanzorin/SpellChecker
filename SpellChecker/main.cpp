#include "Dictionary.h"

#include <iostream>
#include <string>
#include <vector>

void inputText(std::vector<std::vector<std::string>>&);
void checkSpelling(std::vector<std::vector<std::string>>&, Dictionary&);

int main() {
    Dictionary dictionary;

    // 1. Init the dictionary
    dictionary.Init();

    // 2. Get a text from user for spell checking.
    std::vector<std::vector<std::string>> input;
    inputText(input);

    // 3. Check spelling
    checkSpelling(input, dictionary);

    // 4. Output the result
    for (size_t i = 0; i < input.size(); ++i) {
        for (size_t j = 0; j < input[i].size(); ++j) {
            std::cout << input[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

/*
                        Test text

rain spain plain plaint main mainly the in on fall falls his was
===
hte rame in pain fells
mainy oon teh lain
was hints pliant
===

 */