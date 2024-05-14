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
}

void Gameplay::Update(sf::Time deltaTime)
{

}


void Gameplay::ProcessInput()
{
}

void Gameplay::Draw()
{
    m_context->m_window->clear();
    m_context->m_window->draw(m_grass);
    m_context->m_window->display();
}

void Gameplay::Pause()
{
}

void Gameplay::Start()
{
}
