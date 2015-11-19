//
//  Chess.cpp
//  Reversi
//
//  Created by YU CHAO on 2015/11/19.
//  Copyright © 2015年 Darkness Left. All rights reserved.
//

#include "Chess.hpp"

Chess::Chess()
{
    this->shape = new sf::CircleShape();
}

void Chess::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(*this->shape, states);
}

Chess::~Chess()
{
    delete this->shape;
}