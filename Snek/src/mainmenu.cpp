#include "../include/mainmenu.h"
#include <SFML/Window/Event.hpp>

MainMenu::MainMenu(std::shared_ptr<Context> &context)
    : m_context(context)
{
}

MainMenu::~MainMenu()
{

}

void MainMenu::Init()
{
    m_context->m_assets->AddFont(MAIN_FONT, "../assets/fonts/PixelifySans-VariableFont_wght.ttf");

    //Game Title
    m_gameTitle.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_gameTitle.setCharacterSize(50);
    m_gameTitle.setString("SNEK");

    m_gameTitle.setOrigin(m_gameTitle.getLocalBounds().width / 2,
                          m_gameTitle.getLocalBounds().height / 2);
    m_gameTitle.setPosition(m_context->m_window->getSize().x / 2,
                            m_context->m_window->getSize().y / 4);

    //Play Button
    m_PlayButton.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_PlayButton.setString("Play");
    m_PlayButton.setOrigin(m_PlayButton.getLocalBounds().width / 2,
                          m_PlayButton.getLocalBounds().height / 2);
    m_PlayButton.setPosition(m_context->m_window->getSize().x / 2,
                            m_context->m_window->getSize().y / 2 );

    //Exit Button
    m_ExitButton.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_ExitButton.setString("Exit");
    m_ExitButton.setOrigin(m_ExitButton.getLocalBounds().width / 2,
                          m_ExitButton.getLocalBounds().height / 2);
    m_ExitButton.setPosition(m_context->m_window->getSize().x / 2,
                            m_context->m_window->getSize().y / 2 + 40.f);

    m_isPlayButtonSelected = true;
    m_isExitButtonSelected = false;

    m_isPlayButtonPressed = false;
    m_isExitButtonPressed = false;

}


void MainMenu::Update(sf::Time deltaTime)
{
    if(m_isExitButtonSelected)
    {
        m_ExitButton.setFillColor(sf::Color::Yellow);
    }
    else
    {
        m_ExitButton.setFillColor(sf::Color::White);
    }

    if(m_isPlayButtonSelected)
    {
        m_PlayButton.setFillColor(sf::Color::Yellow);
    }
    else
    {
        m_PlayButton.setFillColor(sf::Color::White);
    }

    if(m_isPlayButtonPressed)
    {
        //Go to play state
    }

    if(m_isExitButtonPressed)
    {
        m_context->m_window->close();
    }
}

void MainMenu::ProcessInput()
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
                        m_isPlayButtonSelected = true;
                    }
                    else if(m_isPlayButtonSelected)
                    {
                        m_isExitButtonSelected = true;
                        m_isPlayButtonSelected = false;
                    }
                }
                break;

                case(sf::Keyboard::Down):
                {
                    if(m_isExitButtonSelected)
                    {
                        m_isExitButtonSelected = false;
                        m_isPlayButtonSelected = true;
                    }
                    else if(m_isPlayButtonSelected)
                    {
                        m_isExitButtonSelected = true;
                        m_isPlayButtonSelected = false;
                    }
                }
                break;

                case(sf::Keyboard::Enter):
                {
                    if(m_isExitButtonSelected)
                    {
                        m_isExitButtonPressed = true;
                    }
                    else if(m_isPlayButtonSelected)
                    {
                        m_isPlayButtonPressed = true;
                    }
                }
                break;

                default:
                    break;
            }
        }
    }
}

void MainMenu::Draw()
{
    m_context->m_window->clear();
    m_context->m_window->draw(m_gameTitle);
    m_context->m_window->draw(m_PlayButton);
    m_context->m_window->draw(m_ExitButton);
    m_context->m_window->display();
}
