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

MenuState::MenuState(sf::RenderWindow& window, CoreGame* game) : GameState(window, game)
{
    //setting text and font
    this->font = new sf::Font();
    this->font->loadFromFile(resourcePath() + "sansation.ttf");
    this->text = new sf::Text();
    this->text->setFont(*this->font);
    this->text->setString("Reversi");
    this->text->setCharacterSize(64u);
    //set origin to the middle
    this->text->setOrigin(this->text->getGlobalBounds().width / 2., this->text->getGlobalBounds().height / 2.);
    //set position to horizontally middle and vertically quarter
    this->text->setPosition(window.getSize().x / 2., window.getSize().y / 4.);
    
    //button
}

void MenuState::handleInput(sf::Event& event)
{
    
}

void MenuState::update()
{
    
}

void MenuState::render()
{
    //draw text
    this->getWindow()->draw(*this->text);
    
    //draw button
}

MenuState::~MenuState()
{
    delete this->text;
    delete this->font;
}