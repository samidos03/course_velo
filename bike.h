#pragma once
#include <SDL2/SDL.h>


class Bike {
public:
    Bike(SDL_Renderer* renderer);
    ~Bike();

    void handleEvent(SDL_Event& event);
    void update();
    void render();
    SDL_Rect getRect() const;

private:
    SDL_Renderer* renderer;
    SDL_Texture* texture;
    SDL_Rect rect;
    int velocityY;
};
