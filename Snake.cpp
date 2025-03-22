#include "Snake.h"
#include <utility>

Snake::Snake(unsigned xHead, unsigned yHead) : xHead{xHead}, yHead{yHead} {
  // this->xHead = xHead;
  // this->yHead = yHead;
}

void Snake::setState(State st) {
  // snake cannot be turned in the opposite direction
  if ((state == UP && st == DOWN) || (state == DOWN && st == UP) ||
      (state == LEFT && st == RIGHT) || (state == RIGHT && st == LEFT)) {
    return;
  } else {
    state = st;
  }
}

std::pair<unsigned, unsigned> Snake::move() {

  xTail.push_front(xHead);
  yTail.push_front(yHead);

  // return old coordinates of head to mark this coordinates as tail on field
  std::pair<unsigned, unsigned> res{xHead, yHead};

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

std::pair<unsigned, unsigned> Snake::cut() {

  std::pair<unsigned, unsigned> res;

  if (state != STOP) {
    res.first = xTail.back();
    xTail.pop_back();
    res.second = yTail.back();
    yTail.pop_back();
  }

  return res;
}
