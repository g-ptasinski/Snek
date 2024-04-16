#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

int main(int argc, char **argv) {

    sf::RenderWindow Window(sf::VideoMode(800,600), "SNEK");
    sf::CircleShape shape(100, 30);
    shape.setFillColor(sf::Color::Red);

    while(Window.isOpen())
    {
        sf::Event event;

        while(Window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                Window.close();
        }

        Window.clear();
        Window.draw(shape);
        Window.display();
    }

    return 0;
}
