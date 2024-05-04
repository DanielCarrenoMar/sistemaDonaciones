#include "graficos.h"
#include "colorama.h"
/*
    X 40 Y 8
*/
void imgTextPrincipal(int x, int y, char* color){
    int asciiImage[8][40] = {
        {95,95,95,95,95,95,32,32,32,32,32,95,32,32,32,32,32,32,32,32,32,32,32,32,95,32,32,32,32,32,32,32,32,32,32,32,32,32,95,32,},
{124,32,95,95,95,32,92,32,32,32,40,95,41,32,32,32,32,32,32,32,32,32,32,40,95,41,32,32,32,32,32,32,32,32,32,32,32,124,32,124,},
{124,32,124,95,47,32,47,32,95,95,32,95,32,95,32,95,95,32,32,32,95,95,95,32,95,32,95,32,95,95,32,32,32,95,95,32,95,124,32,124,},
{124,32,32,95,95,47,32,39,95,95,124,32,124,32,39,95,32,92,32,47,32,95,95,124,32,124,32,39,95,32,92,32,47,32,95,96,32,124,32,124,},
{124,32,124,32,32,124,32,124,32,32,124,32,124,32,124,32,124,32,124,32,40,95,95,124,32,124,32,124,95,41,32,124,32,40,95,124,32,124,32,124,},
{92,95,124,32,32,124,95,124,32,32,124,95,124,95,124,32,124,95,124,92,95,95,95,124,95,124,32,46,95,95,47,32,92,95,95,44,95,124,95,124,},
{32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,124,32,124,32,32,32,32,32,32,32,32,32,32,32,32,},
{32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,124,95,124,32,32,32,32,32,32,32,32,32,32,32,32,},
    };

    for (int i = 0; i < 8; i++) {
        gotoxy(x, y);
        printf("%s",color);
        for (int j = 0; j < 40; j++) {
            if (asciiImage[i][j] != 0)
            printf("%c", asciiImage[i][j]);
        }
        y++;
        printf(s_RESET_ALL);
        printf("\n");
    }
}
/*
    X 45 Y 23
*/
void imgArbolBuho1(int x, int y, char* color){
    int asciiImage[23][118] = {
        {32,47,59,45,46,95,44,45,46,95,95,95,95,32,32,32,32,32,32,32,32,44,45,45,45,45,45,46,95,95,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,},
{40,95,58,35,58,58,95,46,58,58,58,46,32,96,45,46,95,32,32,32,47,58,44,32,47,45,46,95,44,32,96,46,95,44,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,},
{32,32,32,32,92,32,32,32,95,124,96,34,61,58,95,58,58,46,96,46,41,59,32,32,92,32,95,95,47,32,47,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,},
{32,32,32,32,32,32,44,32,32,32,32,96,46,47,32,32,92,58,46,32,96,46,32,32,32,41,61,61,45,39,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,},
{61,45,46,32,32,44,92,44,32,43,35,46,47,96,32,32,32,92,58,46,32,32,47,32,47,32,32,32,32,32,32,32,47,92,32,47,92,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,},
{96,45,39,32,44,32,44,92,32,39,96,32,96,32,96,32,32,32,41,58,32,44,32,47,95,32,32,45,111,32,32,40,40,111,118,111,41,41,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,},
{32,45,32,43,32,43,45,32,58,32,58,45,32,43,32,43,32,45,58,39,32,32,47,40,111,45,41,32,92,41,32,40,41,58,58,58,40,41,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,},
{32,32,32,32,96,32,96,47,96,32,39,32,44,32,44,32,44,58,39,32,96,39,45,45,34,46,45,45,34,45,45,45,45,86,86,86,45,45,45,45,46,95,47,96,55,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,},
{92,44,45,46,95,96,32,96,32,43,32,39,92,44,32,44,34,32,32,32,95,44,45,45,46,95,44,45,45,45,45,45,46,45,45,45,45,45,34,58,46,95,95,47,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,},
{32,32,96,32,32,88,96,32,95,124,32,95,44,92,47,39,32,32,32,46,45,39,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,},
{34,58,46,95,58,96,92,95,95,95,95,32,32,47,58,39,32,32,47,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,},
{32,32,32,32,92,58,58,46,32,32,58,92,47,58,39,32,32,47,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,},
{32,32,32,32,32,96,46,58,46,32,32,47,58,39,32,32,125,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,},
{32,32,32,32,32,32,32,41,58,95,40,58,59,32,32,32,92,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,},
{32,32,32,32,32,32,47,58,46,32,95,47,32,44,32,32,124,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,},
{32,32,32,32,32,40,124,58,58,46,32,32,32,32,32,44,96,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,},
{32,32,32,32,32,32,124,58,58,46,32,32,32,32,123,92,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,},
{32,32,32,32,32,32,124,58,58,46,92,32,32,92,32,96,46,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,},
{32,32,32,32,32,32,124,58,58,58,40,92,32,32,32,32,124,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,},
{32,32,32,32,32,32,124,58,58,58,47,123,32,125,32,32,124,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,111,41,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,79,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,79,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,},
{32,32,95,95,95,47,35,92,58,58,96,47,32,40,79,32,34,61,61,46,95,95,95,95,95,32,32,79,32,44,32,40,32,79,32,92,96,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,40,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,41,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,},
{126,34,126,126,44,92,96,32,96,58,47,44,45,40,126,96,34,126,126,126,126,126,126,126,126,34,126,111,126,92,126,47,126,119,124,47,126,126,126,126,126,126,126,126,126,34,126,111,126,92,126,47,126,119,124,47,126,126,126,126,126,126,126,126,126,34,126,111,126,92,126,47,126,119,124,47,126,126,126,126,126,126,126,126,126,34,126,111,126,92,126,47,126,119,124,47,126,126,126,126,126,126,126,126,126,34,126,111,126,92,126,47,126,119,124,47,126,126,},
{126,126,126,126,126,126,126,126,126,126,126,126,126,92,92,87,126,126,126,126,126,126,126,126,126,126,126,126,92,124,47,126,126,32,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,92,92,87,126,126,126,126,126,126,126,126,126,126,126,126,92,124,47,126,126,32,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,92,92,87,126,126,126,126,126,126,126,126,126,126,126,126,92,124,},
    };

    for (int i = 0; i < 23; i++) {
        gotoxy(x, y);
        printf("%s",color);
        for (int j = 0; j < 118; j++) {
            if (asciiImage[i][j] != 0)
            printf("%c", asciiImage[i][j]);
        }
        y++;
        printf(s_RESET_ALL);
        printf("\n");
    }
}
/*
    X 118 Y 23
*/
void imgArbolBuho2(int x, int y,char* color){
    int asciiImage[23][118] = {
        {32,47,59,45,46,95,44,45,46,95,95,95,95,32,32,32,32,32,32,32,32,44,45,45,45,45,45,46,95,95,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,},
{40,95,58,35,58,58,95,46,58,58,58,46,32,96,45,46,95,32,32,32,47,58,44,32,47,45,46,95,44,32,96,46,95,44,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,},
{32,32,32,32,92,32,32,32,95,124,96,34,61,58,95,58,58,46,96,46,41,59,32,32,92,32,95,95,47,32,47,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,},
{32,32,32,32,32,32,44,32,32,32,32,96,46,47,32,32,92,58,46,32,96,46,32,32,32,41,61,61,45,39,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,},
{61,45,46,32,32,44,92,44,32,43,35,46,47,96,32,32,32,92,58,46,32,32,47,32,47,32,32,32,32,32,32,32,47,92,32,47,92,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,},
{96,45,39,32,44,32,44,92,32,39,96,32,96,32,96,32,32,32,41,58,32,44,32,47,95,32,32,45,111,32,32,40,40,45,118,45,41,41,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,},
{32,45,32,43,32,43,45,32,58,32,58,45,32,43,32,43,32,45,58,39,32,32,47,40,111,45,41,32,92,41,32,40,41,58,58,58,40,41,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,},
{32,32,32,32,96,32,96,47,96,32,39,32,44,32,44,32,44,58,39,32,96,39,45,45,34,46,45,45,34,45,45,45,45,86,86,86,45,45,45,45,46,95,47,96,55,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,},
{92,44,45,46,95,96,32,96,32,43,32,39,92,44,32,44,34,32,32,32,95,44,45,45,46,95,44,45,45,45,45,45,46,45,45,45,45,45,34,58,46,95,95,47,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,},
{32,32,96,32,32,88,96,32,95,124,32,95,44,92,47,39,32,32,32,46,45,39,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,},
{34,58,46,95,58,96,92,95,95,95,95,32,32,47,58,39,32,32,47,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,},
{32,32,32,32,92,58,58,46,32,32,58,92,47,58,39,32,32,47,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,},
{32,32,32,32,32,96,46,58,46,32,32,47,58,39,32,32,125,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,},
{32,32,32,32,32,32,32,41,58,95,40,58,59,32,32,32,92,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,},
{32,32,32,32,32,32,47,58,46,32,95,47,32,44,32,32,124,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,},
{32,32,32,32,32,40,124,58,58,46,32,32,32,32,32,44,96,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,},
{32,32,32,32,32,32,124,58,58,46,32,32,32,32,123,92,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,},
{32,32,32,32,32,32,124,58,58,46,92,32,32,92,32,96,46,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,},
{32,32,32,32,32,32,124,58,58,58,40,92,32,32,32,32,124,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,},
{32,32,32,32,32,32,124,58,58,58,47,123,32,125,32,32,124,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,40,111,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,79,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,79,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,},
{32,32,95,95,95,47,35,92,58,58,96,47,32,40,79,32,34,61,61,46,95,95,95,95,95,32,32,79,32,44,32,40,32,79,32,47,96,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,41,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,40,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,},
{126,34,126,126,44,92,96,32,96,58,47,44,45,40,126,96,34,126,126,126,126,126,126,126,126,34,126,111,126,92,126,47,126,119,124,47,126,126,126,126,126,126,126,126,126,34,126,111,126,92,126,47,126,119,124,47,126,126,126,126,126,126,126,126,126,34,126,111,126,92,126,47,126,119,124,47,126,126,126,126,126,126,126,126,126,34,126,111,126,92,126,47,126,119,124,47,126,126,126,126,126,126,126,126,126,34,126,111,126,92,126,47,126,119,124,47,126,126,},
{126,126,126,126,126,126,126,126,126,126,126,126,126,92,92,87,126,126,126,126,126,126,126,126,126,126,126,126,92,124,47,126,126,32,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,92,92,87,126,126,126,126,126,126,126,126,126,126,126,126,92,124,47,126,126,32,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,92,92,87,126,126,126,126,126,126,126,126,126,126,126,126,92,124,},
    };

    for (int i = 0; i < 23; i++) {
        gotoxy(x, y);
        printf("%s",color);
        for (int j = 0; j < 118; j++) {
            if (asciiImage[i][j] != 0)
            printf("%c", asciiImage[i][j]);
        }
        y++;
        printf(s_RESET_ALL);
        printf("\n");
    }
}