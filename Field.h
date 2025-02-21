#pragma once

class Field{

    unsigned width, height;

    char** cells = nullptr;

public:
    Field(unsigned w, unsigned h);

    ~Field();

    void placeFood(unsigned x, unsigned y);

    void print();
};