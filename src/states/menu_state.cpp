#include "menu_state.h"
#include "battle_state.h"
#include "state_manager.h"
#include "raylib.h"

MenuState::MenuState(StateManager& manager, bool debug) : manager(manager) {
    this->debug = debug;
}


void MenuState::update() {
    if (IsKeyPressed(KEY_ENTER)) {
        manager.change_state(std::make_unique<BattleState>(manager, debug));
    }
}

void MenuState::draw() {
    DrawText("Welcome to Simple TBG", 200, 200, 20, GRAY);
    DrawText("Press Enter to go to Battle Screen", 200, 300, 20, GRAY);
}