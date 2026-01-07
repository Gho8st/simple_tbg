#ifndef MENU_STATE_H
#define MENU_STATE_H

#include "state.h"

class StateManager;

class MenuState : public State {
    private:
        StateManager& manager;
        bool debug;
    public:
        MenuState(StateManager& manager, bool debug);
        void update() override;
        void draw() override;
};

#endif