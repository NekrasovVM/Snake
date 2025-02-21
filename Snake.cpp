#include "Snake.h"

Snake::Snake(unsigned maxTailLen, unsigned xHead, unsigned yHead){
        this->xHead = xHead;
        this->yHead = yHead;
}

Snake::~Snake(){}

bool Snake::isTail(unsigned x, unsigned y){

    for(int i = 0; i < xTail.size(); i++){
        if(xTail[i] == x && yTail[i] == y){ return true; }
    }

    return false;
}

void Snake::move(Snake::State direction){
    xTail.push_front(xHead);
    yTail.push_front(yHead);

    switch (direction) {
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
            break;
    }
}

void Snake::cut(){
    xTail.pop_back();
    yTail.pop_back();
}