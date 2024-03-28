typedef struct PLAYER {
    Vec2 pos;
    Vec2 vel;
    int health;
    int power_ups;
} PLAYER;

void init_PLAYERS(PLAYER* PLAYERS) {
    for (int i = 0; i < 3; i++) {
        PLAYERS[i] = (PLAYER){ (Vec2) { 0.0, 0.0 }, (Vec2) { 0.0, 0.0 }, 3, 0 };
    }
}

void UPDATE_PLAYERS(PLAYER* PLAYERS, CONTROLER* CONTROLERS) {
    for (int i = 0; i < 3; i++) {
        PLAYERS[i].pos.x += CONTROLERS[i].DIR.x;
        PLAYERS[i].pos.y += CONTROLERS[i].DIR.y;
    }
}