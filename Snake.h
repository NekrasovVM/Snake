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

    State state {State::STOP};

    // coordinates of snake segments
    std::deque<unsigned> xTail;
    std::deque<unsigned> yTail;

public:
    Snake(unsigned maxTailLen, unsigned xHead, unsigned yHead);

    ~Snake();

    int getxHead(){return xHead;}
    int getyHead(){return yHead;}

    unsigned getTailLen(){return xTail.size();}

    void setState(State st){state = st;}
    State getState() {return state;}

    // move snake in the direction and update head and tail
    pair<unsigned, unsigned> move();

    // delete the oldest segment of snake tail
    pair<unsigned, unsigned> cut();
};
