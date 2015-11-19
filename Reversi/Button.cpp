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
    target.draw(*this->shape, states);
    target.draw(*this->text, states);
}

Button::Button()
{
    //setting text and font
    this->font = new sf::Font();
    this->font->loadFromFile(resourcePath() + "sansation.ttf");
    this->text = new sf::Text();
    this->text->setFont(*this->font);
    this->text->setString("Default");
    this->text->setColor(sf::Color::Black);
    this->text->setCharacterSize(25u);
    this->text->setOrigin(this->text->getGlobalBounds().width / 2., this->text->getGlobalBounds().height / 2.);
    
    //setting shape
    this->shape = new sf::RectangleShape();
    this->shape->setFillColor(sf::Color::White);
    
    //set outline
    this->shape->setOutlineThickness(2);
    this->shape->setOutlineColor(sf::Color::Black);
    
    //set size & origin
    this->shape->setSize(sf::Vector2f(80, 30));
    this->shape->setOrigin(this->shape->getGlobalBounds().width / 2., this->text->getGlobalBounds().height / 2.);
    
    //position
    this->position = sf::Vector2f(0., 0.);
    this->updatePosition();
}

void Button::handleInput(sf::Event& event)
{
    if (event.type == sf::Event::MouseMoved)
    {
        if (this->shape->getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
        {
            this->hoverOver();
        }
        else
        {
            this->reset();
        }
    }
    
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (this->shape->getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
        {
            this->pressed();
        }
    }
}

Button::~Button()
{
    delete this->font;
    delete this->text;
}

void Button::hoverOver()
{
    sf::Color color = sf::Color::Black;
    //set alpha
    color.a = 100u;
    this->shape->setFillColor(color);
    
}

void Button::reset()
{
    this->shape->setFillColor(sf::Color::White);
}

void Button::pressed()
{
    this->shape->setFillColor(sf::Color::Black);
    
    //call the action
    this->action();
}

void Button::setAction(std::function<void(void)> action)
{
    this->action = action;
}

void Button::setPosition(const float x, const float y)
{
    this->position.x = x;
    this->position.y = y;
    
    this->updatePosition();
}

void Button::updatePosition()
{
    this->shape->setPosition(this->position);
    this->text->setPosition(this->position);
}

void Button::setString(const std::string& str)
{
    this->text->setString(str);
    
    //reset origin
    this->text->setOrigin(this->text->getGlobalBounds().width / 2., this->text->getGlobalBounds().height / 2.);
    
    this->updatePosition();
}