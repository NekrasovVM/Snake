#include "Game.h"

int main(int argc, char **argv) {
  srand(time(NULL));
  Game game{20, 20};
  game.start();
  return 0;
}
