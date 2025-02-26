#include "Field.h"

#include <utility>


Field::Field(unsigned w, unsigned h){

    width = w;
    height = h;

    cells = new char*[width];

    for(int i = 0; i < width; i++){
        cells[i] = new char[height];
        for(int j = 0; j < height; j++){
            cells[i][j] = '1';
        }
    }

}

Field::~Field(){
    for(int i = 0; i < width; i++){
        delete [] cells[i];
    }

    delete [] cells;
}

void Field::setCell(pair<unsigned, unsigned> coord){
    cells[coord.first][coord.second] = 'o';
}

void Field::resetCell(pair<unsigned, unsigned> coord){
    cells[coord.first][coord.second] = '1';
}

bool Field::isTail(unsigned x, unsigned y){
    if(cells[x][y] == 'o'){ return true; }
    else{ return false; }
}
