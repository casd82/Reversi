//
//  Chess.hpp
//  Reversi
//
//  Created by YU CHAO on 2015/11/19.
//  Copyright © 2015年 Darkness Left. All rights reserved.
//

#ifndef Chess_hpp
#define Chess_hpp
#include <SFML/Graphics.hpp>

class Chess : public sf::Drawable
{
public:
    typedef enum {BLACK, WHITE} ChessColor;
    
    Chess(ChessColor c, int i, int j, bool alpha = false, bool indicator = false);
    void flipSide();
    ChessColor getColor() {return this->chessColor;};
    ~Chess();
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    
    ChessColor chessColor;
    sf::CircleShape* shape;
};

#endif /* Chess_hpp */
