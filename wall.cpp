#include "wall.h"
#include "utils.h"

Wall::Wall(SDL_Renderer* rend) : renderer(rend) {
    texture = loadTexture("images/wall.png", renderer);

    rect.x = 800;
    rect.y = 400;
    rect.w = 50;
    rect.h = 100;
}

Wall::~Wall() {
    SDL_DestroyTexture(texture);
}

void Wall::update() {
    rect.x -= 5;
    if (rect.x + rect.w < 0) {
        rect.x = 800;
    }
}

void Wall::render() {
    SDL_RenderCopy(renderer, texture, NULL, &rect);
}

SDL_Rect Wall::getRect() const {
    return rect;
}
