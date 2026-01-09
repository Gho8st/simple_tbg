#include "state_manager.h"

void StateManager::change_state(std::unique_ptr<State> state) {
    currentState = std::move(state);
}

void StateManager::draw() {
    if (has_state()) currentState->draw();
}

void StateManager::update() {
    if (has_state()) currentState->update();
}

bool StateManager::has_state() {return currentState != nullptr;}