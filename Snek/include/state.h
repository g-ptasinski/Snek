#pragma once

#ifndef STATE_H
#define STATE_H

#include <SFML/System/Time.hpp>


namespace Engine
{
    class State
    {
    private:


    public:
        State();
        virtual ~State();

        virtual void Init()                     = 0;
        virtual void Update(sf::Time deltaTime) = 0;
        virtual void ProcessInput()             = 0;
        virtual void Draw()                     = 0;

        virtual void Pause(){};
        virtual void Start(){};

    };
}
#endif // STATE_H
