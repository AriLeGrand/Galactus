#define MAX_BULLET_COUNT 100;

typedef struct BULLET {
    Vec2 pos;
    Vec2 vel;
    COLOR color;
    int opacity;
    int size;
    int ENABLED;
} BULLET;

BULLET init_bullet(Vec2 pos, Vec2 vel) {
    return (BULLET) {pos, vel, (COLOR) {255, 255, 255}, 5, 255, 1};
}

void UPDATE_BULLETS(BULLET* BULLETS) {
    for (int i = 0; i < MAX_BULLET_COUNT; i++) {
        if (BULLETS[i].ENABLED == 0) continue;
        if (BULLETS[i].pos.x < 0 || BULLETS[i].pos.x > SW || BULLETS[i].pos.y < 0 || BULLETS[i].pos.y > SH) BULLETS[i].ENABLED = 1;
        BULLETS[i].pos.x += BULLETS[i].vel.x;
        BULLETS[i].pos.y += BULLETS[i].vel.y;
    }
}

void DISPLAY_BULLETS(BULLET* BULLETS, render_info* r_i) {
    for (int i = 0; i < MAX_BULLET_COUNT; i++) {
        SDL_Rect sq = { BULLETS[i].pos.x, BULLETS[i].pos.y, BULLETS[i].size, BULLETS[i].size};

        SDL_SetRenderDrawColor(r_i->renderer, BULLETS[i].color.r, BULLETS[i].color.g, BULLETS[i].color.b, BULLETS[i].opacity);
        SDL_RenderFillRect(r_i->renderer, &sq);
    }
}