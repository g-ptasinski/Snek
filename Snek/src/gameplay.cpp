#include "../include/gameplay.h"

Gameplay::Gameplay(std::shared_ptr<Context> &context)
    : m_context(context)
{
}

Gameplay::~Gameplay
{
}

Gameplay::Init()
{
    m_context->m_assets->AddTexture(SNAKE, "../assets/textures/snake.png");
    m_context->m_assets->AddTexture(WALL, "../assets/textures/wall.png", true);
    m_context->m_assets->AddTexture(GRASS, "../assets/textures/grass.png", true);
    m_context->m_assets->AddTexture(FOOD, "../assets/textures/food.png");

    m_grass.setTexture(m_context->m_assets->GetTexture(GRASS));
}

Gameplay::Update(sf::Time deltaTime)
{

}


Gameplay::ProcessInput()
{
}

Gameplay::Draw()
{
}

Gameplay::Pause()
{
}

Gameplay::Start()
{
}
