#include "Dictionary.h"

#include <iostream>
#include <string>
#include <algorithm>
#include <thread>

void Dictionary::Init() {
    std::string word;

    while (true) try {
        std::cin >> word;

        if (word == "===") {
            std::cin.ignore();
            std::cin.clear();
            break;
        }

        std::string sorted_word = word;
        sort(word.begin(), word.end());
        data[word.length()].emplace(make_pair(std::move(word), std::move(sorted_word)));
    }
    catch (const std::exception& e) {
        system("cls");
        std::cout << "Dictionary init error: " << e.what() << std::endl;
        system("pause");
        return;
    }
}

void Dictionary::Search(std::string& word) {
    std::vector<std::string> matched_words;

    std::thread th1([&] {
        for (const auto dictionary_word : data[word.length()]) {
            std::string sorted_word = word;
            std::sort(sorted_word.begin(), sorted_word.end());


            if (word == dictionary_word.second) {
                matched_words.push_back(dictionary_word.second);
                return;
            }

            else if (dist(sorted_word, dictionary_word.first) <= 1) {
                matched_words.push_back(dictionary_word.second);
            }

            else if (dist(word, dictionary_word.second) <= 1) {
                matched_words.push_back(dictionary_word.second);
            }
        }
    });

    std::thread th2([&] {
        for (const auto dictionary_word : data[word.length() + 1]) {
            std::string sorted_word = word;
            std::sort(sorted_word.begin(), sorted_word.end());

            if (word == dictionary_word.second) {
                matched_words.push_back(dictionary_word.second);
            }

            else if (dist(sorted_word, dictionary_word.first) <= 1) {
                matched_words.push_back(dictionary_word.second);
            }

            else if (dist(word, dictionary_word.second) <= 1) {
                matched_words.push_back(dictionary_word.second);
            }
        }
    });

    for (const auto dictionary_word : data[word.length() - 1]) {
        std::string sorted_word = word;
        std::sort(sorted_word.begin(), sorted_word.end());

        if (word == dictionary_word.second) {
            matched_words.push_back(dictionary_word.second);
        }

        else if (dist(sorted_word, dictionary_word.first) <= 1) {
            matched_words.push_back(dictionary_word.second);
        }

        else if (dist(word, dictionary_word.second) <= 1) {
            matched_words.push_back(dictionary_word.second);
        }
    }

    th1.join();
    th2.join();

    if (matched_words.empty()) {
        word = "{" + word + "?}";
    }

    else if (matched_words.size() == 1) {
        word = matched_words[0];
    }

    else {
        word = "{";
        for (auto i = 0; i < matched_words.size(); ++i) {
            word += matched_words[i];
            if (i < matched_words.size() - 1) {
                word += ' ';
            }
        }
        word += "}";
    }
}

uint16_t Dictionary::min3(const uint16_t n1, const uint16_t n2, const uint16_t n3) {
    int ans = n1;
    if (n2 < ans)
        ans = n2;
    if (n3 < ans)
        ans = n3;
    return ans;
}

uint16_t Dictionary::m(const char a, const  char b) {
    if (a == b)
        return 0;
    else
        return 1;
}

uint16_t Dictionary::dist(const std::string& word, const std::string& dictionary_word) {
    uint16_t l1 = word.length();
    uint16_t l2 = dictionary_word.length();

    std::vector<uint16_t> current_row(l2 + 1);
    std::vector<uint16_t> previous_row(l2 + 1);

    for (uint16_t j = 0; j <= l2; j++)
        current_row[j] = j;

    for (uint16_t i = 1; i <= l1; i++) {
        previous_row = current_row;
        current_row[0] = i;
        for (uint16_t j = 1; j <= l2; j++) {
            uint16_t temp1, temp2, temp3;
            temp1 = previous_row[j] + 1;
            temp2 = current_row[j - 1] + 1;
            temp3 = previous_row[j - 1] + m(word[i - 1], dictionary_word[j - 1]);
            current_row[j] = min3(temp1, temp2, temp3);

        }
    }

    return current_row[l2];
}



Dictionary::~Dictionary() {
    data.clear();
    std::cout << std::endl;
}
