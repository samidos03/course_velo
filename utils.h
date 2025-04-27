#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

// تحميل صورة وتحويلها إلى Texture
SDL_Texture* loadTexture(const char* path, SDL_Renderer* renderer);

// التحقق من التصادم بين مستطيلين
bool checkCollision(SDL_Rect a, SDL_Rect b);
