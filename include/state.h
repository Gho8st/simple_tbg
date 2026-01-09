#ifndef STATE_H
#define STATE_H

class State {
    public:
        virtual ~State() = default;
        virtual void update() = 0;
        virtual void draw() = 0;
};

#endif