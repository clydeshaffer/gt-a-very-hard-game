#include "gt/gametank.h"
#include "gt/banking.h"
#include "gt/drawing_funcs.h"
#include "gt/input.h"
#include "gt/dynawave.h"
#include "gt/music.h"
#include "gt/feature/text/text.h"
#include "gen/assets/menu.h"
#include "gen/assets/sfx.h"
extern void CubicleReset();
extern int avhg_main();
char selection = 0;

#pragma code-name(push, "PROG1")
void drawbg() {
    clear_border(32);
    draw_sprite(1, 1, 126, 126, 1, 1, 0);
    await_draw_queue();
    print_text(">");
    await_drawing();
}
#pragma code-name(pop)

int main() {
    init_graphics();
    init_dynawave();
    init_music();
    change_rom_bank(0xFC);
    load_spritesheet(&ASSET__menu__menuscreen_bmp, 0);
    load_font(1);
    init_text();

    text_cursor_x = 21;
    text_cursor_y = 16;
    text_color = TEXT_COLOR_WHITE;
    drawbg();
    
    flip_pages();
    text_cursor_x = 26;
    text_cursor_y = 105;
    text_color = TEXT_COLOR_BLACK;
    drawbg();
    while (!(selection & 2))
    {
        update_inputs();
        if(player1_new_buttons & (INPUT_MASK_UP | INPUT_MASK_DOWN)) {
            play_sound_effect(&ASSET__sfx__ping1_bin, 1);
            flip_pages();
            selection = !selection;
        }
        if(player1_new_buttons & (INPUT_MASK_START | INPUT_MASK_A)) {
            stop_sound_effects();
            selection |= 2;
        }
        sleep(1);
        tick_music();
    }
    
    stop_music();
    draw_box(1, 1, 127, 126, 32);
    await_draw_queue();
    flip_pages();

    if(selection & 1) {
        avhg_main();
    } else {
        CubicleReset();
    }
}