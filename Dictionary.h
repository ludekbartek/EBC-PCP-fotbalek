//
//  Dictionary.h
//  Fotbalek
//
//  Created by Jakub Sadílek on 22.09.2026.
//
#ifndef dictionary_hpp
#define dictionary_hpp

#include <string>
#include <vector>

class Dictionary {
    std::vector<std::string> m_dictionary;
    std::vector<std::string> m_used_words;
    bool checkWordFollows(std::string previousWord,std::string currentWord);
    bool checkWordUnused(std::string currentWord);
    bool checkWordExists(std::string currentWord);
    void addToUsed(std::string currentWord);

public:
    Dictionary(std::vector<std::string> dictionary);
    std::string getFirstWord();
    std::string findNextWord(std::string previousWord);
    bool checkWord(std::string previousWord,std::string currentWord);
};
#endif /* dictionary_hpp */

