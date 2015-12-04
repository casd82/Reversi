//
//  Button.hpp
//  Reversi
//
//  Created by YU CHAO on 2015/11/17.
//  Copyright © 2015年 Darkness Left. All rights reserved.
//

#ifndef Button_hpp
#define Button_hpp

#include <SFML/Graphics.hpp>

class Button : public sf::Drawable
{
public:
    Button();
    void handleInput(sf::Event& event);
    ~Button();
    
    //setters
    void setString(const std::string& str);
    void setAction(std::function<void(void)> action);
    void setPosition(const float x, const float y);
    
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    
    void updatePosition();
    
    void pressed();
    void hoverOver();
    void reset();
    
    //fields
    sf::Text* text;
    sf::Font* font;
    sf::RectangleShape* shape;
    std::function<void(void)> action;
    sf::Vector2f position;
};

#endif /* Button_hpp */
