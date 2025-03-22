#pragma once

#include <deque>
#include <ratio>
#include <utility>

class Snake {

public:
  enum State { STOP = 0, LEFT, RIGHT, UP, DOWN };

private:
  // coordinates of snake's head
  int xHead, yHead;

  State state{State::STOP};

  // coordinates of snake segments
  std::deque<unsigned> xTail;
  std::deque<unsigned> yTail;

public:
  Snake(unsigned xHead, unsigned yHead);

  int getxHead() { return xHead; }
  int getyHead() { return yHead; }

  unsigned getTailLen() { return xTail.size(); }

  void setState(State st);
  State getState() { return state; }

  // move snake in the direction and update head and tail
  std::pair<unsigned, unsigned> move();

  // delete the oldest segment of snake tail
  std::pair<unsigned, unsigned> cut();
};
