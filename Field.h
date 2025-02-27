#pragma once

#include <utility>
using namespace std;

// class of game field
class Field{

    // width and height of field without walls
    unsigned width, height;

    // storage to check is snake tail on cell or not (o - contain tail, 1 - not contain)
    // char because it takes one byte as bool, but more multifunctional
    char** cells {nullptr};

public:
    Field(unsigned w, unsigned h);

    ~Field();

    // mark cell as containing tail segment
    void setCell(pair<unsigned, unsigned> coord);

    // mark cell as notcontaining tail segment
    void resetCell(pair<unsigned, unsigned> coord);

    // check if cell contain tail segment
    bool isTail(unsigned x, unsigned y);
};
