#include "Metronomo.h"

typedef struct _Metronomo{
    int bmp;
    int maxTic;
    int currentTic;
    char lowTic[255];
    char uppTic[255];

    //DATOS
    bool running;
    MetronomoCallback callback;
    void* data;
}Metronomo;


Metronomo* MetronomoCreate(int bmp, void* data, MetronomoCallback callback){
    Metronomo* m1 = (Metronomo*)malloc(sizeof(Metronomo));
    m1->bmp = bmp;
    m1->maxTic = 3;
    m1->currentTic = 0;
    strcpy(m1->lowTic,"m1: tic\n");
    strcpy(m1->uppTic,"m1: TIIIC\n");

    //
    m1->running = false;
    m1->data = data;
    m1->callback = callback;
    return m1;
}

/*void _MetronomoShowTic(Metronomo *metronomo){
    if (metronomo->currentTic < metronomo->maxTic){
        printf("%s",metronomo->lowTic);
        metronomo->currentTic++;
    }else{
        printf("%s",metronomo->uppTic);
        metronomo->currentTic = 0;
    }
}*/

DWORD WINAPI solo_thread(void* arg)
{
    Metronomo* md = (Metronomo*) arg;
    md->running = true;
    while (md->running == true){
        //sleep(1/metronomo->bmp);
        md->callback(md,md->data,GetTickCount()/1000.0);

    }
    /* Use 'data'. */
    return 0;
}

// A normal C function that is executed as a thread
// when its name is specified in pthread_create()
void MetronomoStart(Metronomo *metronomo)
{
    if (metronomo->running == true){
        return;
    }
    //CreateThread(NULL, 0, solo_thread,MetronomoCreateRawValues(1 + metronomo->n,(void*)metronomo,metronomo->data), 0, NULL);
    CreateThread(NULL, 0, solo_thread,metronomo, 0, NULL);
}



void MetronomoStop(Metronomo *metronomo){
    metronomo->running = false;
}
void MetronomoDestroy(Metronomo *metronomo){
    metronomo->running = false;
    free(metronomo);
}

