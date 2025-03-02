#include "Snake.h"
#include <utility>

using namespace std;

Snake::Snake(unsigned maxTailLen, unsigned xHead, unsigned yHead){
        this->xHead = xHead;
        this->yHead = yHead;
}

Snake::~Snake(){}

pair<unsigned, unsigned> Snake::move(){

    xTail.push_front(xHead);
    yTail.push_front(yHead);

    pair<unsigned, unsigned> res {xHead, yHead};

    switch (state) {
        case LEFT:
            xHead--;
            break;
        case RIGHT:
            xHead++;
            break;
        case UP:
            yHead--;
            break;
        case DOWN:
            yHead++;
            break;
        default:
            xTail.pop_front();
            yTail.pop_front();
            break;
    }

    return res;
}

pair<unsigned, unsigned> Snake::cut(){

    pair<unsigned, unsigned> res;

    if(state != STOP){
        res.first = xTail.back();
        xTail.pop_back();
        res.second = yTail.back();
        yTail.pop_back();
    }

    return res;
}
