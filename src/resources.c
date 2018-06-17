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

void Metronome(bool keys[MAX_KEYS],double fretposy[MAX_FRET]){
    int tiempo=(int)floorf(al_get_time()*100)%(6000/BPM);
    static int bar=0;                                           //BARRA DEL COMPAS
    static int tack=1;                                          //ACENTUACION
    static int beat=1;                                          //GOLPE
    if(tack>tiempo){
        if(keys[KEY_F1]){
            //printf("%d %d %f\n",beat,bar+1,al_get_time());
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
       //FretFallUpdate(fretposy);
    }
    tack=tiempo;
    return;
}

void FallUpdate(bool keys[MAX_KEYS],double fretposy[MAX_FRET],double fretboardposy[MAX_FRET]){
    double vely=(BPM/25.70)/2;           //2: La cantidad de beats que quiero que tarde
    FretFallUpdate(keys,fretposy,vely);
    FretBoardFallUpdate(fretboardposy,vely);
    NoteFallUpdate(vely);

}

void FretFallUpdate(bool keys[MAX_KEYS],double fretposy[MAX_FRET],double fretvely){
    int i;
    static int bar=0;
    static int beat=1;

    for(i=0;i<MAX_FRET;i++){
        fretposy[i]=fretposy[i]+fretvely;

        if(fretposy[i]>=ScreenHeight-160){
            fretposy[i]=0;
            bar=(bar+1)%TIME_SIGNATURE;
            beat++;
            if(keys[KEY_F1]){
                if(bar==0)
                    SoundMetronome(1);
                else
                    SoundMetronome(0);
            }
            if(beat==(TIME_SIGNATURE*2)+1){
                MusicPlay();
            }
        }
    }
    return;
}

void FretBoardFallUpdate(double fretboardposy[MAX_FRET],double fretboardvely){
    int i;
    for(i=0;i<MAX_FRET;i++){
        fretboardposy[i]=fretboardposy[i]+fretboardvely;
        if(fretboardposy[i]>=ScreenHeight-160){
            fretboardposy[i]=-560;
        }
    }
    return;
}

void NoteFallUpdate(double notevely){

    return;
}

void StatsUpdate(){
    return;
}

