#pragma once
#include <unordered_map>
#include <map>
#include <string>

class Dictionary final {
public:
    void Init();
    void Search(std::string&);



private:
    //                 word length           sorted word      word 
    std::unordered_map<std::size_t, std::map<std::string, std::string>> data;
    
    // Levenshtein's distance
    int m(const char, const  char);
    int min3(const int, const  int, const  int);
    uint16_t dist(const std::string&, const std::string&);

};

