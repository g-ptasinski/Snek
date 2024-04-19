#include "../include/game.h"

Game::Game() : m_context(std::make_shared<Context>())
{
    m_context->m_window->create(sf::VideoMode(800,600), "SNEK", sf::Style::Close);
}

Game::~Game()
{

}

void Game::Run()
{
    sf::CircleShape shape(100, 30);
    shape.setFillColor(sf::Color::Red);

    sf::Clock clock;
    sf::Time timeSinceLastFrame = sf::Time::Zero;

    while(m_context->m_window->isOpen())
    {
        timeSinceLastFrame += clock.restart();

        sf::Event event;

        while(m_context->m_window->pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                m_context->m_window->close();
        }

        m_context->m_window->clear();
        m_context->m_window->draw(shape);
        m_context->m_window->display();
    }
}
