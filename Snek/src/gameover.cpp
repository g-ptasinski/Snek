#include "../include/gameover.h"
#include <SFML/Window/Event.hpp>
#include "../include/gameplay.h"

Gameover::Gameover(std::shared_ptr<Context> &context)
    : m_context(context)
{
}

Gameover::~Gameover()
{

}

void Gameover::Init()
{
    m_context->m_assets->AddFont(MAIN_FONT, "../assets/fonts/PixelifySans-VariableFont_wght.ttf");

    //Game Title
    m_gameOverTitle.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_gameOverTitle.setCharacterSize(50);
    m_gameOverTitle.setString("SNEK");

    m_gameOverTitle.setOrigin(m_gameOverTitle.getLocalBounds().width / 2,
                          m_gameOverTitle.getLocalBounds().height / 2);
    m_gameOverTitle.setPosition(m_context->m_window->getSize().x / 2,
                            m_context->m_window->getSize().y / 4);

    //Play Button
    m_RetryButton.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_RetryButton.setString("Retry");
    m_RetryButton.setOrigin(m_RetryButton.getLocalBounds().width / 2,
                          m_RetryButton.getLocalBounds().height / 2);
    m_RetryButton.setPosition(m_context->m_window->getSize().x / 2,
                            m_context->m_window->getSize().y / 2 );

    //Exit Button
    m_ExitButton.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_ExitButton.setString("Exit");
    m_ExitButton.setOrigin(m_ExitButton.getLocalBounds().width / 2,
                          m_ExitButton.getLocalBounds().height / 2);
    m_ExitButton.setPosition(m_context->m_window->getSize().x / 2,
                            m_context->m_window->getSize().y / 2 + 40.f);

    m_isRetryButtonSelected = true;
    m_isExitButtonSelected = false;

    m_isRetryButtonPressed = false;
    m_isExitButtonPressed = false;

}


void Gameover::Update(sf::Time deltaTime)
{
    if(m_isExitButtonSelected)
    {
        m_ExitButton.setFillColor(sf::Color::Yellow);
    }
    else
    {
        m_ExitButton.setFillColor(sf::Color::White);
    }

    if(m_isRetryButtonSelected)
    {
        m_RetryButton.setFillColor(sf::Color::Yellow);
    }
    else
    {
        m_RetryButton.setFillColor(sf::Color::White);
    }

    if(m_isRetryButtonPressed)
    {
        m_context->m_states->AddNewState(std::make_unique<Gameover>(m_context), true);
    }

    if(m_isExitButtonPressed)
    {
        m_context->m_window->close();
    }
}

void Gameover::ProcessInput()
{
    sf::Event event;

    while(m_context->m_window->pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            m_context->m_window->close();
        }
        else if(event.type == sf::Event::KeyPressed)
        {
            switch(event.key.code)
            {
                case(sf::Keyboard::Up):
                {
                    if(m_isExitButtonSelected)
                    {
                        m_isExitButtonSelected = false;
                        m_isRetryButtonSelected = true;
                    }
                    else if(m_isRetryButtonSelected)
                    {
                        m_isExitButtonSelected = true;
                        m_isRetryButtonSelected = false;
                    }
                }
                break;

                case(sf::Keyboard::Down):
                {
                    if(m_isExitButtonSelected)
                    {
                        m_isExitButtonSelected = false;
                        m_isRetryButtonSelected = true;
                    }
                    else if(m_isRetryButtonSelected)
                    {
                        m_isExitButtonSelected = true;
                        m_isRetryButtonSelected = false;
                    }
                }
                break;

                case(sf::Keyboard::Enter):
                {
                    if(m_isExitButtonSelected)
                    {
                        m_isExitButtonPressed = true;
                    }
                    else if(m_isRetryButtonSelected)
                    {
                        m_isRetryButtonPressed = true;
                    }
                }
                break;

                default:
                    break;
            }
        }
    }
}

void Gameover::Draw()
{
    m_context->m_window->clear();
    m_context->m_window->draw(m_gameOverTitle);
    m_context->m_window->draw(m_RetryButton);
    m_context->m_window->draw(m_ExitButton);
    m_context->m_window->display();
}
