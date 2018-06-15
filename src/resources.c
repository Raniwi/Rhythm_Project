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

struct MiData{
    double fretposy[MAX_FRET];
};

void Metronome(bool keys[MAX_KEYS],double fretposy[MAX_FRET]){
  /*  int tiempo=(int)floorf(al_get_time()*100)%(6000/BPM);
    static int bar=0;                                           //BARRA DEL COMPAS
    static int tack=1;                                          //ACENTUACION
    static int beat=1;                                          //GOLPE
    if(tack>tiempo){
        if(keys[KEY_F1]){
            printf("%d %d %f\n",beat,bar+1,al_get_time());
            if(bar==0){
                SoundMetronome(1);
            }
            else{
                SoundMetronome(0);
            }
        }
        else if(beat==(TIME_SIGNATURE*2)+1){
            MusicPlay();
        }

        bar=(bar+1)%TIME_SIGNATURE;
        beat++;
    }
    if(beat>=(TIME_SIGNATURE*2)){
       FretFallUpdate(fretposy);
    }
    tack=tiempo;*/
    return;
}

struct MiData *CreateData(){
    struct MiData* temp=(struct MiData*)malloc(sizeof(struct MiData));
    int i;
    for(i=0;i<MAX_FRET;i++){
        temp->fretposy[i]=0;
    }
    return temp;
}

double *GetDataFretPos(struct MiData* temp){
    return temp->fretposy;
}

void BPM_Event(Metronomo* metronomo,void* data,double seconds){
    struct MiData* var = (struct MiData*)data;
    int tiempo=(int)floorf(seconds*100)%(6000/(BPM*1));
    static int negra=0,beat=1,tack=1,bar=0;
    if(tack>tiempo){
        if(negra%1==0){
            printf("%d %d %d %f\n",negra,bar+1,beat,seconds);
            if(bar==0)
                SoundMetronome(1);
            else
                SoundMetronome(0);

            if(beat==(TIME_SIGNATURE*2)+1)
                MusicPlay();

            beat++;
            bar=(bar+1)%TIME_SIGNATURE;
            if(beat>=TIME_SIGNATURE){}
        }
        negra++;
    }
    tack=tiempo;
}

void FretFallUpdate(double fretposy[MAX_FRET]){
    double fretvely=(BPM/25.75)/2;           //2: La cantidad de beats que quiero que tarde
    int i;
    printf("%f\n",fretvely);
    for(i=0;i<MAX_FRET;i++){
        if(fretposy[i]<ScreenHeight-160){
            fretposy[i]=fretposy[i]+fretvely;
        }
        if(fretposy[i]>ScreenHeight-160){
            SoundMetronome(0);
            fretposy[i]=0;
        }
        if(fretposy[i]==((ScreenHeight-160)/2)){
            SoundMetronome(0);
        }
    }
    return;
}

void StatsUpdate(){
    return;
}

