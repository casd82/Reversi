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
    
private:
    //override
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    
    void update();
    
    //fields
    sf::Text* text;
    sf::Font* font;
    sf::RectangleShape* shape;
};

#endif /* Button_hpp */
