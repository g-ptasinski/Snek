#include "../include/gameplay.h"
#include "../include/gameover.h"

Gameplay::Gameplay(std::shared_ptr<Context> &context)
    : m_context(context), m_snakeDirection({16.f, 0.f}), m_ElapsedTime(sf::Time::Zero)
{
    srand(time(nullptr));
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
    int Window_Width = m_context->m_window->getSize().x;
    int Window_Height = m_context->m_window->getSize().y;


    m_walls[0].setTextureRect({0,0,     Window_Width,WallWidth});
    m_walls[1].setTextureRect({0,0,     WallWidth,Window_Height });
    m_walls[2].setTextureRect({0,0,     Window_Width,WallWidth});
    m_walls[3].setTextureRect({0,0,     WallWidth,Window_Height });

    m_walls[2].setPosition(0, static_cast<float>(m_context->m_window->getSize().y - WallWidth));
    m_walls[3].setPosition(static_cast<float>(m_context->m_window->getSize().x - WallWidth), 0);

    m_snake.Init(m_context->m_assets->GetTexture(SNAKE));

}

void Gameplay::Update(sf::Time deltaTime)
{
    m_ElapsedTime += deltaTime;

    if (m_ElapsedTime.asSeconds() >= 0.05)
    {
        for(auto &wall : m_walls)
        {
            if(m_snake.IsOn(wall))
            {
                m_context->m_states->AddNewState(std::make_unique<Gameover>(m_context), true);
                break;
            }
        }

        if(m_snake.IsOn(m_food))
        {
            m_snake.Grow(m_snakeDirection);
            int x=0;
            int y=0;

            x = std::clamp<int>(16*rand() % m_context->m_window->getSize().x, 16, m_context->m_window->getSize().x -2*16);
            y = std::clamp<int>(16*rand() % m_context->m_window->getSize().y, 16, m_context->m_window->getSize().y -2*16);

            m_food.setPosition(x,y);
        }
        else
        {
            m_snake.Move(m_snakeDirection);
        }
        m_ElapsedTime = sf::Time::Zero;
    }
    
}


void Gameplay::ProcessInput()
{
    sf::Event event;
    sf::Vector2f newDirection;

    while(m_context->m_window->pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            m_context->m_window->close();
        }
        else if (event.type == sf::Event::KeyPressed)
        {
            switch (event.key.code)
            {
            case sf::Keyboard::Up:
                newDirection = { 0.f, -16.f };
                break;
            case sf::Keyboard::Down:
                newDirection = { 0.f, 16.f };
                break;
            case sf::Keyboard::Left:
                newDirection = { -16.f, 0.f };
                break;
            case sf::Keyboard::Right:
                newDirection = { 16.f, 0.f };
                break;

            default:
                break;
            }

            if (std::abs(newDirection.x) != std::abs(m_snakeDirection.x) ||
                std::abs(newDirection.y) != std::abs(m_snakeDirection.y))
            {
                m_snakeDirection = newDirection;
            }
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
    m_context->m_window->draw(m_snake);
    m_context->m_window->display();
}

void Gameplay::Pause()
{
}

void Gameplay::Start()
{
}
