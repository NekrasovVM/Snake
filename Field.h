#pragma once

#include <utility>
using namespace std;

class Field{

    unsigned width, height;

    char** cells = nullptr;

public:
    Field(unsigned w, unsigned h);

    ~Field();

    void setCell(pair<unsigned, unsigned> coord);

    void resetCell(pair<unsigned, unsigned> coord);

    bool isTail(unsigned x, unsigned y);
};