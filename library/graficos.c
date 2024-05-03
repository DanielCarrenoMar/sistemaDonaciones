#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int upL = 218; // ┌
int upR = 191; // ┐
int downR = 217; // ┘
int downL = 192; // └
int cross = 197; // ┼
int crossD = 194; // ┬
int crossU = 193; // ┴
int crossR = 195; // ├
int crossL = 180; // ┤
int vLine = 179; // │
int hLine = 196; // ─

void cfSimpleTabla(){
    upL = 'O'; // ┌
    upR = 'O'; // ┐
    downR = 'O'; // ┘
    downL = 'O'; // └
    cross = '+'; // ┼
    crossD = '+'; // ┬
    crossU = '+'; // ┴
    crossR = '+'; // ├
    crossL = '+'; // ┤
    vLine = '#'; // │
    hLine = '#'; // ─
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
void hidecursor(){
    printf("\e[?25l");
}

void showcursor() {
    printf("\e[?25h");
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
    printf("%c[%d;%df",0x1B,y,x);
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
        printf("%c", 205);
        gotoxy(i, y + h);
        printf("%c", 205);
    }
    for (int i = y; i < y + h; i++){
        gotoxy(x, i);
        printf("%c", 186);
        gotoxy(x + w, i);
        printf("%c", 186);
    }
    gotoxy(x, y); printf("%c", 201);
    gotoxy(x + w, y); printf("%c", 187);
    gotoxy(x, y + h); printf("%c", 200);
    gotoxy(x + w, y + h); printf("%c", 188);
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
/*
    Dibuja un cubo en las coordenadas TAM: 30 X 17
*/
void drawCube(int x, int y){
    
    gotoxy(x+7, y); printf  ("xxxxxxxxxxxxxxxxxxxxxxx");
    gotoxy(x+6, y+1); printf("x                     xx");
    gotoxy(x+5, y+2); printf("x                     x x");
    gotoxy(x+4, y+3); printf("x                     x  x");
    gotoxy(x+3, y+4); printf("x                     x   x");
    gotoxy(x+2, y+5); printf("x                     x    x");
    gotoxy(x+1, y+6); printf("x                     x     x");
    gotoxy(x, y+7); printf  ("XXXXXXXXXXXXXXXXXXXXXXX      x");
    gotoxy(x, y+8); printf  ("X                     X      x");
    gotoxy(x, y+9); printf  ("X                     X      x");
    gotoxy(x, y+10); printf("X                     X      x");
    gotoxy(x, y+11); printf("X                     X     x");
    gotoxy(x, y+12); printf("X                     X    x");
    gotoxy(x, y+13); printf("X                     X   x");
    gotoxy(x, y+14); printf("X                     X  x");
    gotoxy(x, y+15); printf("X                     X x");
    gotoxy(x, y+16); printf("X                     Xx");
    gotoxy(x, y+17); printf("XXXXXXXXXXXXXXXXXXXXXXX"); 
}
/*
    Dibuja CubiTz con ASCII en las coordenadas TAM: 54 X 8
*/
void drawCubiTz(int x, int y){
    gotoxy(x, y); printf(" ______             __        __  ________          ");
    gotoxy(x, y+1); printf("/      \\           /  |      /  |/        |         ");
    gotoxy(x, y+2); printf("$$$$$$  |  __   __ $$ |____  $$/ $$$$$$$$/________  ");
    gotoxy(x, y+3); printf("$$ |  $$/ /  |  /  |$$      \\ /  |   $$ | /        |");
    gotoxy(x, y+4); printf("$$ |      $$ |  $$ |$$$$$$$  |$$ |   $$ | $$$$$$$$/ ");
    gotoxy(x, y+5); printf("$$ |   __ $$ |  $$ |$$ |  $$ |$$ |   $$ |   /  $$/  ");
    gotoxy(x, y+6); printf("$$ \\__/  |$$ \\__$$ |$$ |__$$ |$$ |   $$ |  /$$$$/__ ");
    gotoxy(x, y+7); printf("$$    $$/ $$    $$/ $$    $$/ $$ |   $$ | /$$      |");
    gotoxy(x, y+8); printf(" $$$$$$/   $$$$$$/  $$$$$$$/  $$/    $$/  $$$$$$$$/ ");
}
