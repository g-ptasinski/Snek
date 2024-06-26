#pragma once

#include <list>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/System/Time.hpp>


    class Snake : public sf::Drawable
    {
    private:
        std::list<sf::Sprite> m_body;
        std::list<sf::Sprite>::iterator m_head;
        std::list<sf::Sprite>::iterator m_tail;
        ;

    public:
        Snake();
        virtual ~Snake();

        void Init(const sf::Texture& direction);
        void Move(const sf::Vector2f& direction);
        bool IsOn(const sf::Sprite& other) const;
        void Grow(const sf::Vector2f& direction);

        std::list<sf::Sprite> GetBody();
        std::list<sf::Sprite>::iterator GetHead();

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    };
#endif // STATE_H
