#include "Field.h"

#include <utility>

Field::Field(unsigned w, unsigned h) {

  width = w;
  height = h;

  // initialization cells with '1'
  cells = std::vector<std::vector<char>>(w, std::vector<char>(h, '1'));
}

void Field::setHead(std::pair<unsigned, unsigned> coord) {
  cells[coord.first][coord.second] = 'O';
}

void Field::setCell(std::pair<int, int> coord) {
  if (coord.first < 0 || coord.second < 0) {
    return;
  }
  cells[coord.first][coord.second] = 'o';
}

void Field::resetCell(std::pair<int, int> coord) {
  if (coord.first < 0 || coord.second < 0) {
    return;
  }
  cells[coord.first][coord.second] = '1';
}

bool Field::isTail(int x, int y) {
  if (x < 0 || y < 0) {
    return false;
  }
  if (cells[x][y] == 'o') {
    return true;
  } else {
    return false;
  }
}

std::pair<unsigned, unsigned> Field::getFreeCell(unsigned id) {
  unsigned i{}, j{};
  unsigned counter{};

  for (i = 0; i < width; i++) {
    for (j = 0; j < height; j++) {
      if (cells[i][j] == '1') {
        if (counter == id) {
          return std::pair<unsigned, unsigned>{i, j};
        } else {
          counter++;
        }
      }
    }
  }

  // if there were not enough free cells on the field
  throw "Incorrect id!";

  return std::pair<unsigned, unsigned>{0, 0};
}
