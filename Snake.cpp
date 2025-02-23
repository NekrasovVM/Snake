#include "Snake.h"

using namespace std;

Snake::Snake(unsigned maxTailLen, unsigned xHead, unsigned yHead){
        this->xHead = xHead;
        this->yHead = yHead;
}

Snake::~Snake(){}

bool Snake::isTail(unsigned x, unsigned y){

    if (xTail.empty()) {
        return false;
    }
    else{
        for(int i = 0; i < xTail.size(); i++){
            if(xTail[i] == x && yTail[i] == y){ 
                return true; 
            }
        }
    }

    return false;
}

void Snake::move(){

    switch (state) {
        case LEFT:
            xTail.push_front(xHead);
            yTail.push_front(yHead);
            xHead--;
            break;
        case RIGHT:
            xTail.push_front(xHead);
            yTail.push_front(yHead);
            xHead++;
            break;
        case UP:
            xTail.push_front(xHead);
            yTail.push_front(yHead);
            yHead--;
            break;
        case DOWN:
            xTail.push_front(xHead);
            yTail.push_front(yHead);
            yHead++;
            break;
        default:
            break;
    }
}

void Snake::cut(){

    if(state != STOP){
        xTail.pop_back();
        yTail.pop_back();
    }

    return;
}