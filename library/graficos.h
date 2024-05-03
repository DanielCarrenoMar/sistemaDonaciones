#ifndef Graficos_H
#define Graficos_H

void gotoxy(int x, int y);
void borrarPantalla();

#ifdef _WIN32

void setConsoleDim(int x, int y);
void setConsoleColor(char bg, char fg);
void hidecursor();
void showcursor();
void desactivarmax();

#endif
void cfSimpleTabla();

void line(int x1, int y1, int x2, int y2, char sprite);
void poligono(int  coords[16][2], int elemt, char sprite);
void recuadro(int x, int y, int w, int h);
void tabla(int x , int y, int filas, int columnas, int filasize, int columnasize);
void cuadrado(int x, int y, int w, int h, char sprite);
void circunferencia(int x, int y, int xr, int yr, char sprite);
void drawCube(int x, int y);
void drawCubiTz(int x, int y);

#include "Graficos.c"
#endif