/*
Esta es la seccion de recursos, donde seran alojados todos los codigos que tengan que ver
con calculos de posicion, tiempo, etc.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "resources.h"
#include "constants.h"
#define TIME_SIGNATURE 3

struct particle{
    int x;
    int y;
    int xspeed;
    int yspeed;
};

struct particle spark;

void particle_create(int *xmouse,int *ymouse){
    spark.x=*xmouse;
    spark.y=*ymouse;
    spark.xspeed=(rand()%11-5)*2;
    spark.yspeed=(rand()%11-11)*2;
    printf("%d,",spark.x);
    printf("%d\n",spark.y);
}

void particle_draw(){
    const float framerate=15.0;
    al_init_primitives_addon();
    ALLEGRO_COLOR circle_color=al_map_rgb(255,255,255);
    al_draw_filled_circle(spark.x,spark.y,3,circle_color);


    ALLEGRO_TIMER *timer=al_create_timer(1.0/framerate);
    ALLEGRO_EVENT_QUEUE *event_queue=al_create_event_queue();
    al_register_event_source(event_queue,al_get_timer_event_source(timer));
    al_start_timer(timer);
    ALLEGRO_EVENT ev;
    al_wait_for_event(event_queue, &ev);

    particle_update();
    return;
}

void particle_update(){
    spark.x=spark.x+spark.xspeed;
    spark.yspeed=spark.yspeed+2;
    spark.y=spark.y+spark.yspeed;
    return;
}

void particle_sparkle(){
    struct particle spark;
    const float framerate=15.0;
    ALLEGRO_COLOR circle_color=al_map_rgb(255,255,255);

    ALLEGRO_TIMER *timer=al_create_timer(1.0/framerate);
    ALLEGRO_EVENT_QUEUE *event_queue=al_create_event_queue();
    al_register_event_source(event_queue,al_get_timer_event_source(timer));
    al_start_timer(timer);

    al_init_primitives_addon();

    while(spark.y<ScreenHeight){
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);
        al_draw_filled_circle(spark.x,spark.y,3,circle_color);

        spark.x=spark.x+spark.xspeed;
        spark.yspeed=spark.yspeed+2;
        spark.y=spark.y+spark.yspeed;
        printf("%d\n",spark.yspeed);
        al_flip_display();
        al_clear_to_color(al_map_rgb(0,0,0));
    }
    return;
}

void Metronome(){
    int tiempo=(int)floorf(al_get_time()*100)%(6000/BPM);
    static int bar=0;                                           //BARRA DEL COMPAS
    static int tack=1;                                          //ACENTUACION
    static int beat=1;                                          //GOLPE
    if(tack>tiempo){
        printf("%d %d %f\n",beat,bar+1,al_get_time());
        if(bar==0){
            SoundMetronome(1);
        }
        else{
            SoundMetronome(0);
        }
        bar=(bar+1)%TIME_SIGNATURE;
        beat++;
    }
    tack=tiempo;
    return;
}

void FretFallUpdate(double fretposy[MAX_FRET]){
    float fretvely=((ScreenHeight-160)/(6000/BPM));
    int i;
    for(i=0;i<MAX_FRET;i++){
        if(fretposy[i]<ScreenHeight-160){
            fretposy[i]=fretposy[i]+fretvely;
        }
        else{
            fretposy[i]=0;
            SoundMetronome(0);
        }
    }
    return;
}

void StatsUpdate(){

    return;
}
