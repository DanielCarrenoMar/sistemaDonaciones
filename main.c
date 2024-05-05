#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef _WIN32
#include <unistd.h>
#endif

#include "./library/txtHandler.h"
#include "./library/colorama.h"
#include "./library/graficos.h"
#include "./library/screens.h"

// Fuente https://patorjk.com/software/taag/#p=testall&f=Big%20Money-se&t=Donaciones%0A
// Paleta de colores
// Resalte f_RED #AB0000
// Secundarios f_BLUE f_LBLUE #0000AC #5354FC
// Principal f_GREEN #00AB00

char input;
int page = 0;

void wait(int time){
    #ifdef _WIN32
        Sleep(time);
    #else
        sleep(time/1000);
    #endif
}

void userInput(int x, int y){
    char* error;
    char num[10];
    gotoxy(x,y);
    printf(f_LRED);

    fgets(num, 10, stdin);
    if (error != NULL && num[0] >= '0' && num[0] <= '9'){
        input = num[0];
    }
    printf(s_RESET_ALL);
}

void startAnimation(){
    imgBuho3(33, 17, f_LBLUE);
    wait(500);

    imgBuho2(33, 17, f_LBLUE);
    wait(500);

    imgBuho3(33, 17, f_LBLUE);
    wait(500);

}

void menu_main(){
    static int firtsTime = 1;
    if (firtsTime){
        imgArbolFondoMain(2, 13, f_LGREEN);
        imgBuho1(33, 17, f_LBLUE);
        printf(f_LBLUE);
        gotoxy(58,10); printf("Apoya nuestra causa de proteger, restaurar y promover");
        gotoxy(58,11); printf("el uso sostenible de los ecosistemas terrestres, gestionar");
        gotoxy(58,12); printf("los bosques de manera sostenible, luchar contra");
        gotoxy(58,13); printf("la desertificacion, detener e invertir la degradacion");
        gotoxy(58,14); printf("de las tierras y la perdida de biodiversidad" s_RESET_ALL);
        firtsTime = 0;
    }
    imgTextPrincipal(62, 2, f_LBLUE);

    printf(f_LRED);
    gotoxy(58, 18); printf("1. Iniciar");
    gotoxy(58, 19); printf("0. Salir");
    gotoxy(77, 18); printf("->");
    printf(s_RESET_ALL);

    cuadrado(80, 18, 40, 2, ' ');
    userInput(80,18);
    
    if(input == '1'){
        page = 1;
    }
}

void menu_login(){
    userInput(58,25);
    if(input != '0'){
        page = 1;
    }
}

void menu_makeDonation(){
    userInput(58,25);
    if(input != '0'){
        page = 1;
    }
}

void menu_myDonations(){
    userInput(58,25);
    if(input != '0'){
        page = 1;
    }
}

void menu_listDonations(){
    userInput(58,25);
    if(input != '0'){
        page = 1;
    }
}

int main (){
    just_fix_windows_console();

    makeTXT("./data/DONATIONS.txt");
    makeTXT("./data/USERS.txt");
    int numDonationsList = countLines("./data/DONATIONS.txt");
    int numUsersList = countLines("./data/USERS.txt");
    Donation_t** DonationList = (Donation_t**)malloc(numDonationsList * sizeof(Donation_t*));
    User_t** UsersList = (User_t**)malloc(numUsersList * sizeof(User_t*));
    if (numDonationsList != 0 || numUsersList != 0){
        cargarDonations(DonationList, "./data/DONATIONS.txt");
        cargarUsers(UsersList, "./data/USERS.txt");

        verDonations(DonationList);
        verUsers(UsersList);
    }

    int select = 0;
    ocultarCursor();
    borrarPantalla();
    printf(f_GREEN);
    recuadro(0, 0, 120, 36);
    gotoxy(1,1); printf("Daniel Carreno | Jose Pereira | Juan Roma");
    printf(s_RESET_ALL);
    imgArbolFondoMain(2, 13, f_LGREEN);
    //startAnimation();
    while (1)
    {   

        if (page == 0) menu_main();
        if (page == 1) menu_login();

        if (input == '0'){
            break;
        }
    }

    freeDonation(DonationList);
    freeUsers(UsersList);
    printf(s_RESET_ALL);
    mostrarCursor();
    borrarPantalla();
    return 0;
}