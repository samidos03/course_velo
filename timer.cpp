#include "timer.h"
#include "utils.h"

Timer::Timer(SDL_Renderer* rend) : renderer(rend) {
    startTime = SDL_GetTicks();
}

Timer::~Timer() {}

void Timer::render() {
    // فقط نرسم مستطيل أبيض صغير كمكان للعداد
    SDL_Rect rect = {10, 10, 100, 30};
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &rect);
}
