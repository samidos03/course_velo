#include "game.h"
#include "utils.h"
#include <iostream>

Game::Game() : window(nullptr), renderer(nullptr), isRunning(false), bike(nullptr), wall(nullptr), timer(nullptr) {}

Game::~Game() {}

bool Game::init(const char* title, int width, int height) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    if (!window) return false;

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) return false;

    bike = new Bike(renderer);
    wall = new Wall(renderer);
    timer = new Timer(renderer);

    isRunning = true;
    return true;
}

void Game::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT)
            isRunning = false;
        bike->handleEvent(event);
    }
}

void Game::update() {
    bike->update();
    wall->update();

    if (checkCollision(bike->getRect(), wall->getRect())) {
        std::cout << "Collision détectée ! Game Over.\n";
        isRunning = false;
    }
}

void Game::render() {
    SDL_SetRenderDrawColor(renderer, 100, 149, 237, 255);
    SDL_RenderClear(renderer);

    bike->render();
    wall->render();
    timer->render();

    SDL_RenderPresent(renderer);
}

void Game::run() {
    while (isRunning) {
        handleEvents();
        update();
        render();
        SDL_Delay(16);
    }
}

void Game::clean() {
    delete bike;
    delete wall;
    delete timer;

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();   // فقط SDL_Quit بدون TTF_Quit
}
