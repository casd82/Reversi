//
//  PlayingState.cpp
//  Reversi
//
//  Created by YU CHAO on 2015/11/19.
//  Copyright © 2015年 Darkness Left. All rights reserved.
//

#include "PlayingState.hpp"
#include "ResourcePath.hpp"

PlayingState::PlayingState(sf::RenderWindow* window, CoreGame* coreGame) : GameState(window, coreGame)
{
    this->board = new Board();
    
    //set font and text
    this->font = new sf::Font();
    this->font->loadFromFile(resourcePath() + "sansation.ttf");
    this->turnIndicatingText = new sf::Text();
    this->turnIndicatingText->setFont(*this->font);
    this->turnIndicatingText->setCharacterSize(20u);
    this->turnIndicatingText->setColor(sf::Color::Black);
    this->turnIndicatingText->setPosition(520, 60);
    
    //set turn indicator
    this->turnIndicatingChess = new Chess(this->board->getTurn(), 0, 0, false, true);
    this->turnIndicatingText->setString(turnString());
    
}

std::string PlayingState::turnString() const
{
    std::string s = this->board->getTurn() == Chess::BLACK ? "Black's" : "White's";
    s.append(" turn");
    return s;
}

void PlayingState::updateTurnIndicator()
{
    if (this->board->getTurn() != this->turnIndicatingChess->getColor())
    {
        this->turnIndicatingChess->flipSide();
        this->turnIndicatingText->setString(turnString());
    }
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
    this->updateTurnIndicator();
}

void PlayingState::render()
{
    this->getWindow()->draw(*this->board);
    this->getWindow()->draw(*this->turnIndicatingChess);
    this->getWindow()->draw(*this->turnIndicatingText);
}

PlayingState::~PlayingState()
{
    delete this->board;
    delete this->font;
    delete this->turnIndicatingText;
    delete this->turnIndicatingChess;
}