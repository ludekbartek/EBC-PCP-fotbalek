//
//  Game.cpp
//  Fotbalek
//
//  Created by Jakub Sadílek on 22.09.2026.
//

#include "Game.h"
#include "Dictionary.h"
Game::Game(Dictionary * dictionary) {
    m_dictionary=dictionary;

}
Game::~Game() {
    delete m_dictionary;
}

void Game::play() {
    std::string currentWord;
    std::string previousWord =m_dictionary->getFirstWord();
    std::cout <<"--------------------\n"
                "    Slovni fotbal   \n"
                "--------------------\n\n"
                "Prvni slovo: \n"
                << previousWord
    ;
    bool mainLoop = true;
    while (mainLoop) {
        std::cout << "\nOdpoved: \n";
        std::cin >> currentWord;
        if (!m_dictionary->checkWord(previousWord,currentWord)) {
            return;
        }
        previousWord = currentWord;
        currentWord=m_dictionary->findNextWord(previousWord);
        if (currentWord == "Slova na toto pismeno uz neexistuje ve slovniku") {
            std::cout << currentWord << "\nVyhral jsi!\n";
            return;
        }
        std::cout <<"Slovo:\n"<< currentWord;
        previousWord = currentWord;

    }
}

