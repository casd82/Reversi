//
//  PlayingState.hpp
//  Reversi
//
//  Created by YU CHAO on 2015/11/19.
//  Copyright © 2015年 Darkness Left. All rights reserved.
//

#ifndef PlayingState_hpp
#define PlayingState_hpp

#include "GameState.hpp"
#include "Board.hpp"

class PlayingState : public GameState
{
public:
    PlayingState(sf::RenderWindow* window, CoreGame* coreGame);
    void handleInput(sf::Event& event);
    void update();
    void render();
    ~PlayingState();
    
private:
    Board* board;
};

#endif /* PlayingState_hpp */
