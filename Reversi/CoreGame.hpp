//
//  CoreGame.hpp
//  Reversi
//
//  Created by YU CHAO on 2015/11/16.
//  Copyright © 2015年 Darkness Left. All rights reserved.
//

#ifndef CoreGame_hpp
#define CoreGame_hpp

#include "GameState.hpp"

class CoreGame
{
public:
    //game loop
    CoreGame(sf::RenderWindow& window);
    void handleInput(sf::Event& event);
    void update();
    void render();
    ~CoreGame();
    
    //change state
    void changeState(GameState* newState);
private:
    GameState* currentState;
    sf::RenderWindow* window;
};

#endif /* CoreGame_hpp */
