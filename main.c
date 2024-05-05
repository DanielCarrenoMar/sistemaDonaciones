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

// Fuente https://patorjk.com/software/taag/#p=display&f=Big&t=Garritas%0A
// Paleta de colores
// Resalte f_RED #AB0000
// Secundarios f_BLUE f_LBLUE #0000AC #5354FC
// Principal f_GREEN #00AB00

char input;
int page = 2;

void wait(int time){
    #ifdef _WIN32
        Sleep(time);
    #else
        sleep(time/1000);
    #endif
}

void globalLayer(){
    printf(f_GREEN);
    recuadro(0, 0, 120, 36);
    gotoxy(1,1); printf("Daniel Carreno | Jose Pereira | Juan Salazar");
    printf(s_RESET_ALL);
}

void userInput(int x, int y){
    char num[10];
    gotoxy(x,y);
    printf(f_LRED);

    fgets(num, 10, stdin);
    if (num[0] >= '0' && num[0] <= '9'){
        input = num[0];
    }
    printf(s_RESET_ALL);
}

void startAnimation(){
    imgBuho3(33, 17, f_LBLUE);
    imgPerro3(109, 30, f_LBLUE);
    imgGato2(39, 30, f_LBLUE);
    wait(500);

    imgBuho2(33, 17, f_LBLUE);
    imgPerro2(109, 30, f_LBLUE);
    imgGato3(39, 30, f_LBLUE);
    wait(500);

    imgBuho3(33, 17, f_LBLUE);
    imgPerro3(109, 30, f_LBLUE);
    imgGato2(39, 30, f_LBLUE);
    wait(500);

}

void transition(){
    for (int i = 0; i<=18; i++){
        cuadrado(0, i, 121, 1, ' ');
        cuadrado(0, 36-i, 121, 1, ' ');
        wait(10);
    }
}

void menu_main(){
    static int firtsTime = 1;
    if (firtsTime){
        imgArbolFondoMain(2, 13, f_LGREEN);
        imgBuho1(33, 17, f_LBLUE);
        imgPerro1(109, 30, f_LBLUE);
        imgGato1(39, 30, f_LBLUE);
        printf(f_LBLUE);
        gotoxy(58,10); printf("Apoya nuestra causa de proteger, restaurar y promover");
        gotoxy(58,11); printf("el uso sostenible de los ecosistemas terrestres, gestionar");
        gotoxy(58,12); printf("los bosques de manera sostenible, luchar contra");
        gotoxy(58,13); printf("la desertificacion, detener e invertir la degradacion");
        gotoxy(58,14); printf("de las tierras y la perdida de biodiversidad" s_RESET_ALL);
        firtsTime = 0;
    }
    imgTextGarritas(62, 2, f_LBLUE);

    printf(f_LRED);
    gotoxy(58, 18); printf("1. Iniciar");
    gotoxy(58, 19); printf("0. Salir");
    gotoxy(77, 18); printf("->");
    printf(s_RESET_ALL);

    cuadrado(80, 18, 40, 2, ' ');
    userInput(80,18);
    
    if(input == '1'){
        transition();
        page = 1;
    }
}

void menu_login(){
    static int firtsTime = 1;
    if (firtsTime){
        borrarPantalla();
        globalLayer();
        firtsTime = 0;
    }
    imgTextLogin(45, 2, f_LBLUE);

    printf(f_LRED);
    gotoxy(55, 11); printf("1. Nombre");
    gotoxy(55, 17); printf("2. Cedula");
    gotoxy(55, 23); printf("3. Registarse");
    gotoxy(55, 25); printf("0. Salir");
    printf(f_LGREEN);
    recuadro(40, 12, 40, 3);
    recuadro(40, 18, 40, 3);
    printf(s_RESET_ALL);

    printf(f_LRED);
    gotoxy(52, 27); printf("->");
    printf(s_RESET_ALL);

    userInput(55,27);
    cuadrado(52, 27, 40, 2, ' ');
    
    char num[20];
    if(input == '1'){
        printf(f_LRED);
        gotoxy(41, 13); printf("->");
        printf(f_LBLUE);
        gotoxy(43, 13); fgets(num, 20, stdin);
        gotoxy(41, 13); printf("  ");
        printf(s_RESET_ALL);
        input = 'n';
    }
    if(input == '2'){
        printf(f_LRED);
        gotoxy(41, 19); printf("->");
        printf(f_LBLUE);
        gotoxy(43, 19); fgets(num, 20, stdin);
        gotoxy(41, 19); printf("  ");
        printf(s_RESET_ALL);
        input = 'n';
    }
    if(input == '3'){
        transition();
        page = 2;
    }
}

void menu_register(){
    static int firtsTime = 1;
    if (firtsTime){
        borrarPantalla();
        globalLayer();
        firtsTime = 0;
    }
    imgTextGarritas(62, 2, f_LBLUE);

    printf(f_LRED);
    gotoxy(58, 18); printf("1. Iniciar");
    gotoxy(58, 19); printf("0. Salir");
    gotoxy(77, 18); printf("->");
    printf(s_RESET_ALL);

    cuadrado(80, 18, 40, 2, ' ');
    userInput(80,18);
    
    if(input == '1'){
        page = 2;
    }
}

void menu_makeDonation(){
        static int firtsTime = 1;
    if (firtsTime){
        borrarPantalla();
        globalLayer();
        firtsTime = 0;
    }
    imgTextGarritas(62, 2, f_LBLUE);

    printf(f_LRED);
    gotoxy(58, 18); printf("1. Iniciar");
    gotoxy(58, 19); printf("0. Salir");
    gotoxy(77, 18); printf("->");
    printf(s_RESET_ALL);

    cuadrado(80, 18, 40, 2, ' ');
    userInput(80,18);
    
    if(input == '1'){
        page = 2;
    }
}

void menu_myDonations(){
        static int firtsTime = 1;
    if (firtsTime){
        borrarPantalla();
        globalLayer();
        firtsTime = 0;
    }
    imgTextGarritas(62, 2, f_LBLUE);

    printf(f_LRED);
    gotoxy(58, 18); printf("1. Iniciar");
    gotoxy(58, 19); printf("0. Salir");
    gotoxy(77, 18); printf("->");
    printf(s_RESET_ALL);

    cuadrado(80, 18, 40, 2, ' ');
    userInput(80,18);
    
    if(input == '1'){
        page = 2;
    }
}

void menu_listDonations(){
        static int firtsTime = 1;
    if (firtsTime){
        borrarPantalla();
        globalLayer();
        firtsTime = 0;
    }
    imgTextGarritas(62, 2, f_LBLUE);

    printf(f_LRED);
    gotoxy(58, 18); printf("1. Iniciar");
    gotoxy(58, 19); printf("0. Salir");
    gotoxy(77, 18); printf("->");
    printf(s_RESET_ALL);

    cuadrado(80, 18, 40, 2, ' ');
    userInput(80,18);
    
    if(input == '1'){
        page = 2;
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

    ocultarCursor();
    borrarPantalla();
    globalLayer();

    imgArbolFondoMain(2, 13, f_LGREEN);
    //startAnimation();
    while (1)
    {   

        if (page == 0) menu_main();
        if (page == 1) menu_login();
        if (page == 2) menu_register();
        if (page == 3) menu_makeDonation();
        if (page == 4) menu_myDonations();
        if (page == 5) menu_listDonations();

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