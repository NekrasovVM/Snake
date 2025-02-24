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

    std::deque<unsigned> xTail;
    std::deque<unsigned> yTail;

public:
    Snake(unsigned maxTailLen, unsigned xHead, unsigned yHead);

    ~Snake();


    unsigned getxHead(){return xHead;}
    unsigned getyHead(){return yHead;}

    void setState(State st){state = st;}
    State getState() {return state;}


    // bool isTail(unsigned x, unsigned y);

    pair<unsigned, unsigned> move();

    pair<unsigned, unsigned> cut();
};