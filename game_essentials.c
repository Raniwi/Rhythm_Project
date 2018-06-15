/*En esta seccion va el juego en si*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include "game_essentials.h"
#include "constants.h"

/*BEATPERSECOND SIN USO*/

int GameInit(ALLEGRO_EVENT ev,bool keys[MAX_KEYS],ALLEGRO_FONT *font,double fretposy[MAX_FRET],bool *done,ALLEGRO_TIMER *framepersecond,ALLEGRO_TIMER *beatpersecond){

    //Metronome(keys,fretposy);
    FretFallUpdate(keys,fretposy);
    StatsUpdate();

    if(ev.type==ALLEGRO_EVENT_TIMER){
        if(ev.timer.source==framepersecond){
            FretFallRender(fretposy);
            GameChart();
            GameInputVisual(keys);
            StatsVisual(keys,font);
            al_draw_text(font,al_map_rgb(255,255,255),ScreenWidth,0,ALLEGRO_ALIGN_RIGHT,"Press ESC to quit ");
        }
    }
    else if(ev.type>=ALLEGRO_EVENT_KEY_DOWN&&ev.type<=ALLEGRO_EVENT_KEY_UP){
        GameInput(ev,keys,done);
    }

    return 0;
}

void GameInput(ALLEGRO_EVENT ev,bool keys[MAX_KEYS],bool *done){
    if(ev.type==ALLEGRO_EVENT_KEY_DOWN){
        switch(ev.keyboard.keycode){
            case ALLEGRO_KEY_A:keys[KEY_A]=true;break;
            case ALLEGRO_KEY_S:keys[KEY_S]=true;break;
            case ALLEGRO_KEY_G:keys[KEY_G]=true;break;
            case ALLEGRO_KEY_H:keys[KEY_H]=true;break;
            case ALLEGRO_KEY_J:keys[KEY_J]=true;break;
            case ALLEGRO_KEY_F1:keys[KEY_F1]=!keys[KEY_F1];break;
            case ALLEGRO_KEY_ESCAPE:*done=true;break;
        }
    }
    if(ev.type==ALLEGRO_EVENT_KEY_UP){
        switch(ev.keyboard.keycode){
            case ALLEGRO_KEY_A:keys[KEY_A]=false;break;
            case ALLEGRO_KEY_S:keys[KEY_S]=false;break;
            case ALLEGRO_KEY_G:keys[KEY_G]=false;break;
            case ALLEGRO_KEY_H:keys[KEY_H]=false;break;
            case ALLEGRO_KEY_J:keys[KEY_J]=false;break;
        }
    }
    return;
}
