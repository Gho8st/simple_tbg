#ifndef BATTLE_STATE_H
#define BATTLE_STATE_H

#include "state.h"
#include "entity.h"

class StateManager;

enum Outcome {
    Player,
    Enemy,
    None
};

class BattleState : public State {
    private:
        StateManager& manager;
        
        Entity player;
        Entity enemy;
        bool ifPlayerTurn = true;
        bool debug;

        Outcome outcome = Outcome::None;
    public:
        BattleState(StateManager& manager, bool debug);
        void update() override;
        void draw() override;
};

#endif