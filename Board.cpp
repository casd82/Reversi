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
    
    //the initial board
    this->matrix[3][3].chess = new Chess(Chess::BLACK, 3, 3);
    this->matrix[4][4].chess = new Chess(Chess::BLACK, 4, 4);
    this->matrix[4][3].chess = new Chess(Chess::WHITE, 4, 3);
    this->matrix[3][4].chess = new Chess(Chess::WHITE, 3, 4);
    
    //black starts first
    turn = Chess::BLACK;
}

void Board::recordPossibleMoves()
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            //8 directions
            std::vector<std::pair<int, int>> directions{{-1, -1}, {-1, 0}, {-1, 1},
                                                        {0 , -1}, /* ^^ */ {0 , 1},
                                                        {1 , -1}, {1 , 0}, {1 , 1}};
            for (auto dir : directions)
                this->checkPossibleMove(i, j, dir);
        }
    }
}

void Board::checkPossibleMove(int i, int j, std::pair<int, int> dir)
{
    //clear the possible moves last turn
    this->matrix[i][j].moves.clear();
    
    //occupied
    if (this->matrix[i][j].chess) return;
    
    //.............to be completed............//
}

void Board::clickBoard(float mouseX, float mouseY)
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            //check which block is clicked and whether it has possible moves
            if (this->matrix[i][j].gridRect.getGlobalBounds().contains(mouseX, mouseY) && !this->matrix[i][j].moves.empty())
            {
                //flip chesses and next turn
                
            }
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
            Slot s = this->matrix[i][j];
            
            //draw board grid
            target.draw(s.gridRect, states);
            
            //draw chess
            if (s.chess != nullptr)
                target.draw(*(s.chess), states);
        }
    }
}

Board::~Board()
{
    //delete chess
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            if (this->matrix[i][j].chess != nullptr)
                delete this->matrix[i][j].chess;
        }
    }
}