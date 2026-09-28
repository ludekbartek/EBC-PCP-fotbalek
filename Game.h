//
//  Game.h
//  Fotbalek
//
//  Created by Jakub Sadílek on 22.09.2026.
//

#ifndef game_hpp
#define game_hpp

#include <iostream>

#include "Dictionary.h"

class Game {
    Dictionary * m_dictionary;
public:
    Game(Dictionary * dictionary);
    ~Game();
    void play();

};

#endif /* game_hpp */