#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include "resources.h"
#include "constants.h"

#define MAX_SAMPLE 3

static ALLEGRO_SAMPLE **samples;
static ALLEGRO_SAMPLE_INSTANCE *instances[MAX_SAMPLE];

void SoundLoad(){
    int i;
    al_reserve_samples(MAX_SAMPLE);
    samples=(ALLEGRO_SAMPLE **)malloc(sizeof(ALLEGRO_SAMPLE *)*MAX_SAMPLE);

    samples[0]=al_load_sample("./sound/metronome_tick.wav");
    samples[1]=al_load_sample("./sound/metronome_tack.wav");
    samples[2]=al_load_sample("./sound/GEJ.wav");

    for(i=0;i<MAX_SAMPLE;i++){
        instances[i]=al_create_sample_instance(samples[i]);
        al_attach_sample_instance_to_mixer(instances[i],al_get_default_mixer());
    }
    return;
}

void SoundMetronome(int acentua){
    if(acentua){
        al_play_sample_instance(instances[1]);
    }
    else{
        al_play_sample_instance(instances[0]);
    }
    return;
}

void MusicPlay(){
    al_play_sample_instance(instances[2]);
    return;
}

void SoundDestroy(){
    int i;
    for(i=0;i<MAX_SAMPLE;i++){
        al_destroy_sample(samples[i]);
        al_destroy_sample_instance(instances[i]);
    }
    return;
}
