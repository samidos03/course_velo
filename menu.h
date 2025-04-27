#pragma once
#include <SDL2/SDL.h>

class Menu {
public:
    Menu();
    ~Menu();

    bool show();

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};
