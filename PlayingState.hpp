//
//  PlayingState.hpp
//  Reversi
//
//  Created by YU CHAO on 2015/11/19.
//  Copyright © 2015年 Darkness Left. All rights reserved.
//

#ifndef PlayingState_hpp
#define PlayingState_hpp

#include "GameState.hpp"
#include "Board.hpp"
#include "Chess.hpp"
#include "Button.hpp"

class PlayingState : public GameState
{
public:
    PlayingState(sf::RenderWindow* window, CoreGame* coreGame);
    void handleInput(sf::Event& event);
    void update();
    void render();
    ~PlayingState();
    
private:
    Board* board;
    Chess* turnIndicatingChess;
    Button* restartButton;
    Button* exitButton;
    sf::Text* turnIndicatingText;
    sf::Text* cannotMoveText;
    sf::Text* scoreText;
    sf::Text* winText;
    sf::Font* font;
    bool win = false;
    
    std::string turnString() const;
    void updateTurnIndicator();
    void checkWin();
    void updateScore();
};

#endif /* PlayingState_hpp */
