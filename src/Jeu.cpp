#include "Jeu.h"
#include <iostream>

Jeu::Jeu() : fenetre(nullptr), rendu(nullptr), enCours(false) {}

Jeu::~Jeu() {}

bool Jeu::init(const char* titre, int largeur, int hauteur) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0) {
        std::cout << "Erreur SDL : " << SDL_GetError() << std::endl;
        return false;
    }

    fenetre = SDL_CreateWindow(titre, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, largeur, hauteur, 0);
    if (!fenetre) {
        std::cout << "Erreur fenêtre : " << SDL_GetError() << std::endl;
        return false;
    }

    rendu = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);
    if (!rendu) {
        std::cout << "Erreur rendu : " << SDL_GetError() << std::endl;
        return false;
    }

    enCours = true;
    return true;
}

void Jeu::bouclePrincipale() {
    SDL_Event evenement;

    while (enCours) {
        while (SDL_PollEvent(&evenement)) {
            if (evenement.type == SDL_QUIT) {
                enCours = false;
            }
        }

        SDL_SetRenderDrawColor(rendu, 135, 206, 235, 255); // ciel bleu
        SDL_RenderClear(rendu);

        // TODO: Dessiner vélo, murs, chrono...

        SDL_RenderPresent(rendu);
    }
}

void Jeu::clean() {
    SDL_DestroyRenderer(rendu);
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
}
