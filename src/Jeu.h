#ifndef JEU_H
#define JEU_H

#include <SDL2/SDL.h>

class Jeu {
public:
    Jeu();
    ~Jeu();

    bool init(const char* titre, int largeur, int hauteur);
    void bouclePrincipale();
    void clean();

private:
    SDL_Window* fenetre;
    SDL_Renderer* rendu;
    bool enCours;
};

#endif

