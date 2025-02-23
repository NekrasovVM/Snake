#include "Game.h"
#include "Snake.h"

#include "unistd.h"
#include "termios.h"
#include <cstdio>
#include <sys/ioctl.h>
#include "conio.h"

#include <cstdlib>

Game::Game(unsigned width, unsigned height){
        this->width = width;
        this->height = height;

        // Creation field
        // field = new Field(width, height);

        // Creating snake with max tail length = size of field in center position
        snake = new Snake(width * height - 1, width / 2, height / 2);

        // Set food coordinates
        placeFood();

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
    snake->move();

    // if food
    if(snake->getxHead() != xFood || snake->getyHead() != yFood) { 
        snake->cut();
    }
    else{
        cout << "food";
        score++;
        placeFood();
    }

    // if wall
    if(snake->getxHead() < 0 || snake->getxHead() == width || snake->getyHead() < 0 || snake->getyHead() == height ||
        // or tail
        snake->isTail(snake->getxHead(), snake->getyHead())) {
            isGameOver = true; 
        }

    return;
}

void Game::selectDifficulty(){
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

// bool _kbhit()
// {
//     termios term;
//     tcgetattr(0, &term);

//     unsigned char ch;

//     int nread;
//     // ioctl(0, FIONREAD, &byteswaiting);
//     term.c_cc[VMIN]=0;
//     tcsetattr(0, TCSANOW, &term);

//     cout << "here";
//     // nread = read(0, &ch, 1);

//     term.c_cc[VMIN]=1;
//     tcsetattr(0, TCSANOW, &term);

//     cout << nread;

//     return nread > 0;
// }

int kbhit()
{
    struct termios oldt, newt;
    int ch;
    int oldf;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);
    if (ch != EOF)
    {
        ungetc(ch, stdin);
        return 1;
    }
    return 0;
}

void Game::input(){
    if (kbhit()){
        switch (getchar()) {
            case 'w':
                snake->setState(Snake::UP);
                break;
            case 'a':
                snake->setState(Snake::LEFT);
                break;
            case 's':
                snake->setState(Snake::DOWN);
                break;
            case 'd':
                snake->setState(Snake::RIGHT);
                break;
            default:
                break;
        }
    }
}

// void setNoncanonMode(){
//     termios term;
//     tcgetattr(0, &term);
//     term.c_cflag &= ~(ICANON | ECHO | ISIG);
//     term.c_cc[VMIN] = 1;
//     term.c_cc[VTIME] = 0;
//     tcsetattr(0, TCSANOW, &term);
// }

// void setCanonMode(){
//     termios term;
//     tcgetattr(0, &term);
//     term.c_cflag |= ICANON | ECHO;
//     tcsetattr(0, TCSANOW, &term);
// }

void Game::start(){
    cout << "Enter your name: ";
    cin >> playerName;

    selectDifficulty();

    // setCanonMode();
    // cout << "canon mode";

    while(!isGameOver){
        render();
        usleep(pauseMcs);
        input();
        update();
    }

    render();
    usleep(pauseMcs);

    // setNoncanonMode();

    return;
}

void Game::placeFood(){
    do{
        xFood = rand() % width;
        yFood = rand() % height;
    } while(xFood != snake->getxHead() && yFood != snake->getyHead() && !(snake->isTail(xFood, yFood)));
}

