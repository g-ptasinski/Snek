#include "../include/gameplay.h"

Gameplay::Gameplay(std::shared_ptr<Context> &context)
    : m_context(context)
{
}

Gameplay::~Gameplay()
{
}

void Gameplay::Init()
{
    m_context->m_assets->AddTexture(SNAKE, "../assets/textures/snake.png");
    m_context->m_assets->AddTexture(WALL, "../assets/textures/wall.png", true);
    m_context->m_assets->AddTexture(GRASS, "../assets/textures/grass.png", true);
    m_context->m_assets->AddTexture(FOOD, "../assets/textures/food.png");

    m_grass.setTexture(m_context->m_assets->GetTexture(GRASS));
    m_grass.setTextureRect(m_context->m_window->getViewport(m_context->m_window->getDefaultView()));

    m_food.setTexture(m_context->m_assets->GetTexture(FOOD));
    m_food.setPosition(m_context->m_window->getSize().x/2,m_context->m_window->getSize().y/2);

    for (auto& wall : m_walls)
    {
        wall.setTexture(m_context->m_assets->GetTexture(WALL));
    }

    int WallWidth = 16;

    m_walls[0].setTextureRect({0,0,     m_context->m_window->getSize().x,WallWidth});
    m_walls[1].setTextureRect({0,0,     WallWidth,m_context->m_window->getSize().y});
    m_walls[2].setTextureRect({0,0,     m_context->m_window->getSize().x,WallWidth});
    m_walls[3].setTextureRect({0,0,     WallWidth,m_context->m_window->getSize().y});

    m_walls[2].setPosition(0, static_cast<float>(m_context->m_window->getSize().y - WallWidth));
    m_walls[3].setPosition(static_cast<float>(m_context->m_window->getSize().x - WallWidth), 0);
}

void Gameplay::Update(sf::Time deltaTime)
{

}


void Gameplay::ProcessInput()
{
    sf::Event event;

    while(m_context->m_window->pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            m_context->m_window->close();
        }
    }
}

void Gameplay::Draw()
{
    m_context->m_window->clear();

    m_context->m_window->draw(m_grass);

    for (auto& wall : m_walls)
    {
        m_context->m_window->draw(wall);
    }

    m_context->m_window->draw(m_food);
    m_context->m_window->display();
}

void Gameplay::Pause()
{
}

void Gameplay::Start()
{
}
