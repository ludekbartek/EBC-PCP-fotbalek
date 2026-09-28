//
//  main.cpp
//  Fotbalek
//
//  Created by Jakub Sadílek on 22.09.2026.
//

#include <ctime>
#include <iostream>

#include "Dictionary.h"
#include "Game.h"

int main() {
    std::time(nullptr);
    std::vector<std::string> testDictionary = {"auto", "okno", "okurka", "ananas", "strom"};
    Dictionary * dictionary = new Dictionary(testDictionary);
    Game * game = new Game(dictionary);
    game->play();
    delete game;
}
