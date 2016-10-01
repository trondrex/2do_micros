#include <Event.h>
#include <Timer.h>
#ifndef JUEGO_H
#define JUEGO_H
#include "Arduino.h"
#include <LiquidCrystal.h>
////////////////////tiempos//////////////////
#define t_b 800 //blanca
#define t_n 400 //negra
#define t_c 200 //corchea
#define t_sc 100 //semicorchea
#define S 0 //silencio
///////////////////////notas////////////////////
#define c 261
#define cs 277
#define d 294
#define ds 311
#define e 329
#define f 349
#define fs 369
#define g 392
#define gs 415
#define a 440
#define as 466
#define b 493
#define c2 523
#define c2s 554
#define D2 587
#define d2s 622
#define e2 659
#define f2 698
#define f2s 739
#define g2 783
#define g2s 830
#define a2 880
#define a2s 932
#define b2 987


  void initGame();
  void principal();
  void left();
  void right();
  void verifica();
  void verifica2();
  void llenar_fila();
  void llenar_columna();
  void escribir();
  void led();
  void disp();
  void musica();
  void actualizar();
  void estado();

#endif /*JUEGO_H*/ 
