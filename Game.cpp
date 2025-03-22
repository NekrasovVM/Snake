#include "Game.h"
#include "Snake.h"

#include "conio.h"
#include "termios.h"
#include "unistd.h"
#include <cstdio>
#include <sys/ioctl.h>

#include <cstdlib>

Game::Game(unsigned width, unsigned height)
    : field{Field(width, height)}, width{width}, height{height},
      // Creating snake with max tail length = size of field in center position
      snake{Snake(width / 2, height / 2)} {

  // Set food coordinates
  placeFood();
};

void Game::render() {
  system("clear");

  // top walls
  for (int i = 0; i < width + 2; i++) {
    std::cout << "-";
  }
  std::cout << '\n';

  // rendering cycles
  for (int j = 0; j < height; j++) {
    std::cout << '|'; // left wall
    for (int i = 0; i < width; i++) {
      if (i == snake.getxHead() && j == snake.getyHead()) {
        if (isGameOver) {
          std::cout << 'X';
        } else {
          std::cout << 'O';
        }
      }
      // else if (i == xFood && j == yFood) { std::cout << '#'; }
      else if (i == food.first && j == food.second) {
        std::cout << '#';
      } else if (field.isTail(i, j)) {
        std::cout << 'o';
      } else {
        std::cout << ' ';
      }
    }
    std::cout << "|\n"; // right wall
  }

  // bot walls
  for (int i = 0; i < width + 2; i++) {
    std::cout << "-";
  }
  std::cout << '\n';

  // info
  std::cout << "Player: " << playerName << "   Score: " << score << '\n';
}

void Game::update() {
  if (snake.getState() != Snake::STOP) {

    field.setCell(snake.move());

    // if food
    if (snake.getxHead() != food.first || snake.getyHead() != food.second) {
      field.resetCell(snake.cut());
    } else {
      score++;
      placeFood();
    }

    // if wall
    if (snake.getxHead() < 0 || snake.getxHead() == width ||
        snake.getyHead() < 0 || snake.getyHead() == height ||
        // or tail
        field.isTail(snake.getxHead(), snake.getyHead())) {
      isGameOver = true;
    }
  }
}

void Game::selectDifficulty() {
  int ch;

  do {
    std::cout
        << "Select difficulty:\n1: easy\n2: medium\n3: hard\nYour choice: ";

    std::cin >> ch;
  } while (ch < 1 && ch > 3);

  switch (ch) {
  case 1:
    pauseMcs = 330000;
    break;
  case 2:
    pauseMcs = 660000;
    break;
  case 3:
    pauseMcs = 1000000;
    break;
  }
}

int kbhit() {
  // structs for old and new parameters of terminal
  struct termios oldTerm, newTerm;
  int ch;
  int oldf;
  tcgetattr(0, &oldTerm);
  newTerm = oldTerm;

  // disable canon input and echo of terminal
  newTerm.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(0, TCSANOW, &newTerm);

  // set non-block for stdin
  oldf = fcntl(0, F_GETFL, 0);
  fcntl(0, F_SETFL, oldf | O_NONBLOCK);
  ch = getchar();
  tcsetattr(0, TCSANOW, &oldTerm);
  fcntl(0, F_SETFL, oldf);
  if (ch != EOF) {
    ungetc(ch, stdin);
    return 1;
  }
  return 0;
}

void Game::input() {
  if (kbhit()) {
    switch (getchar()) {
    case 'w':
      snake.setState(Snake::UP);
      break;
    case 'a':
      snake.setState(Snake::LEFT);
      break;
    case 's':
      snake.setState(Snake::DOWN);
      break;
    case 'd':
      snake.setState(Snake::RIGHT);
      break;
    default:
      break;
    }
  }
}

void Game::start() {
  std::cout << "Enter your name: ";
  std::cin >> playerName;

  selectDifficulty();

  while (!isGameOver) {
    render();
    usleep(pauseMcs);
    input();
    update();
  }

  render();
  std::cout << "GAME OVER\n";
  usleep(pauseMcs);
}

void Game::placeFood() {

  field.setHead(
      std::pair<unsigned, unsigned>{snake.getxHead(), snake.getyHead()});

  unsigned id = rand() % (width * height - snake.getTailLen());

  food = field.getFreeCell(id);
}
