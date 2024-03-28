#pragma once
#include "libs.h"
#include "render.h"


const TTF_Font* font;

typedef struct SCORE {
    int score;
    int player;
} SCORE;


TTF_Font* init_SCORE() {
    const char* fontPath = "light-arial.ttf";
    int size = 25;

    // Cette fonction doit �tre appel�e une fois au d�but de votre programme

    if (TTF_Init() == -1) {
        printf("Erreur lors de l'initialisation de SDL_ttf: %s\n", TTF_GetError());
    }
    font= TTF_OpenFont(fontPath, size);
    // Charger la police TrueType � partir d'un fichier
    if (font == NULL) {
        printf("Erreur lors du chargement de la police : %s\n", TTF_GetError());
    }
    return 0;
}




void DRAW_SCORE(SCORE p1, SCORE p2, render_info* r_i, TTF_Font* font, PLAYER* PLAYERS) {
    char buf[24];
    snprintf(buf, 24, "Player One Lives : %d", PLAYERS[0].health);
    renderText(r_i->renderer, font, buf, 20, 990, white);


    snprintf(buf, 24, "Player One Score : %d", p1.score);
    renderText(r_i->renderer, font, buf, 420, 990, white);

    renderText(r_i->renderer, font, "High Score: 0", 820, 990, white);


    snprintf(buf, 24, "Player Two Lives : %d", PLAYERS[1].health);
    renderText(r_i->renderer, font, buf, 1620, 990, white);

    
    snprintf(buf, 24, "Player Two Score : %d", p2.score);
    renderText(r_i->renderer, font, buf, 1220, 990, white);

}