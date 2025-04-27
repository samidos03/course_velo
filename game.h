#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>   // ✅ نحتافظ بها لأننا نحتاج صور

#include "bike.h"
#include "wall.h"
#include "timer.h"

class Game {
public:
    Game();
    ~Game();

    bool init(const char* title, int width, int height);
    void run();
    void clean();

private:
    void handleEvents();
    void update();
    void render();

    SDL_Window* window;
    SDL_Renderer* renderer;
    bool isRunning;

    Bike* bike;
    Wall* wall;
    Timer* timer;
};
