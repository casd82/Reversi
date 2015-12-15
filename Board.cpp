//
//  Board.cpp
//  Reversi
//
//  Created by YU CHAO on 2015/11/19.
//  Copyright © 2015年 Darkness Left. All rights reserved.
//

#include "Board.hpp"
#include <iostream>

Board::Board() : hoverChess(nullptr)
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
    
    recordPossibleMoves();
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
            
            //clear the possible moves recorded last turn
            this->matrix[i][j].moves.clear();
            
            for (auto dir : directions)
                this->checkPossibleMove(i, j, dir);
        }
    }
}

void Board::checkPossibleMove(int i, int j, std::pair<int, int> dir)
{
    //occupied
    if (this->matrix[i][j].chess != nullptr) return;
    
    int moves = -1, i0 = i, j0 = j;
    
    do {
        //next slot
        i0 += dir.first;
        j0 += dir.second;
        
        //out of bounds
        if (i0 >= SIZE || j0 >= SIZE || i0 < 0 || j0 < 0) return;
        
        //empty
        if (this->matrix[i0][j0].chess == nullptr) return;
        
        ++moves;
        
    } while (this->matrix[i0][j0].chess->getColor() != this->turn);
    
    //set move to the map
    if (moves > 0)
        this->matrix[i][j].moves[dir] = moves;
}

void Board::hoverBoard(float mouseX, float mouseY)
{
    //delete the previous hover chess
    if (this->hoverChess != nullptr)
    {
        delete this->hoverChess;
        this->hoverChess = nullptr;
    }
    
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            //in the block, not occupied, and have moves
            if (this->matrix[i][j].gridRect.getGlobalBounds().contains(mouseX, mouseY) && this->matrix[i][j].chess == nullptr && !this->matrix[i][j].moves.empty())
            {
                this->hoverChess = new Chess(this->turn, i, j, true);
            }
        }
    }
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
                //delete the hover chess
                
                //place chess where the player clicks
                this->matrix[i][j].chess = new Chess(this->turn, i, j);
                
                //flip chesses and next turn
                for (auto iter = matrix[i][j].moves.cbegin(); iter != matrix[i][j].moves.cend(); ++iter)
                {
                    int i0 = i, j0 = j;
                    
                    //flip
                    for (int n = 0; n < iter->second; ++n)
                    {
                        i0 += iter->first.first;
                        j0 += iter->first.second;
                        
                        this->matrix[i0][j0].chess->flipSide();
                    }
                }
                
                nextTurn();
                countScore();
            }
        }
    }
}

void Board::nextTurn()
{
    
    if (this->turn == Chess::BLACK)
        this->turn = Chess::WHITE;
    else
        this->turn = Chess::BLACK;
    
    recordPossibleMoves();
    
    //no possible moves
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            if (!this->matrix[i][j].moves.empty())
            {
                this->noPossibleMoves = false;
                return;
            }
        }
    }
    
    if (this->turn == Chess::BLACK)
        this->turn = Chess::WHITE;
    else
        this->turn = Chess::BLACK;
    
    recordPossibleMoves();
    
    if (this->noPossibleMoves)
    {
        this->noPossibleMovesForBoth = true;
    }
    
    this->noPossibleMoves = true;
}

void Board::countScore()
{
    this->blackScore = 0;
    this->whiteScore = 0;
    
    for (auto i : matrix)
    {
        for (auto j : i)
        {
            if (j.chess != nullptr)
            {
                if (j.chess->getColor() == Chess::BLACK)
                {
                    ++this->blackScore;
                }
                else
                {
                    ++this->whiteScore;
                }
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
    
    if (hoverChess != nullptr) target.draw(*hoverChess, states);
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