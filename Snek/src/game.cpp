#include "../include/game.h"
#include "../include/mainmenu.h"

Game::Game() : m_context(std::make_shared<Context>())
{
    m_context->m_window->create(sf::VideoMode(800,600), "SNEK", sf::Style::Close);
    m_context->m_states->AddNewState(std::make_unique<MainMenu>(m_context));
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

        while(timeSinceLastFrame > TIME_PER_FRAME)
        {
            timeSinceLastFrame-=TIME_PER_FRAME;


            m_context->m_states->ProcessStateChange();
            m_context->m_states->GetCurrentState()->ProcessInput();
            m_context->m_states->GetCurrentState()->Update(TIME_PER_FRAME);
            m_context->m_states->GetCurrentState()->Draw();
        }
    }
}
