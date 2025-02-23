#include "Field.h"

#include <iostream>
using namespace std;

Field::Field(unsigned w, unsigned h){

    cout << "OK";

    width = w + 2;
    height = h + 2;

    cells = new char*[width];

    for(int i = 0; i < width; i++){
        cells[i] = new char[height];
    }

    cout << "OK";
}

Field::~Field(){
    for(int i = 0; i < width; i++){
        delete [] cells[i];
    }

    delete [] cells;
}

void Field::renderFood(unsigned x, unsigned y){
    cells[x][y] = '#';
}

void Field::print(){
    for(int i = 0; i < width; i++) {
        for(int j = 0; j < height; j++){ 
            cout << cells[i][j];
        }
    }
}
