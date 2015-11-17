//
//  Button.cpp
//  Reversi
//
//  Created by YU CHAO on 2015/11/17.
//  Copyright © 2015年 Darkness Left. All rights reserved.
//

#include "Button.hpp"
#include "ResourcePath.hpp"

//override (implement Drawable)
void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(*this->shape);
    target.draw(*this->text);
}

Button::Button()
{
    //setting text and font
    this->font = new sf::Font();
    this->font->loadFromFile(resourcePath() + "sansation.ttf");
    this->text = new sf::Text();
    this->text->setFont(*this->font);
    this->text->setString("Default");
    this->text->setCharacterSize(20u);
    this->text->setOrigin(this->text->getGlobalBounds().width / 2., this->text->getGlobalBounds().height / 2.);
    
    //setting shape
    this->shape = new sf::RectangleShape();
    this->shape->setFillColor(sf::Color::White);
    //set outline
    this->shape->setOutlineThickness(2);
    this->shape->setOutlineColor(sf::Color::Black);
    this->shape->setSize(sf::Vector2f(80, 30));
    
}

void Button::handleInput(sf::Event& event)
{
    if (event.type == sf::Event::MouseMoved)
    {
        if (this->shape->getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
        {
            
        }
    }
    
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (this->shape->getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
        {
            
        }
    }
}

Button::~Button()
{
    delete this->font;
    delete this->text;
}

void Button::update()
{
    
}