#pragma once

#include "Field.h"
#include "Snake.h"

#include <iostream>
#include <random>

class Game {

  bool isGameOver = false;

  unsigned width, height;

  // unsigned xFood, yFood;
  std::pair<unsigned, unsigned> food;

  unsigned score{};

  unsigned pauseMcs;

  std::string playerName{"Noname"};

  Snake snake;

  Field field;

  std::mt19937 engine;

public:
  Game(unsigned width, unsigned height);

  // render the field to console
  void render();

  // move snake in the direction and update game objects
  void update();

  // let user to select game difficulty
  void selectDifficulty();

  // get user input to control the snake
  void input();

  // initiate game
  void start();

  // generate new food on the free cell
  void placeFood();
};
