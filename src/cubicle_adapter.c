#include "gt/gametank.h"
#include "gt/drawing_funcs.h"
#include <zlib.h>

extern char CubicleLoadedMusic;

char CubicleLoadedMap[4096];
extern char CubicleACP[];
extern char CubicleSprites[];
extern char CubicleMainMusic[];
extern char CubicleVictoryMusic[];
extern char CubicleMainMap[];
extern char CubicleTitleMap[];
extern char CubicleVictoryMap[];

extern char* current_tilemap;
#pragma zpsym ("current_tilemap");

void unpack_cubicle_acp() {
    inflatemem(aram, CubicleACP);
}

void unpack_cubicle_graphics() {
    load_spritesheet(CubicleSprites, 0xFC, 0);
}

void unpack_main_cubicle_music() {
    inflatemem(&CubicleLoadedMusic, CubicleMainMusic);
}

void unpack_victory_cubicle_music() {
    inflatemem(&CubicleLoadedMusic, CubicleVictoryMusic);
}

void unpack_title_tile_map() {
    inflatemem(current_tilemap, CubicleTitleMap);
}

void unpack_main_tile_map() {
    inflatemem(CubicleLoadedMap, CubicleMainMap);
}

void unpack_victory_tile_map() {
    inflatemem(current_tilemap, CubicleVictoryMap);
}