//
//  PlayingState.cpp
//  Reversi
//
//  Created by YU CHAO on 2015/11/19.
//  Copyright © 2015年 Darkness Left. All rights reserved.
//

#include "PlayingState.hpp"

PlayingState::PlayingState(sf::RenderWindow* window, CoreGame* coreGame) : GameState(window, coreGame)
{
    this->board = new Board();
}

void PlayingState::handleInput(sf::Event& event)
{
    if (event.type == sf::Event::MouseMoved)
    {
        this->board->hoverBoard(event.mouseMove.x, event.mouseMove.y);
    }
    
    if (event.type == sf::Event::MouseButtonPressed)
    {
        this->board->clickBoard(event.mouseButton.x, event.mouseButton.y);
    }
}

void PlayingState::update()
{
    
}

void PlayingState::render()
{
    this->getWindow()->draw(*this->board);
}

PlayingState::~PlayingState()
{
    delete this->board;
}