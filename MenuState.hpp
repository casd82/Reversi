//
//  MenuState.hpp
//  Reversi
//
//  Created by YU CHAO on 2015/11/16.
//  Copyright © 2015年 Darkness Left. All rights reserved.
//

#ifndef MenuState_hpp
#define MenuState_hpp

#include <SFML/Graphics.hpp>
#include "GameState.hpp"
#include "Button.hpp"

class MenuState : public GameState
{
public:
    MenuState(sf::RenderWindow* window, CoreGame* coreGame);
    virtual void handleInput(sf::Event& event);
    virtual void update();
    virtual void render();
    ~MenuState();
private:
    sf::Text* text;
    sf::Font* font;
    Button* startBtn;
};

#endif /* MenuState_hpp */
