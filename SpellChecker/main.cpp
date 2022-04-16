#include "Dictionary.h"

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <sstream>

void inputText(std::vector<std::vector<std::string>>&);
void checkSpelling(std::vector<std::vector<std::string>>&, Dictionary&);

int main() {
    Dictionary dictionary;

    // 1. Составляем словарь
    dictionary.Init();

    // 2. Получаем текст для проверки от пользователя
    std::vector<std::vector<std::string>> input;
    inputText(input);

    // 3. Проверяем полученный текст на ошибки
    checkSpelling(input, dictionary);

    // 4. Выводим текст после проверки на орфаграфию
    for (size_t i = 0; i < input.size(); ++i) {
        for (size_t j = 0; j < input[i].size(); ++j) {
            std::cout << input[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}



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
    } catch (const std::exception& e) {
        system("cls");
        std::cout << "Input data error: " << e.what() << std::endl;
        system("pause");
        return;
    }
}

void checkSpelling(std::vector<std::vector<std::string>>& input, Dictionary& dictionary) {
    for (size_t i = 0; i < input.size(); ++i) {
        for (size_t j = 0; j < input[i].size(); ++j) {
            dictionary.Search(input[i][j]);
        }
    }
}



/*

        rain spain plain plaint main mainly the in on fall falls his was
===
hte rame in pain fells
mainy oon teh lain
was hints pliant
===


        */