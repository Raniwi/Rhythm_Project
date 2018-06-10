/*Declaracion de funciones*/
#ifndef RESOURCES_H_   /* Include guard */
#define RESOURCES_H_
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include<allegro5/allegro_primitives.h>

#define MAX_KEYS 6
#define MAX_FRET 3

enum GAMEKEYS{KEY_A,KEY_S,KEY_G,KEY_H,KEY_J,KEY_F1};

/*
POR QUE ESTO NO FUNCA
int GameInit(ALLEGRO_EVENT ev,bool keys[MAX_KEYS],ALLEGRO_FONT *font,double fretposy[MAX_FRET],bool done,ALLEGRO_TIMER *framepersecond,ALLEGRO_TIMER *beatpersecond);
void GameInput(ALLEGRO_EVENT ev,bool keys[MAX_KEYS],bool done);
*/

void particle_create(int *xmouse,int *ymouse);
void particle_draw();
void particle_update();
void particle_sparkle();
void StatsUpdate();
void Metronome(bool keys[MAX_KEYS],double fretposy[MAX_FRET]);
void FretFallUpdate(double fretposy[MAX_FRET]);

void AssetsLoad();
void GameChart();
void GameStats(ALLEGRO_FONT *font);
void GameInputVisual(bool keys[MAX_KEYS]);
void StatsVisual(bool keys[MAX_KEYS],ALLEGRO_FONT *font);
void FretFallRender(double fretposy[MAX_FRET]);
void AssetsDestroy();

void SoundLoad();
void SoundMetronome();
void MusicPlay();
void SoundDestroy();

#endif
