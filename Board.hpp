//
//  Board.hpp
//  Reversi
//
//  Created by YU CHAO on 2015/11/19.
//  Copyright © 2015年 Darkness Left. All rights reserved.
//

#ifndef Board_hpp
#define Board_hpp
#include <SFML/Graphics.hpp>
#include <vector>
#include <map>
#include "Chess.hpp"

class Board : public sf::Drawable
{
public:
    static const int SIZE = 8;
    
    //Loop of Board
    Board();
    void recordPossibleMoves();
    void clickBoard(float mouseX, float mouseY);
    void hoverBoard(float mouseX, float mouseY);
    bool cannotMove() const {return noPossibleMoves;};
    ~Board();
    
    //getters
    Chess::ChessColor getTurn() const {return this->turn;};
    int getBlackScore() const {return this->blackScore;};
    int getWhiteScore() const {return this->whiteScore;};
    bool getNoPossibleMovesForBoth() const {return this->noPossibleMovesForBoth;};
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    
    //struct of slot
    struct Slot
    {
        Chess* chess;
        int side;
        sf::RectangleShape gridRect;
        
        //records possible moves of this slot.  Map: {(x,y) directions -> length}
        std::map<std::pair<int, int>, int> moves;
    };
    
    void nextTurn();
    
    void countScore();
    
    void checkPossibleMove(int i, int j, std::pair<int, int> dir);
    
    //records current turn
    Chess::ChessColor turn;
    
    bool noPossibleMoves = false;
    bool noPossibleMovesForBoth = false;
    
    //score
    int whiteScore = 2;
    int blackScore = 2;
    
    //hover chess
    Chess* hoverChess;
    
    //board in 2d vector
    std::vector<std::vector<Slot>> matrix;
};

#endif /* Board_hpp */
