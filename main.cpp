#include "Game.h"

#include "unistd.h"

int main(int argc, char** argv){
    srand ( time(NULL) );
    Game game{20, 20};
    game.chooseDifficulty();
    game.render();
    game.update();
    sleep(1);
    game.render();
    return 0;
}