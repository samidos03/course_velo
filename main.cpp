#include "game.h"

int main(int argc, char* argv[]) {
    Game game;
    if (game.init("Bike Game", 800, 600)) {
        game.run();
    }
    game.clean();

    return 0;
}
