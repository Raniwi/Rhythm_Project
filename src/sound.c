#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include "resources.h"
#include "constants.h"

#define MAX_SAMPLE 3

static ALLEGRO_SAMPLE **samples;

void SoundLoad(){
    al_reserve_samples(MAX_SAMPLE);
    samples=(ALLEGRO_SAMPLE **)malloc(sizeof(ALLEGRO_SAMPLE *)*MAX_SAMPLE);

    samples[0]=al_load_sample("./sound/metronome_tick.wav");
    samples[1]=al_load_sample("./sound/metronome_tack.wav");
    samples[2]=al_load_sample("./sound/GEJ.wav");
    return;
}

void SoundMetronome(int acentua){
    if(acentua){
        al_play_sample(samples[1],0.5,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,0);
    }
    else{
        al_play_sample(samples[0],0.5,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,0);
    }
    return;
}

void MusicPlay(){
    al_play_sample(samples[2],1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,0);
    return;
}

void SoundDestroy(){
    int i;
    for(i=0;i<MAX_SAMPLE;i++){
        al_destroy_sample(samples[i]);
    }
    return;
}
