//
//  Board.cpp
//  Reversi
//
//  Created by YU CHAO on 2015/11/19.
//  Copyright © 2015年 Darkness Left. All rights reserved.
//

#include "Board.hpp"

Board::Board()
{
    for (int i = 0; i < SIZE; ++i)
    {
        this->matrix.push_back(std::vector<Slot>());
        
        for (int j = 0; j < SIZE; ++j)
        {
            Slot newSlot;
            newSlot.chess = nullptr;
            
            //rect
            newSlot.gridRect = sf::RectangleShape();
            newSlot.gridRect.setOutlineThickness(2);
            newSlot.gridRect.setOutlineColor(sf::Color::Black);
            newSlot.gridRect.setSize(sf::Vector2f(62, 62));
            newSlot.gridRect.setPosition(2. + 64. * j, 2. + 64. * i);
            
            this->matrix[i].push_back(newSlot);
        }
    }
}

//override
void Board::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            //draw board grid
            target.draw(matrix[i][j].gridRect, states);
        }
    }
}

Board::~Board()
{
    
}