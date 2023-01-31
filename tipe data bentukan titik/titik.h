// PELAYAN
#ifndef TITIK_H
#define TITIK_H

// Type Titik = <x: integer, y: integer>
typedef struct { int x; int y; } Titik;

// function getAbsis(T:Titik)
int getAbsis(Titik T);
/*
{ mengembalikan/membaca nilai absis Titik T }
*/
void setAbsis(Titik *T, int dx);

#endif
