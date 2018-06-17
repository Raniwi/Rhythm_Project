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
#include "Metronomo.h"

#define MAX_KEYS 6
#define MAX_FRET 2

enum GAMEKEYS{KEY_A,KEY_S,KEY_G,KEY_H,KEY_J,KEY_F1};

/*
POR QUE ESTO NO FUNCA
int GameInit(ALLEGRO_EVENT ev,bool keys[MAX_KEYS],ALLEGRO_FONT *font,double fretposy[MAX_FRET],bool done,ALLEGRO_TIMER *framepersecond,ALLEGRO_TIMER *beatpersecond);
void GameInput(ALLEGRO_EVENT ev,bool keys[MAX_KEYS],bool done);
AHORA SI FUNCA
*/

int GameInit(ALLEGRO_EVENT ev,bool keys[MAX_KEYS],ALLEGRO_FONT *font,double fretposy[MAX_FRET],double fretboardposy[MAX_FRET],bool *done,ALLEGRO_TIMER *framepersecond,ALLEGRO_TIMER *beatpersecond);
void GameInput(ALLEGRO_EVENT ev,bool keys[MAX_KEYS],bool *done);

void Metronome(bool keys[MAX_KEYS],double fretposy[MAX_FRET]);
void FallUpdate(bool keys[MAX_KEYS],double fretposy[MAX_FRET],double fretboardposy[MAX_FRET]);
void FretFallUpdate(bool keys[MAX_KEYS],double fretposy[MAX_FRET],double fretvely);
void FretBoardFallUpdate(double fretboardposy[MAX_FRET],double fretboardvely);
void NoteFallUpdate(double notevely);
void StatsUpdate();

void AssetsLoad();
void GameChart();
void GameStats(ALLEGRO_FONT *font);
void GameInputVisual(bool keys[MAX_KEYS]);
void StatsVisual(bool keys[MAX_KEYS],ALLEGRO_FONT *font);
void FretBoardFallVisual(double fretboardposy[MAX_FRET]);
void FretFallVisual(double fretposy[MAX_FRET]);
void AssetsDestroy();

void SoundLoad();
void SoundMetronome();
void MusicPlay();
void SoundDestroy();

#endif
