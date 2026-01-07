#include "battle_state.h"
#include "state_manager.h"
#include "raylib.h"

BattleState::BattleState(StateManager& manager) : manager(manager) {

}


void BattleState::update() {

}

void BattleState::draw() {
    DrawText("Welcome to Battle Screen", 200, 200, 20, GRAY);
}