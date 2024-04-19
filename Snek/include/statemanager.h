// SPDX-FileCopyrightText: 2024 <copyright holder> <email>
// SPDX-License-Identifier: BSL-1.0

#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include <stack>
#include <memory>

#include "state.h"
#include "assetmanager.h"

namespace Engine
{
    class StateManager
    {

    private:

        bool m_add;
        bool m_replace;
        bool m_remove;

        std::stack<std::unique_ptr<State>> m_stateStack;
        std::unique_ptr<State> m_newState;

    public:

        StateManager();
        ~StateManager();

        void AddNewState(std::unique_ptr<State> toAdd, bool replace = false);
        void RemoveCurrentState();
        void ProcessStateChange();

        std::unique_ptr<State> &GetCurrentState();

    };
}
#endif // STATEMANAGER_H
