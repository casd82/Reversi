//
//  CoreGame.cpp
//  Reversi
//
//  Created by YU CHAO on 2015/11/16.
//  Copyright © 2015年 Darkness Left. All rights reserved.
//

#include "CoreGame.hpp"
#include "GameState.hpp"

CoreGame::CoreGame(sf::RenderWindow& window) : window(&window)
{
    this->currentState = new GameState(window, this);
}

void CoreGame::handleInput(sf::Event& event)
{
    this->currentState->handleInput(event);
}

void CoreGame::update()
{
    this->currentState->update();
}

void CoreGame::render()
{
    this->currentState->render();
}

CoreGame::~CoreGame()
{
    if (this->currentState != nullptr)
        delete this->currentState;
}

void CoreGame::changeState(GameState* newState)
{
    //delete the previous state if existed
    if (this->currentState != nullptr)
        delete this->currentState;
    
    this->currentState = newState;
}