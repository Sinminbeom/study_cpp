#include <iostream>
#include "game/game.h"

int main() {

    srand((unsigned int)time(nullptr));

    Game game;
    game.Init();

    while(true) {
        game.Update();
    }

    return 0;

}