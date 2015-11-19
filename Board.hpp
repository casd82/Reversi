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
#include "Chess.hpp"

class Board : public sf::Drawable
{
public:
    static const int SIZE = 8;
    
    Board();
    ~Board();
private:
    //override
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    
    //struct of slot
    struct Slot
    {
        Chess* chess;
        int side;
        sf::RectangleShape gridRect;
    };
    
    //board in 2d vector
    std::vector<std::vector<Slot>> matrix;
};

#endif /* Board_hpp */
