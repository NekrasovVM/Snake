#pragma once

#include <deque>
#include <ratio>
#include <utility>

using namespace std;

class Snake{

public:
    enum State{STOP = 0, LEFT, RIGHT, UP, DOWN};

private:
    // coordinates of snake's head
    int xHead, yHead;

    State state = State::STOP;

    // coordinates of snake segments
    std::deque<unsigned> xTail;
    std::deque<unsigned> yTail;

public:
    Snake(unsigned maxTailLen, unsigned xHead, unsigned yHead);

    ~Snake();

    unsigned getxHead(){return xHead;}
    unsigned getyHead(){return yHead;}

    void setState(State st){state = st;}
    State getState() {return state;}

    pair<unsigned, unsigned> move();

    // delete the oldest segment of snake tail
    pair<unsigned, unsigned> cut();
};
