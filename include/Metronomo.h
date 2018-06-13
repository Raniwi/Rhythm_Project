#ifndef METRONOMO_H
#define METRONOMO_H
#include <windows.h>
#include <stdbool.h>
typedef struct _Metronomo Metronomo;
typedef struct _MetronomoData MetronomoData;
typedef void (*MetronomoCallback)(Metronomo* metronomo,void* data,double seconds);
Metronomo* MetronomoCreate(int bmp, void* data,MetronomoCallback callback);
void MetronomoStart(Metronomo *metronomo);
void MetronomoStop(Metronomo *metronomo);
void MetronomoDestroy(Metronomo *metronomo);

DWORD WINAPI solo_thread(void* arg);
void _MetronomoShowTic(Metronomo *metronomo);


#endif // METRONOMO_H
