#include "menu_state.h"
#include "state_manager.h"
#include "raylib.h"

MenuState::MenuState(StateManager& manager) : manager(manager) {

}


void MenuState::update() {

}

void MenuState::draw() {
    DrawText("Welcome to Simple TBG", 200, 200, 20, GRAY);
}