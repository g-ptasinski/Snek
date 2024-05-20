#pragma once

#include <memory>
#include <array>

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "state.h"
#include "game.h"
#include "snake.h"
#include "gameover.h"

#include <stdlib.h>
#include <time.h>
#include <cmath>

#ifndef GAMEPLAY_H
#define GAMEPLAY_H

class Gameplay : public Engine::State
{
private:

    std::shared_ptr<Context> m_context;
    sf::Sprite m_grass;
    sf::Sprite m_food;
    Snake m_snake;
    std::array<sf::Sprite, 4> m_walls;

    sf::Vector2f m_snakeDirection;
    sf::Time m_ElapsedTime;
    

public:

    Gameplay(std::shared_ptr<Context> &m_context);
    ~Gameplay();

    void Init() override;
    void Update(sf::Time deltaTime) override;

    void ProcessInput() override;
    void Draw() override;
    void Pause() override;
    void Start() override;

};

#endif // MAINMENU_H
