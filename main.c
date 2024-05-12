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

// Fuente Grande https://patorjk.com/software/taag/#p=display&f=Big&t=Garritas%0A
// Fuente Pequeña https://patorjk.com/software/taag/#p=display&f=Small&t=Inicio%0A
// Paleta de colores
// Resalte f_RED #AB0000
// Secundarios f_BLUE f_LBLUE #0000AC #5354FC
// Principal f_GREEN #00AB00

char inputMenu;
int pageIndex = 7;

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
    imgOwl3(33, 17, f_LBLUE);
    imgDog3(109, 30, f_LBLUE);
    imgCat2(39, 30, f_LBLUE);
    wait(500);

    imgOwl2(33, 17, f_LBLUE);
    imgDog2(109, 30, f_LBLUE);
    imgCat3(39, 30, f_LBLUE);
    wait(500);

    imgOwl3(33, 17, f_LBLUE);
    imgDog3(109, 30, f_LBLUE);
    imgCat2(39, 30, f_LBLUE);
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
        imgTreeMain1(2, 13, f_LGREEN);
        imgOwl1(33, 17, f_LBLUE);
        imgDog1(109, 30, f_LBLUE);
        imgCat1(39, 30, f_LBLUE);
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
    gotoxy(58, 18); printf(f_LRED); printf("1."); printf(f_LBLUE); printf(" Iniciar");
    gotoxy(58, 19); printf(f_LRED); printf("0."); printf(f_LBLUE); printf(" Salir");
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
        gotoxy(55, 17); printf(f_LRED); printf("2."); printf(f_LBLUE); printf(" Cedula");
        gotoxy(55, 23); printf(f_LRED); printf("3."); printf(f_LBLUE); printf(" Registarse");
        gotoxy(55, 25); printf(f_LRED); printf("4."); printf(f_LRED); printf(" INICIAR");
        gotoxy(55, 27); printf(f_LRED); printf("0."); printf(f_LBLUE); printf(" Salir");
        imgTextInicio(46, 2, f_LBLUE);
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
        firtsTime = 1;
        pageIndex = 3;
    }
}

void layer_register(User_t* actualUser){
    static int firtsTime = 1;
    if (firtsTime){
        borrarPantalla();
        layer_global();

        printf(f_LRED);
        gotoxy(14, 11); printf(f_LRED); printf("1."); printf(f_LBLUE); printf(" Nombre");
        gotoxy(14, 17); printf(f_LRED); printf("2."); printf(f_LBLUE); printf(" Cedula");
        gotoxy(69, 11); printf(f_LRED); printf("3."); printf(f_LBLUE); printf(" Telefono");
        gotoxy(69, 17); printf(f_LRED); printf("4."); printf(f_LBLUE); printf(" Direccion");
        gotoxy(55, 23); printf(f_LRED); printf("5."); printf(f_LBLUE); printf(" Login");
        gotoxy(55, 25); printf(f_LRED); printf("6."); printf(f_LRED); printf(" INICIAR");
        gotoxy(55, 27); printf(f_LRED); printf("0."); printf(f_LBLUE); printf(" Salir");
        imgTextRegistro(41, 2, f_LBLUE);
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
        imgLine(35, 33, f_LGREEN);
        imgLine(56, 33, f_LGREEN);
        imgLine(77, 33, f_LGREEN);
        printf(f_LRED);
        gotoxy(41, 12); printf("1.");
        gotoxy(41, 17); printf("2.");
        gotoxy(41, 22); printf("3.");
        gotoxy(41, 27); printf("0. Salir");
        imgTextDonacion(45,10, f_LBLUE);
        imgTextVerDonaciones(46,15, f_LBLUE);
        imgTextMisDonaciones(47,20, f_LBLUE);
        imgTextGarritas(62, 2, f_LBLUE);
        imgBear(99, 24, f_LGREEN);
        imgCave(1, 17, f_LGREEN);
        firtsTime = 0;
    }

    userInputMenu(41,32);
    cuadrado(37, 32, 40, 2, ' ');
    
    if(inputMenu == '1'){
        transition();
        firtsTime = 1;
        pageIndex = 4;
    }else if(inputMenu == '2'){
        transition();
        firtsTime = 1;
        pageIndex = 6;
    }else if(inputMenu == '3'){
        transition();
        firtsTime = 1;
        pageIndex = 7;
    }
}

