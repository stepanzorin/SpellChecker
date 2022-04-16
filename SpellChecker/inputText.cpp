#include <iostream>
#include <string>
#include <vector>
#include <sstream>

void inputText(std::vector<std::vector<std::string>>& input) {
    std::vector<std::string> words;
    std::string line;

    while (std::getline(std::cin, line)) try {
        if (line == "===") {
            break;
        }

        std::istringstream is(line);
        std::string temp;
        while (is >> temp)
            words.push_back(std::move(temp));

        input.push_back(std::move(words));
    }
    catch (const std::exception& e) {
        system("cls");
        std::cout << "Input text error: " << e.what() << std::endl;
        system("pause");
        return;
    }
}