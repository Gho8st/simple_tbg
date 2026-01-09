#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#include <memory>
#include "state.h"

class StateManager {
    public:
        void change_state(std::unique_ptr<State> state);
        void update();
        void draw();

        bool has_state();

    private:
        std::unique_ptr<State> currentState;
};

#endif