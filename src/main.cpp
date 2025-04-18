#include "Jeu.h"

int main(int argc, char* argv[]) {
    Jeu jeu;
    if (jeu.init("Course à Vélo", 800, 600)) {
        jeu.bouclePrincipale();
    }
    jeu.clean();
    return 0;
}
