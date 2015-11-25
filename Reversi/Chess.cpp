//
//  Chess.cpp
//  Reversi
//
//  Created by YU CHAO on 2015/11/19.
//  Copyright © 2015年 Darkness Left. All rights reserved.
//

#include "Chess.hpp"
#include <iostream>

Chess::Chess(ChessColor c, int i, int j, bool alpha, bool indicator) : chessColor(c)
{
    //set shape
    this->shape = new sf::CircleShape();
    this->shape->setRadius(24);
    this->shape->setPosition(34. + 64. * j, 34. + 64. * i);
    this->shape->setOutlineThickness(2);
    this->shape->setOrigin(this->shape->getGlobalBounds().width / 2., this->shape->getGlobalBounds().height / 2.);
    
    //color
    sf::Color color = (this->chessColor == BLACK) ? (sf::Color::Black) : (sf::Color::White);
    if (alpha) color.a = 125;
    sf::Color alphaBlack = sf::Color::Black;
    alphaBlack.a = 125;
    this->shape->setOutlineColor(alpha ? alphaBlack : (sf::Color::Black));
    this->shape->setFillColor(color);
    
    if (indicator) this->shape->setPosition(573, 34);
}

void Chess::flipSide()
{
    this->chessColor == BLACK ? this->chessColor = WHITE : this->chessColor = BLACK;
    
    this->shape->setFillColor(this->chessColor == BLACK ? sf::Color::Black : sf::Color::White);
}

void Chess::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(*this->shape, states);
}

Chess::~Chess()
{
    delete this->shape;
}