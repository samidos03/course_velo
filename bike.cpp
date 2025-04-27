#include "bike.h"
#include "utils.h"

Bike::Bike(SDL_Renderer* rend) : renderer(rend), velocityY(0) {
    texture = loadTexture("images/bike.png", renderer);

    rect.x = 100;
    rect.y = 400;
    rect.w = 64;
    rect.h = 64;
}

Bike::~Bike() {
    SDL_DestroyTexture(texture);
}

void Bike::handleEvent(SDL_Event& event) {
    if (event.type == SDL_KEYDOWN) {
        if (event.key.keysym.sym == SDLK_SPACE) {
            velocityY = -12;
        }
    }
}

void Bike::update() {
    rect.y += velocityY;
    velocityY += 1; // Gravité

    if (rect.y > 400) {
        rect.y = 400;
        velocityY = 0;
    }
}

void Bike::render() {
    SDL_RenderCopy(renderer, texture, NULL, &rect);
}

SDL_Rect Bike::getRect() const {
    return rect;
}
