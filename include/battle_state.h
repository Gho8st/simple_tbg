#ifndef BATTLE_STATE_H
#define BATTLE_STATE_H

#include "state.h"

class StateManager;

class BattleState : public State {
    private:
        StateManager& manager;
    public:
        BattleState(StateManager& manager);
        void update() override;
        void draw() override;
};

#endif