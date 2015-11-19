#include <SFML/Graphics.hpp>

#include "ResourcePath.hpp"
#include "CoreGame.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(514, 514), "Reversi", sf::Style::Close | sf::Style::Titlebar);
    CoreGame coreGame(&window);
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
            coreGame.handleInput(event);
        }
        
        coreGame.update();
        
        //render
        window.clear(sf::Color::White);
        coreGame.render();
        window.display();
    }
    
    return 0;
}
