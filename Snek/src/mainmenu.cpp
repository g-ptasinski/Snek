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
    m_gameTitle.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_gameTitle.setString("Snek");
}


void MainMenu::Update(sf::Time deltaTime)
{
}

void MainMenu::ProcessInput()
{
    sf::Event event;

    while(m_context->m_window->pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        m_context->m_window->close();
    }
}

void MainMenu::Draw()
{
    m_context->m_window->clear();
    m_context->m_window->draw(m_gameTitle);
    m_context->m_window->display();
}
