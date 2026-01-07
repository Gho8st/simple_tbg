#ifndef BATTLE_STATE_H
#define BATTLE_STATE_H

#include "state.h"
#include "entity.h"

class StateManager;

class BattleState : public State {
    private:
        StateManager& manager;
        
        Entity player;
        Entity enemy;
        bool ifPlayerTurn = true;

    public:
        BattleState(StateManager& manager);
        void update() override;
        void draw() override;
};

#endif