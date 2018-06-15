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
#include "resources.h"
#include "constants.h"

int main(){
    int i;
    static double fretposy[MAX_FRET];
    bool done=false;
    bool keys[MAX_KEYS];
    if(!al_init()){
        fprintf(stderr, "failed to initialize allegro!\n");
        return -1;
    }

    al_set_new_display_flags(ALLEGRO_WINDOWED|ALLEGRO_RESIZABLE);
    ALLEGRO_DISPLAY *display=al_create_display(ScreenWidth,ScreenHeight);
    al_set_window_position(display,512,256);
    al_set_window_title(display,"Rhythm Game");

    if(!display){
        fprintf(stderr, "failed to create display!\n");
    }

    al_install_audio();
    al_install_keyboard();
    al_install_mouse();

    al_init_font_addon();
    al_init_ttf_addon();
    al_init_image_addon();
    al_init_primitives_addon();
    al_init_acodec_addon();
    ALLEGRO_FONT *font=al_load_font("./DTM-Mono.otf",24,NULL);

    ALLEGRO_TIMER *framepersecond=al_create_timer(1.0/FPS);
    ALLEGRO_TIMER *beatpersecond=al_create_timer(60.0/BPM);
    ALLEGRO_EVENT_QUEUE *event_FPS=al_create_event_queue();
    al_register_event_source(event_FPS,al_get_timer_event_source(framepersecond));
    al_register_event_source(event_FPS,al_get_timer_event_source(beatpersecond));
    al_register_event_source(event_FPS,al_get_display_event_source(display));
    al_register_event_source(event_FPS,al_get_keyboard_event_source());
    al_start_timer(framepersecond);

    srand(time(0));

    AssetsLoad();
    SoundLoad();

    for(i=0;i<MAX_KEYS;i++){
        keys[i]=false;
    }
    for(i=0;i<MAX_FRET;i++){
        fretposy[i]=0;
    }

    struct MiData *dat=CreateData();
    Metronomo* met = MetronomoCreate(120,&dat,BPM_Event);
    MetronomoStart(met);
    while(!done){
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_FPS, &ev);
        al_clear_to_color(al_map_rgb(0,0,0));

        GameInit(ev,keys,font,GetDataFretPos(dat),&done,framepersecond,beatpersecond);
        if(ev.type==ALLEGRO_EVENT_DISPLAY_CLOSE)
            done=true;
        else if(ev.timer.source==framepersecond)
            al_flip_display();
    }

    AssetsDestroy();
    SoundDestroy();
    MetronomoDestroy(met);
    free(dat);
    al_destroy_timer(beatpersecond);
    al_destroy_timer(framepersecond);
    al_destroy_font(font);
    al_destroy_display(display);
    al_uninstall_keyboard();
    al_uninstall_mouse();
    return 0;
}
