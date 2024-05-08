#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef _WIN32
#include <unistd.h>
#endif

#include "./library/txtHandler.h"
#include "./library/colorama.h"
#include "./library/graficos.h"
#include "./library/imgAscii.h"
#include "./library/linkedDonations.h"

// Fuente https://patorjk.com/software/taag/#p=display&f=Big&t=Garritas%0A
// Paleta de colores
// Resalte f_RED #AB0000
// Secundarios f_BLUE f_LBLUE #0000AC #5354FC
// Principal f_GREEN #00AB00

char inputMenu;
int pageIndex = 0;

void wait(int time){
    #ifdef _WIN32
        Sleep(time);
    #else
        char buffer[50];
        sprintf(buffer, "sleep %f", time/1000.0);
        system(buffer);
    #endif
}

void layer_global(){
    printf(f_GREEN);
    recuadro(0, 0, 120, 36);
    gotoxy(1,1); printf("Daniel Carreno | Jose Pereira | Juan Salazar");
    printf(s_RESET_ALL);
}

void userInputMenu(int x, int y){
    char num[10];
    printf(f_LRED);
    gotoxy(x-3, y); printf("->");
    printf(f_LBLUE);
    gotoxy(x,y);
    fgets(num, 10, stdin);
    if (num[0] >= '0' && num[0] <= '9'){
        inputMenu = num[0];
    }
    printf(s_RESET_ALL);
}

