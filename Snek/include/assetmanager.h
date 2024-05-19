#pragma once

#include <map>
#include <memory>
#include <string>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>


#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

namespace Engine
{
    class AssetManager
    {

    private:

        std::map<int, std::unique_ptr<sf::Texture>> m_texture;
        std::map<int, std::unique_ptr<sf::Font>> m_fonts;

    public:

        AssetManager();
        ~AssetManager();

        void AddTexture(int id, const std::string &filePath, bool wantRepeated = false);
        void AddFont(int id, const std::string &filePath);

        const sf::Texture &GetTexture(int id) const;
        const sf::Font &GetFont(int id) const;

    };
}
#endif // ASSETMANAGER_H
