#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


class Timer {
public:
    Timer(SDL_Renderer* renderer);
    ~Timer();

    void render();

private:
    SDL_Renderer* renderer;
    Uint32 startTime;
};