void layer_makeDonation(){
        static int firtsTime = 1;
    if (firtsTime){
        borrarPantalla();
        layer_global();
        imgTextDonacion(54,1, f_LBLUE);
        firtsTime = 0;
    }

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

void layer_thanksDonation(){
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

void layer_myDonations(User_t user, nodeDonation_t* headDonations){
        static int firtsTime = 1;
    if (firtsTime){
        borrarPantalla();
        layer_global();
        int percent = 0;
        int count = 0;

        headDonations = headDonations->next;
        while (headDonations){
            if (strcmp(headDonations->donation.cedula, user.cedula) == 0){
                if (percent <= 4) {
                    imgCard(79, 5 + 6*percent, f_LGREEN);
                    printf(f_LBLUE);
                    gotoxy(80, 6 + 6*percent); printf("%s", headDonations->donation.tipo);
                    printf(f_LGREEN);
                    gotoxy(87, 7 + 6*percent); printf("%s", headDonations->donation.valor);
                    gotoxy(88, 8 + 6*percent); printf("%s", headDonations->donation.cedula);
                    gotoxy(87, 9 + 6*percent); printf("%s", headDonations->donation.fecha);
                    printf(f_LRED);
                    gotoxy(76, 8 + 6*percent); printf("%d.", percent+1);
                }
                percent++;
            }
            count++;
            headDonations = headDonations->next;
        }
        percent = (percent * 100) / count;

        imgTextMisDonaciones(55,1, f_LBLUE);
        printf(f_LBLUE);
        gotoxy(22, 6); printf("USUARIO");
        gotoxy(20, 13); printf("Estadisticas");
        gotoxy(37, 15); printf("%d%%", percent);
        printf(f_LGREEN);
        gotoxy(12, 8); printf("- %s", user.nombre);
        gotoxy(28, 8); printf("- %s", user.cedula);
        gotoxy(12, 10); printf("- %s", user.telefono);
        gotoxy(28, 10); printf("- %s", user.direccion);
        gotoxy(12, 15); printf("Porcentaje de donaciones");
        printf(f_LRED);
        gotoxy(47, 14); printf(f_LRED); printf("6."); printf(f_LBLUE); printf(" Regresar");
        gotoxy(47, 16); printf(f_LRED); printf("0."); printf(f_LBLUE); printf(" Salir");

        printf(f_LGREEN);
        graficaPastel(25, 25, 16, 8, '*', f_LBLUE, percent);
        firtsTime = 0;
    }

    userInputMenu(50,12);
    cuadrado(50, 12, 29, 2, ' ');
    
    if(inputMenu == '1'){
        transition();
        firtsTime = 1;
        pageIndex = 8;
    }else if (inputMenu == '6'){
        transition();
        firtsTime = 1;
        pageIndex = 3;
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

void layer_infoDonation(){
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

    int numUsersList = countLines("./data/USERS.txt");
    int numDonationsList = countLines("./data/DONATIONS.txt");
    User_t** UsersList = (User_t**)malloc(numUsersList * sizeof(User_t*));
    nodeDonation_t* headDonations = (nodeDonation_t*)malloc(sizeof(nodeDonation_t));
    headDonations->next = NULL;

    if (numUsersList != 0){
        loadUsers(UsersList, "./data/USERS.txt");
        //verUsers(UsersList);
    }
    if (numDonationsList != 0){
        loadDonations(headDonations, "./data/DONATIONS.txt");
    }

    User_t* actualUser = (User_t*)malloc(sizeof(User_t));
    strcpy(actualUser->nombre, "Daniel");
    strcpy(actualUser->cedula, "cedulaD");
    strcpy(actualUser->telefono, "telefonoD");
    strcpy(actualUser->direccion, "direccionD");

    need_t needList[5] = {
        {'a', "Reforestacion", "Reforestacion de arboles nativos", 100},
        {'b', "Proteccion", "Proteccion de animales en peligro de extincion", 100},
        {'c', "Juguetes", "Juguetes para los animales", 10},
        {'d', "Comida de animales", "Comprar comida para cada animal", 150},
        {'e', "Casas para perro", "Comprar casas para los perros", 100}
    };

    
    ocultarCursor();
    borrarPantalla();
    layer_global();

    imgTreeMain1(2, 13, f_LGREEN);
    //startAnimation();
    while (1)
    {   

        if (pageIndex == 0) layer_main();
        if (pageIndex == 1) layer_login(actualUser);
        if (pageIndex == 2) layer_register(actualUser);
        if (pageIndex == 3) layer_options();
        if (pageIndex == 4) layer_makeDonation();
        if (pageIndex == 5) layer_thanksDonation();
        if (pageIndex == 6) layer_listDonations();
        if (pageIndex == 7) layer_myDonations(*actualUser, headDonations);
        if (pageIndex == 8) layer_infoDonation();

        if (inputMenu == '0'){
            break;
        }
    }

    printf(s_RESET_ALL);
    mostrarCursor();
    borrarPantalla();
    saveDonation(headDonations, "./data/DONATIONS.txt");
    free(actualUser);
    freeLinkedDonations(&headDonations);
    freeUsers(UsersList);
    return 0;
}