#include "utils.h"
#include <iostream>

SDL_Texture* loadTexture(const char* path, SDL_Renderer* renderer) {
    SDL_Surface* surface = IMG_Load(path);

    if (!surface) {
        std::cout << "Erreur chargement image : " << SDL_GetError() << std::endl;
        return nullptr;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

bool checkCollision(SDL_Rect a, SDL_Rect b) {
    return SDL_HasIntersection(&a, &b);
}

