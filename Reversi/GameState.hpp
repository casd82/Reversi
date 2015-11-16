//
//  GameState.hpp
//  Reversi
//
//  Created by YU CHAO on 2015/11/16.
//  Copyright © 2015年 Darkness Left. All rights reserved.
//

#ifndef GameState_hpp
#define GameState_hpp

#include <SFML/Graphics.hpp>

class CoreGame;

class GameState
{
public:
    GameState(sf::RenderWindow& window, CoreGame* game);
    virtual void handleInput(sf::Event& event){};
    virtual void update(){};
    virtual void render(){};
    ~GameState(){};
private:
    sf::RenderWindow* window;
    CoreGame* coreGame;
};

#endif /* GameState_hpp */
