#pragma once

#include <memory>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "state.h"
#include "game.h"

#ifndef GAMEOVER_H
#define GAMEOVER_H

class Gameover : public Engine::State
{
public:

    Gameover(std::shared_ptr<Context> &context);
    ~Gameover();

    void Init() override;
    void Update(sf::Time deltaTime) override;

    void ProcessInput() override;
    void Draw() override;

    private:
    std::shared_ptr<Context> m_context;
    sf::Text m_gameOverTitle;
    sf::Text m_RetryButton;
    sf::Text m_ExitButton;

    bool m_isRetryButtonSelected;
    bool m_isRetryButtonPressed;

    bool m_isExitButtonSelected;
    bool m_isExitButtonPressed;

};

#endif // GAMEOVER_H
