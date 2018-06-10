/*
Esta es la seccion visual del codigo. Aqui cargo, trabajo y destruyo todas las
imagenes que seran usadas en el preoyecto.
*/
#include <stdio.h>
#include "resources.h"
#include "constants.h"

#define MAX_BITMAP 70
#define MAX_NOTES 50

#define BITMAP_KEY1 1
#define BITMAP_KEY2 2
#define BITMAP_KEY3 3
#define BITMAP_KEY4 4
#define BITMAP_KEY5 5

#define BITMAP_KEY1PRESSED 11
#define BITMAP_KEY2PRESSED 12
#define BITMAP_KEY3PRESSED 13
#define BITMAP_KEY4PRESSED 14
#define BITMAP_KEY5PRESSED 15

#define BITMAP_NOTE1 21
#define BITMAP_NOTE2 22
#define BITMAP_NOTE3 23
#define BITMAP_NOTE4 24
#define BITMAP_NOTE5 25

#define NOTE_IGB 0  /*Note index green begin*/
#define NOTE_IGE 9  /*Note index green end*/
#define NOTE_IRB 10
#define NOTE_IRE 19
#define NOTE_IYB 20
#define NOTE_IYE 29
#define NOTE_IBB 30
#define NOTE_IBE 39
#define NOTE_IOB 40
#define NOTE_IOE 49

struct notes{
    ALLEGRO_BITMAP *colour;
    double posx;
    double posy;
};

static ALLEGRO_BITMAP **bitmaps;
static struct notes *note;

struct notes NotesCreate(ALLEGRO_BITMAP *colour,double posx,double posy){
    struct notes temp;
    temp.colour=colour;
    temp.posx=posx;
    temp.posy=posy;
    return temp;
}

void AssetsLoad(){
    int i;
    bitmaps=(ALLEGRO_BITMAP **)malloc(sizeof(ALLEGRO_BITMAP *)*MAX_BITMAP);
    for(i=0;i<MAX_BITMAP;i++)
        bitmaps[i]=NULL;
    bitmaps[BITMAP_KEY1]=al_load_bitmap("./images/key1.png");
    bitmaps[BITMAP_KEY2]=al_load_bitmap("./images/key2.png");
    bitmaps[BITMAP_KEY3]=al_load_bitmap("./images/key3.png");
    bitmaps[BITMAP_KEY4]=al_load_bitmap("./images/key4.png");
    bitmaps[BITMAP_KEY5]=al_load_bitmap("./images/key5.png");

    bitmaps[BITMAP_KEY1PRESSED]=al_load_bitmap("./images/key1p.png");
    bitmaps[BITMAP_KEY2PRESSED]=al_load_bitmap("./images/key2p.png");
    bitmaps[BITMAP_KEY3PRESSED]=al_load_bitmap("./images/key3p.png");
    bitmaps[BITMAP_KEY4PRESSED]=al_load_bitmap("./images/key4p.png");
    bitmaps[BITMAP_KEY5PRESSED]=al_load_bitmap("./images/key5p.png");

    bitmaps[BITMAP_NOTE1]=al_load_bitmap("./images/note1.png");
    bitmaps[BITMAP_NOTE2]=al_load_bitmap("./images/note2.png");
    bitmaps[BITMAP_NOTE3]=al_load_bitmap("./images/note3.png");
    bitmaps[BITMAP_NOTE4]=al_load_bitmap("./images/note4.png");
    bitmaps[BITMAP_NOTE5]=al_load_bitmap("./images/note5.png");
    return;
}

void NotesLoad(){
    int i;
    note=(struct notes *)malloc(sizeof(struct notes)*MAX_NOTES);
    for(i=NOTE_IGB;i<NOTE_IGE;i++)
        note[i]=NotesCreate(bitmaps[BITMAP_NOTE1],(ScreenWidth/2)-160,0);
    for(i=NOTE_IRB;i<NOTE_IRE;i++)
        note[i]=NotesCreate(bitmaps[BITMAP_NOTE2],(ScreenWidth/2)-96,0);
    for(i=NOTE_IYB;i<NOTE_IYE;i++)
        note[i]=NotesCreate(bitmaps[BITMAP_NOTE3],(ScreenWidth/2)-32,0);
    for(i=NOTE_IBB;i<NOTE_IBE;i++)
        note[i]=NotesCreate(bitmaps[BITMAP_NOTE4],(ScreenWidth/2)+32,0);
    for(i=NOTE_IOB;i<NOTE_IOE;i++)
        note[i]=NotesCreate(bitmaps[BITMAP_NOTE5],(ScreenWidth/2)+96,0);
    return;
}


