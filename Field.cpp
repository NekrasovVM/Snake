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

void Field::setHead(pair<unsigned, unsigned> coord){
    cells[coord.first][coord.second] = 'O';
}

void Field::setCell(pair<int, int> coord){
    if(coord.first < 0 || coord.second < 0) { return; }
    cells[coord.first][coord.second] = 'o';
}

void Field::resetCell(pair<int, int> coord){
    if(coord.first < 0 || coord.second < 0) { return; }
    cells[coord.first][coord.second] = '1';
}

bool Field::isTail(int x, int y){
    if( x < 0 || y < 0 ) { return false; }
    if(cells[x][y] == 'o'){ return true; }
    else{ return false; }
}

pair<unsigned, unsigned> Field::getFreeCell(unsigned id){
    unsigned i{}, j{};
    unsigned counter{};

    for(i = 0; i < width; i++){
        for(j = 0; j < height; j++){
            if(cells[i][j] == '1'){
                if(counter == id) {return pair<unsigned, unsigned> {i, j};}
                else {counter++;}
            }
        }
    }

    throw "Incorrect id!";
    
    return pair<unsigned, unsigned> {0, 0};
}
