#include "Game.h"
#include "Snake.h"

#include "termios.h"

#include <cstdlib>
Game::Game(unsigned width, unsigned height){
        this->width = width;
        this->height = height;

        // Creation field
        // field = new Field(width, height);

        // Creating snake with max tail length = size of field in center position
        snake = new Snake(width * height - 1, width / 2, height / 2);

        // Set food coordinates
        do{
            xFood = rand() % width;
            yFood = rand() % height;
        } while(xFood != snake->getxHead() && yFood != snake->getyHead());

        // field->placeFood(xFood, yFood);
};

void Game::render(){
    system("clear");


    // field->print();
    //top walls
    for(int i = 0; i < width + 2; i++){cout << "-";}
    cout << endl;

    //rendering cycles
    for(int j = 0; j < height; j++){
        cout << '|'; //left wall
        for(int i = 0; i < width; i++){
            if (i == snake->getxHead() && j == snake->getyHead()){
                if(isGameOver) { cout << 'X'; }
                else { cout << 'O'; }
            }
            else if (i == xFood && j == yFood) { cout << '#'; }
            else if (snake->isTail(i, j)) { cout << 'o'; }
            else{ cout << ' '; }
        }
        cout << '|' << endl; //right wall
    }

    //bot walls
    for(int i = 0; i < width + 2; i++){cout << "-";}
    cout << endl;

    //info
    cout << "Player: " << playerName << "   Score: " << score << endl;

    return;
}

void Game::update(){
    snake->move(Snake::UP);

    // if wall
    if(snake->getxHead() < 0 || snake->getxHead() > width || snake->getyHead() < 0 || snake->getyHead() > height ||
        // or tail
        snake->isTail(snake->getxHead(), snake->getyHead())) { isGameOver = true; }

    // if food
    if(snake->getxHead() != xFood || snake->getyHead() != yFood) {
         snake->cut(); 
         score++;
    }

    return;
}

void Game::chooseDifficulty(){
    int ch;
    
    do{
        cout << "Select difficulty:" << endl << "1: easy" << endl << "2: medium" << endl << "3: hard" << endl << "Your choice: ";

        cin >> ch;
    } while(ch < 1 && ch > 3);
    
    switch (ch) {
        case 1:
            pauseMcs = 330000;
        case 2:
            pauseMcs = 660000;
        case 3:
            pauseMcs = 1000000;
    }
}

bool _kbhit()
{
    termios term;
    tcgetattr(0, &term);

    termios term2 = term;
    //choose not canon 
    term2.c_cflag &= ~ICANON;

    tcsetattr(0, TCSANOW, &term2);

}

void Game::input(){
    if (_kbhit())
}