void userInputStr(int x, int y, char* buffer){
    printf(f_LRED);
    gotoxy(x, y); printf("->");
    printf(f_LBLUE);
    gotoxy(x+2, y); fgets(buffer, 20, stdin);
    gotoxy(x, y); printf("  ");
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

void layer_main(){
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
    printf(s_RESET_ALL);

    userInputMenu(80,18);
    cuadrado(80, 18, 40, 2, ' ');
    
    if(inputMenu == '1'){
        transition();
        pageIndex = 1;
    }
}

void layer_login(User_t* actualUser){
    static int firtsTime = 1;
    if (firtsTime){
        borrarPantalla();
        layer_global();
        
        gotoxy(55, 11); printf(f_LRED); printf("1."); printf(f_LBLUE); printf(" Nombre");
        gotoxy(55, 17); printf(f_LRED); printf("2. Cedula");
        gotoxy(55, 23); printf("3. Registarse");
        gotoxy(55, 25); printf("4. INICIAR");
        gotoxy(55, 27); printf("0. Salir");
        printf(f_LGREEN);
        gotoxy(53, 25); printf("~");
        gotoxy(66, 25); printf("~");
        imgTextLogin(45, 2, f_LBLUE);
        firtsTime = 0;
    }

    printf(f_LGREEN);
    recuadro(40, 12, 40, 3);
    recuadro(40, 18, 40, 3);
    printf(s_RESET_ALL);

    userInputMenu(55,29);
    cuadrado(52, 29, 40, 2, ' ');
    
    char nombre[20];
    char cedula[20];
    if(inputMenu == '1'){
        userInputStr(41,13, nombre);
        inputMenu = 'n';
    }
    if(inputMenu == '2'){
        userInputStr(41,19, cedula);
        inputMenu = 'n';
    }
    if(inputMenu == '3'){
        transition();
        pageIndex = 2;
        firtsTime = 1;
    }
    if(inputMenu == '4'){
        transition();
        pageIndex = 3;
        firtsTime = 1;
    }
}

void layer_register(User_t* actualUser){
    static int firtsTime = 1;
    if (firtsTime){
        borrarPantalla();
        layer_global();

        printf(f_LRED);
        gotoxy(14, 11); printf("1. Nombre");
        gotoxy(14, 17); printf("2. Cedula");
        gotoxy(69, 11); printf("3. Telefono");
        gotoxy(69, 17); printf("4. Direccion");
        gotoxy(55, 23); printf("5. Login");
        gotoxy(55, 25); printf("6. INICIAR");
        gotoxy(55, 27); printf("0. Salir");
        printf(f_LGREEN);
        gotoxy(53, 25); printf("~");
        gotoxy(66, 25); printf("~");
        imgTextRegister(40, 2, f_LBLUE);
        firtsTime = 0;
    }
    printf(f_LGREEN);
    recuadro(13, 12, 40, 3);
    recuadro(13, 18, 40, 3);
    recuadro(68, 12, 40, 3);
    recuadro(68, 18, 40, 3);
    printf(s_RESET_ALL);

    userInputMenu(55,29);
    cuadrado(52, 29, 40, 2, ' ');
    
    if(inputMenu == '1'){
        userInputStr(14,13, actualUser->nombre);
        inputMenu = 'n';
    }
    if(inputMenu == '2'){
        userInputStr(14,19, actualUser->cedula);
        inputMenu = 'n';
    }
    if(inputMenu == '3'){
        userInputStr(69,13, actualUser->telefono);
        inputMenu = 'n';
    }
    if(inputMenu == '4'){
        userInputStr(69,19, actualUser->direccion);
        inputMenu = 'n';
    }
    if(inputMenu == '5'){
        transition();
        pageIndex = 1;
        firtsTime = 1;
    }
    if(inputMenu == '6'){
        if(strlen(actualUser->nombre) != 0 && strlen(actualUser->cedula) != 0 && strlen(actualUser->telefono) != 0 && strlen(actualUser->direccion) != 0){
            transition();
            saveUser(actualUser, "./data/USERS.txt");
            pageIndex = 3;
            firtsTime = 1;
        }
    }
}

void layer_options(){
    static int firtsTime = 1;
    if (firtsTime){
        borrarPantalla();
        layer_global();
        firtsTime = 0;
    }
    imgTextGarritas(62, 2, f_LBLUE);

    printf(f_LRED);
    gotoxy(58, 18); printf("1. Hacer Donacion");
    gotoxy(58, 19); printf("0. Salir");
    gotoxy(77, 18); printf("->");
    printf(s_RESET_ALL);

    userInputMenu(55,29);
    cuadrado(52, 29, 40, 2, ' ');
    
    if(inputMenu == '1'){
        pageIndex = 2;
    }
}

void layer_makeDonation(){
        static int firtsTime = 1;
    if (firtsTime){
        borrarPantalla();
        layer_global();
        firtsTime = 0;
    }
    imgTextGarritas(62, 2, f_LBLUE);

    printf(f_LRED);
    gotoxy(58, 18); printf("1. Iniciar");
    gotoxy(58, 19); printf("0. Salir");
    gotoxy(77, 18); printf("->");
    printf(s_RESET_ALL);

    cuadrado(80, 18, 40, 2, ' ');
    userInputMenu(80,18);
    
    if(inputMenu == '1'){
        pageIndex = 2;
    }
}

void layer_myDonations(){
        static int firtsTime = 1;
    if (firtsTime){
        borrarPantalla();
        layer_global();
        firtsTime = 0;
    }
    imgTextGarritas(62, 2, f_LBLUE);

    printf(f_LRED);
    gotoxy(58, 18); printf("1. Iniciar");
    gotoxy(58, 19); printf("0. Salir");
    gotoxy(77, 18); printf("->");
    printf(s_RESET_ALL);

    cuadrado(80, 18, 40, 2, ' ');
    userInputMenu(80,18);
    
    if(inputMenu == '1'){
        pageIndex = 2;
    }
}

void layer_listDonations(){
        static int firtsTime = 1;
    if (firtsTime){
        borrarPantalla();
        layer_global();
        firtsTime = 0;
    }
    imgTextGarritas(62, 2, f_LBLUE);

    printf(f_LRED);
    gotoxy(58, 18); printf("1. Iniciar");
    gotoxy(58, 19); printf("0. Salir");
    gotoxy(77, 18); printf("->");
    printf(s_RESET_ALL);

    cuadrado(80, 18, 40, 2, ' ');
    userInputMenu(80,18);
    
    if(inputMenu == '1'){
        pageIndex = 2;
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
        cargarDonations(DonationList, "./data/DONATIONS.txt"); // Convertir a lista enlazada
        cargarUsers(UsersList, "./data/USERS.txt");

        verDonations(DonationList);
        verUsers(UsersList);
    }

    User_t* actualUser = (User_t*)malloc(sizeof(User_t));
    strcpy(actualUser->nombre, "");
    strcpy(actualUser->cedula, "");
    strcpy(actualUser->telefono, "");
    strcpy(actualUser->direccion, "");

    // PRUEBA DE LISTAS ENLAZADAS

    nodeDonation_t* headActualDonations = malloc(sizeof(nodeDonation_t));
    Donation_t dona = {"nombre1","2","3","4"};
    addNodeDonationStart(headActualDonations, dona);
    Donation_t dona2 = {"nombre2","2","3","4"};
    addNodeDonationStart(headActualDonations, dona2);
    Donation_t dona3 = {"nombre3","2","3","4"};
    addNodeDonationStart(headActualDonations, dona3);

    Donation_t dona4 = {"Alrevez4","2","3","4"};
    addNodeDonationEnd(headActualDonations, dona4);
    
    printNodesDonations(headActualDonations);

    freeLinkedDonations(&headActualDonations);
    free(headActualDonations);

    /*
    ocultarCursor();
    borrarPantalla();
    layer_global();

    imgArbolFondoMain(2, 13, f_LGREEN);
    startAnimation();
    while (1)
    {   

        if (pageIndex == 0) layer_main();
        if (pageIndex == 1) layer_login(actualUser);
        if (pageIndex == 2) layer_register(actualUser);
        if (pageIndex == 3) layer_options();
        if (pageIndex == 4) layer_makeDonation();
        if (pageIndex == 5) layer_myDonations();
        if (pageIndex == 6) layer_listDonations();

        if (inputMenu == '0'){
            break;
        }
    }

    printf(s_RESET_ALL);
    mostrarCursor();
    borrarPantalla();*/
    free(actualUser);
    freeDonation(DonationList);
    freeUsers(UsersList);
    return 0;
}