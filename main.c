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

// Paleta de colores
// Resalte f_RED #AB0000
// Secundarios f_BLUE f_LBLUE #0000AC #5354FC
// Principal f_GREEN #00AB00

char input;
int page = 0;

void wait(int time){
    #ifdef _WIN32
        Sleep(time*1000);
    #else
        sleep(time);
    #endif
}

void userInput(){
    char* error;
    char num[10];

    fgets(num, 10, stdin);
    if (error != NULL && num[0] >= '0' && num[0] <= '9'){
        input = num[0];
    }
}

void startAnimation(){
    for (int i = 0; i < 3; i++){
        borrarPantalla();
        printf(f_GREEN);
        recuadro(0, 0, 120, 36);
        printf(s_RESET_ALL);
        
        imgArbolBuho1(2, 13, f_LGREEN);
        wait(2);
        imgArbolBuho2(2, 13, f_LGREEN); 
        wait(1);
    }
}

void menu_main(){
    imgTextPrincipal(2, 2, f_LMAGENTA);
    gotoxy(1,12); printf(f_LBLUE "Secundario Azul" s_RESET_ALL);

    imgArbolBuho1(2, 13, f_LGREEN);

    gotoxy(19,30);
    userInput();
    if(input == '1'){
        page = 1;
    }
}

void menu_login(){
    gotoxy(19,30);
    userInput();
    if(input != '0'){
        page = 1;
    }
}

void menu_makeDonation(){
    gotoxy(19,30);
    userInput();
    if(input != '0'){
        page = 1;
    }
}

void menu_myDonations(){
    gotoxy(19,30);
    userInput();
    if(input != '0'){
        page = 1;
    }
}

void menu_listDonations(){
    gotoxy(19,30);
    userInput();
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

    startAnimation();
    while (1)
    {   
        borrarPantalla();
        printf(f_GREEN);
        recuadro(0, 0, 120, 36);
        printf(s_RESET_ALL);

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