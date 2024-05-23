#pragma once

#include <memory>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "state.h"
#include "game.h"

#ifndef PAUSE_H
#define PAUSE_H

class Pause : public Engine::State
{
private:
    std::shared_ptr<Context> m_context;
    sf::Text m_gameTitle;

public:

    Pause(std::shared_ptr<Context> &m_context);
    ~Pause();

    void Init() override;
    void Update(sf::Time deltaTime) override;

    void ProcessInput() override;
    void Draw() override;


};

#endif // PAUSE_H
