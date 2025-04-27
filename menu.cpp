#include "menu.h"
#include "utils.h"
#include <iostream>

Menu::Menu() : window(nullptr), renderer(nullptr) {}

Menu::~Menu() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

bool Menu::show() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow("Menu - Bike Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // نحمل صورة ديال المينو
    SDL_Texture* menuTexture = loadTexture("images/menu.bmp", renderer);
    if (!menuTexture) {
        std::cout << "Erreur chargement image menu." << std::endl;
        return false;
    }

    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) return false;
            if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_RETURN) {
                    SDL_DestroyTexture(menuTexture);
                    return true; // Commencer le jeu
                }
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    SDL_DestroyTexture(menuTexture);
                    return false; // Quitter
                }
            }
        }

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, menuTexture, NULL, NULL);
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyTexture(menuTexture);
    return true;
}
