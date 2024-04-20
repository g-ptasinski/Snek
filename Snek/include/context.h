struct Context
{
    std::unique_ptr<Engine::AssetManager> m_assets;
    std::unique_ptr<Engine::StateManager> m_states;
    std::unique_ptr<sf::RenderWindow> m_window;

    Context()
    {
            m_assets = std::make_unique<Engine::AssetManager>();
            m_states = std::make_unique<Engine::StateManager>();
            m_window = std::make_unique<sf::RenderWindow>();
    }
};
