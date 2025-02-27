#pragma once

#include "Snake.h"
#include "Field.h"

#include "iostream"
using namespace std;

class Game{

    bool isGameOver = false;

    unsigned width, height;

    unsigned xFood, yFood;

    unsigned score {};

    unsigned pauseMcs;

    string playerName {"Noname"};

    Snake* snake;

    Field* field;

public:
    Game(unsigned width, unsigned height);

    ~Game();

    void render();

    void update();

    void selectDifficulty();

    void input();

    void start();

    void placeFood();
};
