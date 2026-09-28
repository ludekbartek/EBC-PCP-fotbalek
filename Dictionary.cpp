//
//  Dictionary.cpp
//  Fotbalek
//
//  Created by Jakub Sadílek on 22.09.2026.

#include <string>
#include <vector>
#include <Dictionary.h>
#include <iostream>

Dictionary::Dictionary(std::vector<std::string> dictionary) {
    m_dictionary = dictionary;
}


std::string Dictionary::getFirstWord() {
    srand(time(nullptr));
    int index = std::rand() % m_dictionary.size();
    addToUsed(m_dictionary[index]);
    return m_dictionary[index];
}

std::string Dictionary::findNextWord(std::string previousWord) {
    std::vector<std::string> possibleWords;
    for (std::string word : m_dictionary) {
       if (checkWordUnused(word) && previousWord.back()==word.front()) {
           possibleWords.push_back(word);
       }

    }if (possibleWords.empty()) return "Slova na toto pismeno uz neexistuje ve slovniku";
    srand(time(nullptr));
    int index = std::rand() % possibleWords.size();
    addToUsed(possibleWords[index]);
    return possibleWords[index];

}
bool Dictionary::checkWord(std::string previousWord,std::string currentWord) {

    if (!checkWordExists(currentWord)) {
        std::cout << "Slovo neexistuje ve slovniku\n";
        return false;
    }
    if (!checkWordUnused(currentWord)) {
        std::cout << "Slovo uz bylo pouzito\n";
        return false;
    }
    if (!checkWordFollows(previousWord, currentWord)) {
        std::cout << "Slovo nenavazuje\n";
        return false;
    }
    addToUsed(currentWord);
    return true;
}
bool Dictionary::checkWordFollows(std::string previousWord,std::string currentWord) {

    bool isCorrect = false;
    if (currentWord.front() ==  previousWord.back()) {
        isCorrect = true;
    }
    return isCorrect;
}
bool Dictionary::checkWordUnused(std::string currentWord) {
    bool isCorrect = true;
    for (std::string word : m_used_words) {
        if (word==currentWord) {
            isCorrect = false;
        }
    }
    return isCorrect;

}
bool Dictionary::checkWordExists(std::string currentWord) {
    bool isCorrect = false;
    for (std::string word : m_dictionary) {
        if (word==currentWord) {
            isCorrect = true;
        }
    }
    return isCorrect;

}

void Dictionary::addToUsed(std::string currentWord) {
    m_used_words.push_back(currentWord);

}
