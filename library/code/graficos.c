#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../colorama.h"

int upL = 124; // ┌
int upR = 124; // ┐
int downR = 124; // ┘
int downL = 124; // └
int cross = 197; // ┼
int crossD = 194; // ┬
int crossU = 193; // ┴
int crossR = 195; // ├
int crossL = 180; // ┤
int vLine = 124; // │
int hLine = 61; // ─

void ocultarCursor(){
    printf("\e[?25l");
}
void mostrarCursor() {
    printf("\e[?25h");
}
/*
    Dibuja un circulo vacio en la pantalla
*/
void circunferencia(int x, int y, int xr, int yr, char sprite){
    for (int i = 1; i < 360; i++){
        float rad = i * 3.1416 / 180;
        gotoxy(x + xr * cos(rad), y + yr * sin(rad));
        printf("%c", sprite);
    }
}

void graficaPastel(int x, int y, int xr, int yr, char sprite, char* color1, char* color2, int percent){
    printf(color1);
    for (int i = 89; i < 91+360/(100.0/percent); i++){
        float rad = i * 3.1416 / 180;
        for (int r = 0; r <= xr/2; r++) {
            gotoxy(x + (r*2) * cos(rad), y + r * sin(rad));
            printf("%c", sprite);
        }
    }
    printf(color2);
    for (int i = 1; i < 360; i++){
        float rad = i * 3.1416 / 180;
        gotoxy(x + xr * cos(rad), y + yr * sin(rad));
        printf("%c", sprite);
    }
    /*
    for (int i = 89; i < 91+360/(100.0/percent); i++){
        float rad = i * 3.1416 / 180;
        line(x, y, x + xr * cos(rad), y + yr * sin(rad), sprite);
    }*/
    printf(s_RESET_ALL);
}

#ifdef _WIN32
#include <conio.h>
#include <windows.h>
#define CLEAR "cls"

/*
    Mueve el Cursor a una posicion especifica WINDOWS
*/
void gotoxy(int x, int y){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}
void setConsoleColor(char bg, char fg){
    char cmd[30];
    sprintf(cmd, "color %c%c", bg, fg);
    system(cmd);
}
void setConsoleDim(int x, int y){
    char cmd[30];
    sprintf(cmd, "mode con: cols=%d lines=%d", x, y);
    system(cmd);
}
void desactivarmax() {
    HWND consoleWindow = GetConsoleWindow();
    SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
}

#else
#define CLEAR "clear"
/*
    Mueve el Cursor a una posicion especifica LINUX
*/
void gotoxy(int x, int y){
    printf("\033[%d;%dH", y+1 ,x+1);
}

#endif

/*
    Borra la pantalla en cualquier sistema operativo
*/
void borrarPantalla(){
    system(CLEAR);
}
/*
    Usando dos coordenadas dibuja una linea en la pantalla
*/
void line(int x1, int y1, int x2, int y2, char sprite){
    int paso;

    if (x1 == x2){
        if (y1 < y2){paso = 1;}else{paso = -1;}
        for (int i = y1; i != y2; i += paso){
            gotoxy(x1, i);
            printf("%c", sprite);
        }
    }else if (y1 == y2){
        if (x1 < x2){paso = 1;}else{paso = -1;}
        for (int i = x1; i != x2; i += paso){
            gotoxy(i, y1);
            printf("%c", sprite);
        }
    }
    else{
        float m = (float)(y2 - y1) / (x2 - x1);
        float b = y1 - m * x1;
        if (x1 < x2){paso = 1;}else{paso = -1;}
        for (int i = x1; i != x2; i += paso){
            gotoxy(i, m * i + b);
            printf("%c", sprite);
        }
    }
}
/*
    Usando una serie de coordenadas dibuja un poligono
*/
void poligono(int  coords[][2], int elemt, char sprite){
    for (int i = 0; i < elemt-1; i++){
        line(coords[i][0], coords[i][1], coords[i + 1][0], coords[i + 1][1], sprite);
    }
}
/*
    Dibuja un rectangulo en la pantalla
*/
void recuadro(int x, int y, int w, int h){
    for (int i = x; i < x + w; i++){
        gotoxy(i, y);
        printf("%c", hLine);
        gotoxy(i, y + h);
        printf("%c", hLine);
    }
    for (int i = y; i < y + h; i++){
        gotoxy(x, i);
        printf("%c", vLine);
        gotoxy(x + w, i);
        printf("%c", vLine);
    }
    gotoxy(x, y); printf("%c", upL);
    gotoxy(x + w, y); printf("%c", upR);
    gotoxy(x, y + h); printf("%c", downL);
    gotoxy(x + w, y + h); printf("%c", downR);
}
/*
    Dibuja unta tabla con dimensiones especificas
*/
void tabla(int X , int Y, int colum, int filas, int Xsize, int Ysize){

    gotoxy(X,Y); printf("%c", upL);

    for (int c = 0; c < colum; c++){
        for (int x = 0; x < Xsize; x++){
            printf("%c", hLine);
        }
        if (c != colum - 1){
            printf("%c", crossD);
        }else{
            printf("%c", upR);
        }
    }

    for (int f = 1; f < filas; f++){
        gotoxy(X,Y + (Ysize+1) * f); printf("%c", crossR);

        for (int c = 0; c < colum; c++){
            for (int x = 0; x < Xsize; x++){
                printf("%c", hLine);
            }
            if (c != colum - 1){
                printf("%c", cross);
            }else{
                printf("%c", crossL);
            }
        }
    }

    gotoxy(X,Y + filas * (Ysize+1)); printf("%c", downL);

    for (int c = 0; c < colum; c++){
        for (int x = 0; x < Xsize; x++){
            printf("%c", hLine);
        }
        if (c != colum - 1){
            printf("%c", crossU);
        }else{
            printf("%c", downR);
        }
    }

    for (int f = 0; f < filas; f++){
        for (int yz = 1; yz < Ysize+1; yz++){
            int temp = Y + (Ysize+1) * f + yz;
            gotoxy(X, temp); printf("%c", vLine);

            for (int c = 0; c <= colum; c++){
                gotoxy(X + (Xsize+1) * c,temp); printf("%c", vLine);
            }
        }
    }
}
/*
    Dibuja un cuadrado relleno en la pantalla
*/
void cuadrado(int X, int Y, int w, int h, char sprite){
    for (int y = Y; y < Y + h; y++){
        gotoxy(X, y); 
        for (int x = X; x < X + w; x++){
            printf("%c", sprite);
        }
    }
}
