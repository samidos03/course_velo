#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


class Wall {
public:
    Wall(SDL_Renderer* renderer);
    ~Wall();

    void update();
    void render();
    SDL_Rect getRect() const;

private:
    SDL_Renderer* renderer;
    SDL_Texture* texture;
    SDL_Rect rect;
};
