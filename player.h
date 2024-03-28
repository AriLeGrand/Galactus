typedef struct PLAYER {
    Vec2 pos;
    Vec2 vel;
    COLOR color;
    int health;
    int power_ups;
    int ENABLED;
} PLAYER;

void init_PLAYERS(PLAYER* PLAYERS, COLOR* colors, int ENABLED) {
    for (int i = 0; i < 3; i++) {
        PLAYERS[i] = (PLAYER){ (Vec2) { 0.0, 0.0 }, (Vec2) { 0.0, 0.0 }, colors[i], 3, 0, ENABLED};
    }
}

void UPDATE_PLAYERS(PLAYER* PLAYERS, CONTROLER* CONTROLERS) {
    for (int i = 0; i < 3; i++) {
        PLAYERS[i].pos.x += CONTROLERS[i].DIR.x;
        PLAYERS[i].pos.y += CONTROLERS[i].DIR.y;
    }
}

void DRAW_PLAYERS(render_info* r_i, PLAYER* PLAYERS, debug_info* DEBUG_INFO) {
    //("%d\n", DEBUG_INFO->SHOW_HITBOX);
    for (int i = 0; i < 2; i++) {
        if (PLAYERS[i].ENABLED == 0 && DEBUG_INFO->SHOW_HITBOX == 0) continue;
        SDL_SetRenderDrawColor(r_i->renderer, PLAYERS[i].color.r, PLAYERS[i].color.g, PLAYERS[i].color.b, 255);
        SDL_Rect rect1 = { PLAYERS[i].pos.x, PLAYERS[i].pos.y, 50, 50 };
        SDL_RenderFillRect(r_i->renderer, &rect1);
    }
}