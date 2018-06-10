#include "Metronomo.h"

typedef struct _Metronomo{
    int bmp;
    bool running;
    int maxTic;
    int currentTic;
    char lowTic[255];
    char uppTic[255];
    MetronomoCallback callback;
    void* data;
}Metronomo;

typedef struct _MetronomoData{
    Metronomo* m;
    void* v;
}MetronomoData;

MetronomoData* MetronomoDataCreate(Metronomo* m, void* data){
    MetronomoData* md = malloc(sizeof(MetronomoData));
    md->m = m;
    md-> v = data;
    return md;
}

Metronomo* MetronomoCreate(int bmp, void* data, MetronomoCallback callback){
    Metronomo* m1 = (Metronomo*)malloc(sizeof(Metronomo));
    m1->bmp = bmp;
    m1->maxTic = 3;
    m1->running = false;
    m1->currentTic = 0;
    strcpy(m1->lowTic,"m1: tic\n");
    strcpy(m1->uppTic,"m1: TIIIC\n");
    m1->data = data;
    m1->callback = callback;
    return m1;
}

void _MetronomoShowTic(Metronomo *metronomo){
    if (metronomo->currentTic < metronomo->maxTic){
        printf("%s",metronomo->lowTic);
        metronomo->currentTic++;
    }else{
        printf("%s",metronomo->uppTic);
        metronomo->currentTic = 0;
    }
}

DWORD WINAPI solo_thread(void* arg)
{
    MetronomoData* md = (MetronomoData*) arg;
    md->m->running = true;
    while (md->m->running == true){
            //sleep(1/metronomo->bmp);
            md->m->callback(md->m,md->v,clock()/1000.0);
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
    CreateThread(NULL, 0, solo_thread,(void *)MetronomoDataCreate(metronomo,metronomo->data), 0, NULL);
}
void MetronomoStop(Metronomo *metronomo){
    metronomo->running = false;
}
void MetronomoDestroy(Metronomo *metronomo){
    metronomo->running = false;
    free(metronomo);
}

