#pragma once

#include <utility>
#include <vector>

// class of game field
class Field {

  // width and height of field without walls
  unsigned width, height;

  // storage to check is snake tail on cell or not (o - contain tail, O -
  // contain head, 1 - free cell)
  // char **cells{nullptr};
  std::vector<std::vector<char>> cells;

public:
  Field(unsigned w, unsigned h);

  void setHead(std::pair<unsigned, unsigned> coord);

  // mark cell as containing tail segment
  void setCell(std::pair<int, int> coord);

  // mark cell as notcontaining tail segment
  void resetCell(std::pair<int, int> coord);

  // check if cell contain tail segment
  bool isTail(int x, int y);

  // returns the coordinates of an unoccupied cell with a serial number id
  std::pair<unsigned, unsigned> getFreeCell(unsigned id);
};
