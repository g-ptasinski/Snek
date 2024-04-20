#pragma once

#include <memory>
#include <SFML/Graphics/Text.hpp>

#include "state.h"
#include "game.h"

#ifndef MAINMENU_H
#define MAINMENU_H

class MainMenu : public Engine::State
{
private:
    std::shared_ptr<Context> m_context;
    sf::Text m_gameTitle;

public:

    MainMenu(std::shared_ptr<Context> &m_context);
    ~MainMenu();

    void Init() override;
    void Update(sf::Time deltaTime) override;

    void ProcessInput() override;
    void Draw() override;


};

#endif // MAINMENU_H
