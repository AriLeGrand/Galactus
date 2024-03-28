#define MAX_BULLET_COUNT 100

typedef struct BULLET {
    Vec2 pos;
    Vec2 vel;
    COLOR color;
    int opacity;
} BULLET;

BULLET init_bullet(Vec2 pos, Vec2 vel) {
    return (BULLET) {pos, vel, (COLOR) {255, 255, 255}, 255};
}

void UPDATE_BULLETS(BULLET* BULLETS) {
    for (int i = 0; i < MAX_BULLET_COUNT; i++) {
        BULLETS[i].pos.x += BULLETS[i].vel.x;
        BULLETS[i].pos.y += BULLETS[i].vel.y;
    }
}

void DISPLAY_BULLETS(BULLET* BULLETS, render_info* r_i) {
    
    for (int i = 0; i < MAX_BULLET_COUNT; i++) {
        // printf("%d\n", BULLETS[i].pos.x);
        SDL_Rect sq = { BULLETS[i].pos.x, BULLETS[i].pos.y, 5, 5};

        SDL_SetRenderDrawColor(r_i->renderer, BULLETS[i].color.r, BULLETS[i].color.g, BULLETS[i].color.b, BULLETS[i].opacity);
        SDL_RenderFillRect(r_i->renderer, &sq);
    }
}