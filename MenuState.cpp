//
//  MenuState.cpp
//  Reversi
//
//  Created by YU CHAO on 2015/11/16.
//  Copyright © 2015年 Darkness Left. All rights reserved.
//

#include <SFML/Graphics.hpp>
#include "MenuState.hpp"
#include "GameState.hpp"
#include "ResourcePath.hpp"
#include "PlayingState.hpp"
#include "CoreGame.hpp"
#include <iostream>
#include "Button.hpp"

MenuState::MenuState(sf::RenderWindow* window, CoreGame* game) : GameState(window, game)
{
    //setting text and font
    this->font = new sf::Font();
    this->font->loadFromFile(resourcePath() + "sansation.ttf");
    this->text = new sf::Text();
    this->text->setFont(*this->font);
    this->text->setString("Reversi");
    this->text->setColor(sf::Color::Black);
    this->text->setCharacterSize(64u);
    
    //set origin to the middle
    this->text->setOrigin(this->text->getGlobalBounds().width / 2., this->text->getGlobalBounds().height / 2.);
    
    //set position to horizontally middle and vertically quarter
    this->text->setPosition(window->getSize().x / 2., window->getSize().y / 4.);
    
    //button
    this->startBtn = new Button();
    this->startBtn->setString("Start");
    this->startBtn->setAction([window, game]{game->changeState(new PlayingState(window, game));});
    this->startBtn->setPosition(window->getSize().x / 2., window->getSize().y * .6);
}

void MenuState::handleInput(sf::Event& event)
{
    this->startBtn->handleInput(event);
}

void MenuState::update()
{
    
}

void MenuState::render()
{
    //draw text
    this->getWindow()->draw(*this->text);
    
    //draw button
    this->getWindow()->draw(*this->startBtn);
}

MenuState::~MenuState()
{
    delete this->text;
    delete this->font;
    delete this->startBtn;
}