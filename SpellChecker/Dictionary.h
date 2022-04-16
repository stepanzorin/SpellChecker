#pragma once

#include <unordered_map>
#include <map>
#include <string>

class Dictionary final {
public:
    Dictionary() = default;
    void Init();
    void Search(std::string&);
    ~Dictionary();

private:
    //                 word length           sorted word      word 
    std::unordered_map<std::size_t, std::map<std::string, std::string>> data;
    
    // Levenshtein's distance 

    uint16_t m(const char, const  char);
    uint16_t min3(const uint16_t, const  uint16_t, const uint16_t);
    uint16_t dist(const std::string&, const std::string&);

};