void GameChart(){
    al_draw_line((ScreenWidth/2)-163,ScreenHeight,(ScreenWidth/2)-163,0,al_map_rgb(180,180,180),3);
    al_draw_line((ScreenWidth/2)-160,ScreenHeight,(ScreenWidth/2)-160,0,al_map_rgb(220,220,220),3);
    al_draw_line((ScreenWidth/2)+160,ScreenHeight,(ScreenWidth/2)+160,0,al_map_rgb(220,220,220),3);
    al_draw_line((ScreenWidth/2)+163,ScreenHeight,(ScreenWidth/2)+163,0,al_map_rgb(180,180,180),3);

    al_draw_line((ScreenWidth/2)+128,ScreenHeight-192,(ScreenWidth/2)+128,0,al_map_rgb(128,128,128),2);
    al_draw_line((ScreenWidth/2)+64,ScreenHeight-192,(ScreenWidth/2)+64,0,al_map_rgb(128,128,128),2);
    al_draw_line((ScreenWidth/2),ScreenHeight-192,(ScreenWidth/2),0,al_map_rgb(128,128,128),2);
    al_draw_line((ScreenWidth/2)-64,ScreenHeight-192,(ScreenWidth/2)-64,0,al_map_rgb(128,128,128),2);
    al_draw_line((ScreenWidth/2)-128,ScreenHeight-192,(ScreenWidth/2)-128,0,al_map_rgb(128,128,128),2);

    al_draw_line(480,ScreenHeight-132,800,ScreenHeight-132,al_map_rgb(255,255,255),3); /*ELIMINAR*/

    al_draw_bitmap(bitmaps[BITMAP_KEY1],(ScreenWidth/2)-160,ScreenHeight-192,NULL);
    al_draw_bitmap(bitmaps[BITMAP_KEY2],(ScreenWidth/2)-96,ScreenHeight-192,NULL);
    al_draw_bitmap(bitmaps[BITMAP_KEY3],(ScreenWidth/2)-32,ScreenHeight-192,NULL);
    al_draw_bitmap(bitmaps[BITMAP_KEY4],(ScreenWidth/2)+32,ScreenHeight-192,NULL);
    al_draw_bitmap(bitmaps[BITMAP_KEY5],(ScreenWidth/2)+96,ScreenHeight-192,NULL);

    return;
}

void GameInputVisual(bool keys[MAX_KEYS]){
    if(keys[KEY_A]){
        al_draw_bitmap(bitmaps[BITMAP_KEY1PRESSED],(ScreenWidth/2)-160,ScreenHeight-192,NULL);
    }
    else if(keys[KEY_S]){
        al_draw_bitmap(bitmaps[BITMAP_KEY2PRESSED],(ScreenWidth/2)-96,ScreenHeight-192,NULL);
    }
    else if(keys[KEY_G]){
        al_draw_bitmap(bitmaps[BITMAP_KEY3PRESSED],(ScreenWidth/2)-32,ScreenHeight-192,NULL);
    }
    else if(keys[KEY_H]){
        al_draw_bitmap(bitmaps[BITMAP_KEY4PRESSED],(ScreenWidth/2)+32,ScreenHeight-192,NULL);
    }
    else if(keys[KEY_J]){
        al_draw_bitmap(bitmaps[BITMAP_KEY5PRESSED],(ScreenWidth/2)+96,ScreenHeight-192,NULL);
    }
    return;
}

void FretFallRender(double fretposy[MAX_FRET]){
    int i;
    for(i=0;i<MAX_FRET;i++){
        al_draw_line(480,fretposy[i],800,fretposy[i],al_map_rgb(255,255,255),3);
    }
    return;
}

void StatsVisual(bool keys[MAX_KEYS],ALLEGRO_FONT *font){
    if(keys[KEY_F1]){
        al_draw_text(font,al_map_rgb(255,255,255),0,0,ALLEGRO_ALIGN_LEFT,"Time");
        al_draw_text(font,al_map_rgb(255,255,255),0,24,ALLEGRO_ALIGN_LEFT,"Song");

    }
    return;
}

void AssetsDestroy(){
    int i;
    for(i=0;i<MAX_BITMAP;i++){
        if(bitmaps[i]!=NULL)
            al_destroy_bitmap(bitmaps[i]);
    }
    free(bitmaps);
    free(note);
    return;
}
