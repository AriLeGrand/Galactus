#define SDL_MAIN_HANDLED
#define FRAMERATE 1000/60
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "render.h"


//#include "init_map.h"
//#include "physc.h"
// #include "audio.h"

float randomfloatinrange(float min, float max) {
    return min + (float)(rand()) * (float)(max - min) / RAND_MAX;
}
int randominrange(int min, int max) { return(rand() % (max - min + 1)) + min; }



#define PLAYER_SPEED 5


#include "utils.h"
#include "particles.h"
#include "controller.h"
#include "player.h"
#include "score.h"


int main(int argc, char* argv[]) {
    srand(0);
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Init(SDL_INIT_VIDEO);

    TTF_Init();
    //SDL_CreateWindowAndRenderer(SW, SH, 0, &window, &renderer);
    

    //Player player1 = initPlayer(700, 900, 50, 50); 
    //Player player2 = initPlayer(500, 500, 50, 50); 

    TTF_Font* font = TTF_OpenFont("fonts/light-arial.ttf", 40);
    if (!font) {
        printf("Error loading font: %s \n", TTF_GetError());
        return 1;
    }

    render_info render_info = init_renderer();
    SDL_SetRenderDrawBlendMode(render_info.renderer, SDL_BLENDMODE_BLEND);
    if (render_info.err != 0)return render_info.err;
    int LAST_HITTED = -1;
    
    /*CUBE CUBE[1]; SLIDER SLIDERS[2]; init_MAP(CUBE, SLIDERS);*/
    int keys[4]; keys[0] = 0; keys[1] = 0; keys[2] = 0; keys[3] = 0;
    int PARTICLE_COUNT = 11; PARTICLE PARTICLES[11];
    int PARTICLE_COUNT_GOAL = 60; PARTICLE PARTICLES_GOAL[60];
    
    CONTROLER CONTROLERS[2];
    PLAYER PLAYERS[2];
    init_CONTROLERS(CONTROLERS);
    COLOR players_colors[2];
    players_colors[0] = (COLOR){ 255, 0, 0 };
    players_colors[1] = (COLOR){ 0, 0, 255 };

    init_PLAYERS(PLAYERS, players_colors, 0);
    SCORE p1_score = (SCORE){ 0, 1 };
    SCORE p2_score = (SCORE){ 0, 2 };

    SDL_Event event;
    debug_info DEBUG_INFO = (debug_info){ 0 };
    while (1) {
        int events_info = handle_events(&render_info, CONTROLERS, &DEBUG_INFO);
        if (events_info != 0)return events_info;
        UPDATE_PLAYERS(PLAYERS, CONTROLERS);
        SDL_SetRenderDrawColor(render_info.renderer, 0, 0, 0, 255);
        SDL_RenderClear(render_info.renderer);
        //renderText(render_info.renderer, font, "Player One Lives: 3", 20, 990, white);
        //renderText(render_info.renderer, font, "Player One Score: 0", 420, 990, white);
        //renderText(render_info.renderer, font, "High Score: 0", 820, 990, white);
        //renderText(render_info.renderer, font, "Player Two Score: 0", 1220, 990, white);
        //renderText(render_info.renderer, font, "Player Two Lives: 3", 1620, 990, white);
        DRAW_SCORE(p1_score, p2_score, &render_info, font, PLAYERS);

        DRAW_PLAYERS(&render_info, PLAYERS, &DEBUG_INFO);
        // more of a fill
        //SDL_RenderCopy(render_info.renderer, backgroundTexture, NULL, NULL);
        //LAST_HITTED = UPDATE_TICK_CUBE(CUBE, SLIDERS, &p1_score, &p2_score, LAST_HITTED,
        //    &PARTICLES, PARTICLE_COUNT, &PARTICLES_GOAL, PARTICLE_COUNT_GOAL);
        //UPDATE_TICK_SLIDERS(keys, SLIDERS);
        //DRAW_OBJS(CUBE, SLIDERS, &render_info);
        //UPDATE_PARTICLES(&PARTICLES, PARTICLE_COUNT, &render_info);
        //UPDATE_PARTICLES(&PARTICLES_GOAL, PARTICLE_COUNT_GOAL, &render_info);
        //DRAW_SCORE(p1_score, p2_score, &render_info, fontPixel);
        SDL_RenderPresent(render_info.renderer); // update display
        SDL_Delay(FRAMERATE);
    }

   

 

    TTF_CloseFont(font);
    SDL_DestroyRenderer(render_info.renderer);
    SDL_DestroyWindow(render_info.window);
    TTF_Quit();
    SDL_Quit();
    return 0;
}
