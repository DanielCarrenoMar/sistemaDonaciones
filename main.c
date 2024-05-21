#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "./library/txtHandler.h"
#include "./library/colorama.h"
#include "./library/graficos.h"
#include "./library/imgAscii.h"
#include "./library/linkedDonations.h"

// Para correr el programa en linux se debe añadir "-lm" sin comillas al final
// Fuente Grande https://patorjk.com/software/taag/#p=display&f=Big&t=Garritas%0A
// Fuente Pequeña https://patorjk.com/software/taag/#p=display&f=Small&t=Inicio%0A
// Paleta de colores
// Resalte f_RED #AB0000
// Secundarios f_BLUE f_LBLUE #0000AC #5354FC
// Principal f_GREEN #00AB00

char inputMenu;
int lastPageIndex = 0;
int pageIndex = 0;
int cardIndex = 0;

int strIsNumber(char* str){
    int isNumber = 1;
    for (int i = 0; i < strlen(str); i++){
        if(str[i] < '0' || '9' < str[i]) {
            isNumber = 0;
            break;
        }
    }
    return isNumber;
}
/*
    Imprime en la posicion x y las donacion en tarjetas por paginas. 
    Retorna -1 si la pagina siguiente pagina esta vacia
*/
int printCardDonationPage(int x, int y, NodeDonation* headDonations, int amount, int page, char* id){
    int count = 0;
    int none = -1;
    while (headDonations->next){
        headDonations = headDonations->next;
        if (id && strcmp(id, headDonations->donation.cedula) != 0) continue;
        if (count < amount * page){
            count++;
            continue;
        }
        if (count >= amount * page+ amount){
            none = 0;
            break;
        }

        int i = count - (amount * page);
        imgCard(x, y + 6*i, f_LGREEN);
        printf(f_LBLUE);
        gotoxy(x+1, y+1 + 6*i);
        if (headDonations->donation.tipo == 0) printf("Monetaria");
        else if (headDonations->donation.tipo == 1) printf("Material");
        else if (headDonations->donation.tipo == 2) printf("Voluntariado");
        printf(f_LGREEN);
        gotoxy(x+1, y+2 + 6*i);
        if (headDonations->donation.tipo == 0) printf("Valor: ");
        else if (headDonations->donation.tipo == 1) printf("Cantidad:");
        else if (headDonations->donation.tipo == 2) printf("Horas: ");
        printf("%s", headDonations->donation.valor);
        gotoxy(x+6, y+3 + 6*i); printf("%s", headDonations->donation.cedula);
        gotoxy(x+8, y+4 + 6*i); printf("%s", headDonations->donation.fecha);
        printf(f_LRED);
        gotoxy(x-3, y+3 + 6*i); printf("%d.", i+2);
        none = i+1;

        count++;
    }
    printf(s_RESET_ALL);
    return none;
}
User* findUserID(User** UsersList, int numUsersList, char* cedula){
    for (int i = 0; i < numUsersList-1; i++){
        if (strcmp(UsersList[i]->cedula, cedula) == 0){
            return UsersList[i];
        }
    }
    return NULL;
}
User* findUserName(User** UsersList, int numUsersList, char* name){
    for (int i = 0; i < numUsersList-1; i++){
        if (strcmp(UsersList[i]->nombre, name) == 0){
            return UsersList[i];
        }
    }
    return NULL;
}
void actualTime(char* buffer){
    time_t fechactual;
    time(&fechactual);
    int dia=localtime(&fechactual)->tm_mday;
    int mes=localtime(&fechactual)->tm_mon + 1;
    int año=localtime(&fechactual)->tm_year + 1900;
    sprintf(buffer, "%02d/%02d/%d", dia, mes, año);
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
    fseek(stdin, 0, SEEK_END);
}

void userInputStr(int x, int y, char* buffer){
    printf(f_LRED);
    gotoxy(x, y); printf("->");
    printf(f_LBLUE);
    gotoxy(x+2, y); fgets(buffer, 40, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    gotoxy(x, y); printf("  ");
    printf(s_RESET_ALL);
    fseek(stdin, 0, SEEK_END);
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
    inputMenu = 'n';
    for (int i = 0; i<=18; i++){
        cuadrado(0, i, 121, 1, ' ');
        cuadrado(0, 36-i, 121, 1, ' ');
        wait(10);
    }
}

void layer_main(){
    static int firstTime = 1;
    if (firstTime){
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
        firstTime = 0;
    }
    imgTextGarritas(62, 2, f_LBLUE);

    printf(f_LRED);
    gotoxy(58, 18); printf(f_LRED); printf("1."); printf(f_LBLUE); printf(" Iniciar");
    gotoxy(58, 19); printf(f_LRED); printf("0."); printf(f_LBLUE); printf(" Salir del programa");
    printf(s_RESET_ALL);

    userInputMenu(80,18);
    cuadrado(80, 18, 40, 2, ' ');
    
    if(inputMenu == '1'){
        transition();
        pageIndex = 1;
    }
}

void layer_login(User* actualUser, User** UsersList,int numUsersList){
    static int firstTime = 1;
    if (firstTime){
        borrarPantalla();
        layer_global();
        
        gotoxy(55, 11); printf(f_LRED); printf("1."); printf(f_LBLUE); printf(" Nombre");
        gotoxy(55, 17); printf(f_LRED); printf("2."); printf(f_LBLUE); printf(" Cedula");
        gotoxy(55, 23); printf(f_LRED); printf("3."); printf(f_LBLUE); printf(" Registro de usuario");
        gotoxy(55, 25); printf(f_LRED); printf("4."); printf(f_LRED); printf(" INICIAR");
        gotoxy(55, 27); printf(f_LRED); printf("0."); printf(f_LBLUE); printf(" Salir del programa");
        imgTextInicio(46, 2, f_LBLUE);
        firstTime = 0;
    }

    printf(f_LGREEN);
    recuadro(40, 12, 40, 3);
    recuadro(40, 18, 40, 3);
    printf(s_RESET_ALL);

    userInputMenu(55,29);
    cuadrado(52, 29, 40, 2, ' ');
    
    char nombre[20];
    char cedula[40];

    if(inputMenu == '1'){
        cuadrado(41, 13, 39, 2, ' ');
        userInputStr(41,13, nombre);
        formatingText(nombre);
        inputMenu = 'n';
    }
    if(inputMenu == '2'){
        cuadrado(41, 19, 39, 2, ' ');
        userInputStr(41,19, cedula);
        if (strIsNumber(cedula) == 0){
            gotoxy(41,19); printf(f_LRED); printf("Ingresar un Numero");
            cedula[0] = 0;
        }
        inputMenu = 'n';
    }
    if(inputMenu == '3'){
        transition();
        pageIndex = 2;
        firstTime = 1;
        cedula[0] = '\0';
        nombre[0] = '\0';
    }
    if(inputMenu == '4'){
        if (strlen(nombre) > 1 && strlen(cedula) > 1){
            User* userId = findUserID(UsersList, numUsersList, cedula);
            User* userName = findUserName(UsersList, numUsersList, nombre);
            if((!userId || !userName) || userId != userName){
                printf(f_LRED);
                cuadrado(41, 19, 39, 2, ' ');
                cuadrado(41, 13, 39, 2, ' ');
                gotoxy(57, 29); printf("*Nombre o cedula no existen");
                cedula[0] = '\0';
                nombre[0] = '\0';
                printf(s_RESET_ALL);
            }else if (userId == userName){
                strcpy(actualUser->nombre, userId->nombre);
                strcpy(actualUser->cedula, userId->cedula);
                strcpy(actualUser->telefono, userId->telefono);
                strcpy(actualUser->direccion, userId->direccion);
                transition();
                firstTime = 1;
                pageIndex = 3;
            }
        }else{
            printf(f_LRED);
            gotoxy(57, 29); printf("*Ingrese un nombre y cedula");
            printf(s_RESET_ALL);
        }
    }
}

void layer_register(User* actualUser, User** UsersList, int numUsersList){
    static int firstTime = 1;
    if (firstTime){
        borrarPantalla();
        layer_global();

        printf(f_LRED);
        gotoxy(14, 11); printf(f_LRED); printf("1."); printf(f_LBLUE); printf(" Nombre");
        gotoxy(14, 17); printf(f_LRED); printf("2."); printf(f_LBLUE); printf(" Cedula");
        gotoxy(69, 11); printf(f_LRED); printf("3."); printf(f_LBLUE); printf(" Telefono");
        gotoxy(69, 17); printf(f_LRED); printf("4."); printf(f_LBLUE); printf(" Direccion");
        gotoxy(55, 23); printf(f_LRED); printf("5."); printf(f_LBLUE); printf(" Inicio de sesion");
        gotoxy(55, 25); printf(f_LRED); printf("6."); printf(f_LRED); printf(" INICIAR");
        gotoxy(55, 27); printf(f_LRED); printf("0."); printf(f_LBLUE); printf(" Salir del programa");
        imgTextRegistro(41, 2, f_LBLUE);
        firstTime = 0;
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
        cuadrado(14, 13, 39, 2, ' ');
        userInputStr(14,13, actualUser->nombre);
        if (findUserName(UsersList, numUsersList, actualUser->nombre) != NULL){
            gotoxy(14,13); printf(f_LRED); printf("Nombre ocupado");
            actualUser->nombre[0] = 0;
        }
        inputMenu = 'n';
    }
    if(inputMenu == '2'){
        cuadrado(14, 19, 39, 2, ' ');
        userInputStr(14,19, actualUser->cedula);
        if (strIsNumber(actualUser->cedula) == 0){
            gotoxy(14,19); printf(f_LRED); printf("Ingresar un Numero");
            actualUser->cedula[0] = 0;
        }
        if (findUserID(UsersList, numUsersList, actualUser->cedula) != NULL){
            gotoxy(14,19); printf(f_LRED); printf("Cedula ocupada");
            actualUser->cedula[0] = 0;
        }
        inputMenu = 'n';
    }
    if(inputMenu == '3'){
        cuadrado(69, 13, 39, 2, ' ');
        userInputStr(69,13, actualUser->telefono);
        if (strIsNumber(actualUser->telefono) == 0){
            gotoxy(69,13); printf(f_LRED); printf("Ingresar un Numero");
            actualUser->telefono[0] = 0;
        }
        inputMenu = 'n';
    }
    if(inputMenu == '4'){
        cuadrado(69, 19, 39, 2, ' ');
        userInputStr(69,19, actualUser->direccion);
        inputMenu = 'n';
    }
    if(inputMenu == '5'){
        transition();
        pageIndex = 1;
        firstTime = 1;
        actualUser->nombre[0] = 0;
        actualUser->cedula[0] = 0;
        actualUser->telefono[0] = 0;
        actualUser->direccion[0] = 0;
    }
    if(inputMenu == '6'){
        if (strlen(actualUser->nombre) > 1 && strlen(actualUser->cedula) > 1 && strlen(actualUser->telefono) > 1 && strlen(actualUser->direccion) > 1){
            transition();
            saveUser(actualUser, "./data/USERS.txt");
            pageIndex = 3;
            firstTime = 1;
        }else{
            printf(f_LRED);
            gotoxy(57, 29); printf("*Ingrese todos los datos");
            printf(s_RESET_ALL);
        }
    }
}

void layer_options(){
    static int firstTime = 1;
    if (firstTime){
        borrarPantalla();
        layer_global();
        imgLine(35, 33, f_LGREEN);
        imgLine(56, 33, f_LGREEN);
        imgLine(77, 33, f_LGREEN);
        printf(f_LRED);
        gotoxy(41, 12); printf("1.");
        gotoxy(41, 17); printf("2.");
        gotoxy(41, 22); printf("3.");
        gotoxy(41, 27); printf("0. "); printf(f_LBLUE); printf(" Salir del programa");
        imgTextDonacion(45,10, f_LBLUE);
        imgTextVerDonaciones(46,15, f_LBLUE);
        imgTextMisDonaciones(47,20, f_LBLUE);
        imgTextGarritas(62, 2, f_LBLUE);
        imgBear(99, 24, f_LGREEN);
        imgCave(1, 17, f_LGREEN);
        firstTime = 0;
    }

    userInputMenu(41,32);
    cuadrado(37, 32, 64, 1, ' ');
    if(inputMenu == '1'){
        transition();
        firstTime = 1;
        pageIndex = 4;
    }else if(inputMenu == '2'){
        transition();
        firstTime = 1;
        pageIndex = 6;
    }else if(inputMenu == '3'){
        transition();
        firstTime = 1;
        pageIndex = 7;
    }
}

void layer_makeDonation(NodeDonation* headDonations, User actualUser, Need* needList, int numNeedsList){
    static int firstTime = 1;
    static int type = 0;
    char value[20];
    char description[100];

    int* totalNeeds = (int*)malloc(numNeedsList*sizeof(int));
    for (int i = 0; i < numNeedsList; i++){
        totalNeeds[i] = 0;
    }
    while (headDonations->next){
        headDonations = headDonations->next;
        if (headDonations->donation.destino != -1) totalNeeds[headDonations->donation.destino] += atoi(headDonations->donation.valor);
    }

    if (firstTime){
        value[0] = 0;
        description[0] = 0;
        borrarPantalla();
        layer_global();
        imgTextDonacion(54,1, f_LBLUE);

        gotoxy(70, 7); printf(f_LRED); printf("2."); printf(f_LBLUE); gotoxy(73, 7); printf("Tipo de donacion");
         
        gotoxy(73, 13);
        if (type == 0)  printf("  Valor Monetario");
        else if (type == 1) printf("Cantidad de objetos");
        else if (type == 2) printf("Horas de voluntariado");
        gotoxy(70, 13); printf(f_LRED); printf("3.");
        printf(f_LGREEN); recuadro(71, 14, 22, 3);

        gotoxy(70, 19); printf(f_LRED); printf("4."); printf(f_LBLUE); gotoxy(73, 19); printf("Descripccion (opcional)");
        printf(f_LGREEN);
        recuadro(56, 20, 49, 6);

        if (type == 0) printf(f_LBLUE);
        else printf(f_LGREEN);
        recuadro(51, 8, 20, 3);
        gotoxy(57, 10); printf("Monetaria");

        if (type == 1) printf(f_LBLUE);
        else printf(f_LGREEN);
        recuadro(72, 8, 20, 3);
        gotoxy(79, 10); printf("Material");

        if (type == 2) printf(f_LBLUE);
        else printf(f_LGREEN);
        recuadro(93, 8, 20, 3);
        gotoxy(98, 10); printf("Voluntariado");

        printf(f_LBLUE);
        gotoxy(3, 3); printf("--- Causas a las que donar ---");
        for (int i = 0; i < numNeedsList; i++){
            printf(f_LGREEN);
            gotoxy(5, 5+3*i); printf("- %s", needList[i].name);
            if (needList[i].type == 0) printf(" (Monetaria)");
            else if (needList[i].type == 1) printf(" (Material)");
            else if (needList[i].type == 2) printf(" (Voluntariado)");
            if (totalNeeds[i] < needList[i].goal) printf(f_LBLUE);
            gotoxy(5, 6+3*i); printf("%d / %d", totalNeeds[i], needList[i].goal);
        }

        gotoxy(48, 33); printf(f_LRED); printf("1."); printf(f_LBLUE); printf(" Regresar");
        gotoxy(48, 34); printf(f_LRED); printf("0."); printf(f_LBLUE); printf(" Salir del programa");
        gotoxy(70, 29); printf(f_LRED); printf("5."); printf(" HACER DONACION");
        printf(s_RESET_ALL);

        firstTime = 0;
    }

    userInputMenu(70,33);
    cuadrado(70, 33, 40, 2, ' ');
    
    if(inputMenu == '1'){
        transition();
        firstTime = 1;
        pageIndex = 3;
    }else if (inputMenu == '2'){
        type = (type+1) % 3; 
        firstTime = 1;
    }else if (inputMenu == '3'){
        value[0] = 0;
        cuadrado(72, 15, 21, 2, ' ');
        userInputStr(72,15, value);

        if (strIsNumber(value) == 0){
            gotoxy(72,15); printf(f_LRED); printf("Ingresar un Numero");
            value[0] = 0;
        }
        inputMenu = 'n';
    }else if (inputMenu == '4'){
        description[0] = 0;
        cuadrado(58, 21, 47, 5, ' ');
        userInputStr(58,21, description);
        inputMenu = 'n';
    }else if (inputMenu == '5'){
        int have = 0;
        for (int i = 0; i < numNeedsList; i++){
            if (needList[i].type == type && totalNeeds[i] < needList[i].goal){
                have = 1;
            }
        }
        if (strlen(value) < 1){
            printf(f_LRED);
            gotoxy(70,33); printf("*Ingrese un valor");
            printf(s_RESET_ALL);
        }else if (have == 1){
            if (strlen(description) < 1) strcpy(description, "Sin descripcion");
            for (int i = 0; i < numNeedsList; i++){
                printf(f_LRED);
                if (needList[i].type == type && totalNeeds[i] < needList[i].goal){
                    gotoxy(2, 5+3*i); printf("%d.", i+1);
                }
                printf(s_RESET_ALL);
                gotoxy(48, 33); printf("  ");
                gotoxy(70,7); printf("  ");
                gotoxy(70,13); printf("  ");
                gotoxy(70,19); printf("  ");
                gotoxy(70,29); printf("  ");
            }
            do{
                cuadrado(70, 33, 40, 2, ' ');
                userInputMenu(70,33);
                if (inputMenu == '0') return;
            }
            while (needList[(inputMenu-'0')-1].type != type || totalNeeds[(inputMenu-'0')-1] > needList[(inputMenu-'0')-1].goal);

            char time[20];
            actualTime(time);
            formatingText(description);
            addNodeDonationStart(headDonations, actualUser.cedula, time, type, value, description, (inputMenu-'0')-1);

            cuadrado(70, 33, 40, 2, ' ');
            printf(f_LRED); gotoxy(70,33); printf("*Donacion hecha, pulsa ENTER para continuar...");
            userInputMenu(70,33);

            firstTime = 1;
            inputMenu = 'n';
        }else if (have == 0){
            printf(f_LRED);
            gotoxy(70,33); printf("*No hay causa disponible");
            printf(s_RESET_ALL);
        }
    }
    free(totalNeeds);
}

void layer_myDonations(NodeDonation* headDonations, User user){
        static int firstTime = 1;
        static int donationPage = 0;
        int percent = 0;
        int nonePage;
        NodeDonation* copyhead = headDonations;
    if (firstTime){
        borrarPantalla();
        layer_global();
        if (headDonations->next){
            nonePage = printCardDonationPage(79,5,headDonations, 5, donationPage, user.cedula);
            if (nonePage == 0){
            gotoxy(95, 35); printf(f_LRED); printf("7. "); printf(f_LBLUE); printf("Siguiente pagina");}
            if (donationPage != 0){
            gotoxy(75, 35); printf(f_LRED); printf("8. "); printf(f_LBLUE); printf("Anterior pagina");}

            int count = 0;
            headDonations = headDonations->next;
            while (headDonations){
                if (strcmp(headDonations->donation.cedula, user.cedula) == 0){
                    percent++;
                }
                count++;
                headDonations = headDonations->next;
            }
            percent = (percent * 100) / count;

            printf(f_LBLUE);
            if (percent == 0){gotoxy(73, 6); printf("No hay donaciones");}
            gotoxy(37, 15); printf("%d%%", percent);
            printf(f_LGREEN);
            graficaPastel(25, 25, 16, 8, '*',f_LBLUE, f_LGREEN, percent);
        }else {
            printf(f_LBLUE);
            gotoxy(37, 15); printf("XX%%");
            gotoxy(73, 6); printf("No hay donaciones");
            graficaPastel(25, 25, 16, 8, '.', f_LBLUE, f_LGREEN, 0);
        }
        
        imgTextMisDonaciones(55,1, f_LBLUE);
        printf(f_LBLUE);
        gotoxy(22, 6); printf("USUARIO");
        gotoxy(20, 13); printf("Estadisticas");
        
        printf(f_LGREEN);
        gotoxy(12, 8); printf("- %s", user.nombre);
        gotoxy(28, 8); printf("- %s", user.cedula);
        gotoxy(12, 10); printf("- %s", user.telefono);
        gotoxy(28, 10); printf("- %s", user.direccion);
        gotoxy(12, 15); printf("Porcentaje de donaciones");
        printf(f_LRED);
        gotoxy(47, 14); printf(f_LRED); printf("1."); printf(f_LBLUE); printf(" Regresar");
        gotoxy(47, 16); printf(f_LRED); printf("0."); printf(f_LBLUE); printf(" Salir del programa");
        firstTime = 0;
    }

    userInputMenu(50,12);
    cuadrado(50, 12, 29, 2, ' ');
    
    if (inputMenu == '1'){
        transition();
        firstTime = 1;
        pageIndex = 3;
    }else if(inputMenu == '2'){
        transition();
        firstTime = 1;
        cardIndex = realIndexUserDonation(copyhead, user.cedula, 1+5*donationPage)-1;
        pageIndex = 8;
        lastPageIndex = 7;
    }else if (inputMenu == '3'&& (nonePage == 0 || nonePage >= 2)){
        transition();
        firstTime = 1;
        cardIndex = realIndexUserDonation(copyhead, user.cedula, 2+5*donationPage)-1;
        pageIndex = 8;
        lastPageIndex = 7;
    }else if (inputMenu == '4'&& (nonePage == 0 || nonePage >= 3)){
        transition();
        firstTime = 1;
        cardIndex = realIndexUserDonation(copyhead, user.cedula, 3+5*donationPage)-1;
        pageIndex = 8;
        lastPageIndex = 7;
    }else if (inputMenu == '5'&& (nonePage == 0 || nonePage >= 4)){
        transition();
        firstTime = 1;
        cardIndex = realIndexUserDonation(copyhead, user.cedula, 4+5*donationPage)-1;
        pageIndex = 8;
        lastPageIndex = 7;
    }else if (inputMenu == '6'&& (nonePage == 0 || nonePage >= 5)){
        transition();
        firstTime = 1;
        cardIndex = realIndexUserDonation(copyhead, user.cedula, 5+5*donationPage)-1;
        pageIndex = 8;
        lastPageIndex = 7;
    }else if (inputMenu == '7' && nonePage == 0){
        donationPage += 1;
        firstTime = 1;
    }else if (inputMenu == '8' && donationPage != 0){
        donationPage -= 1;
        firstTime = 1;
    }
}

void layer_listDonations(NodeDonation* headDonations){
        static int firstTime = 1;
        static int donationPage = 0;
        int nonePage;
    if (firstTime){
        borrarPantalla();
        layer_global();

        if (headDonations->next){
            nonePage = printCardDonationPage(70,5,headDonations, 5, donationPage, NULL);
            if (nonePage == 0){
            gotoxy(90, 35); printf(f_LRED); printf("7. "); printf(f_LBLUE); printf("Siguiente pagina");}
            if (donationPage != 0){
            gotoxy(70, 35); printf(f_LRED); printf("8. "); printf(f_LBLUE); printf("Anterior pagina");}

        }
        imgTextVerDonaciones(55,1, f_LBLUE);
        printf(f_LRED);
        gotoxy(40, 8); printf(f_LRED); printf("1."); printf(f_LBLUE); printf(" Regresar");
        gotoxy(40, 10); printf(f_LRED); printf("0."); printf(f_LBLUE); printf(" Salir del programa");

        firstTime = 0;
    }
    userInputMenu(40,6);
    cuadrado(40, 6, 29, 2, ' ');
    
    
    if (inputMenu == '1'){
        transition();
        firstTime = 1;
        pageIndex = 3;
    }else if(inputMenu == '2'){
        transition();
        firstTime = 1;
        cardIndex = 0+5*donationPage;
        pageIndex = 8;
        lastPageIndex = 6;
    }else if (inputMenu == '3' && (nonePage == 0 || nonePage >= 2)){
        transition();
        firstTime = 1;
        cardIndex = 1+5*donationPage;
        pageIndex = 8;
        lastPageIndex = 6;
    }else if (inputMenu == '4'  && (nonePage == 0 || nonePage >= 3)){
        transition();
        firstTime = 1;
        cardIndex = 2+5*donationPage;
        pageIndex = 8;
        lastPageIndex = 6;
    }else if (inputMenu == '5'  && (nonePage == 0 || nonePage >= 4)){
        transition();
        firstTime = 1;
        cardIndex = 3+5*donationPage;
        pageIndex = 8;
        lastPageIndex = 6;
    }else if (inputMenu == '6'  && (nonePage == 0 || nonePage >= 5)){
        transition();
        firstTime = 1;
        cardIndex = 4+5*donationPage;
        pageIndex = 8;
        lastPageIndex = 6;
    }else if (inputMenu == '7' && nonePage == 0){
        donationPage += 1;
        firstTime = 1;
    }else if (inputMenu == '8' && donationPage != 0){
        donationPage -= 1;
        firstTime = 1;
    }
}

void layer_infoDonation(NodeDonation* headDonations, User** UsersList,int numUsersList, Need* needList, User actualUser){
    static int firstTime = 1;
    NodeDonation* donation = findIndexUserDonations(headDonations, cardIndex);
    User* user = findUserID(UsersList, numUsersList, donation->donation.cedula);
    if (firstTime){
        borrarPantalla();
        layer_global();
        gotoxy(3,4); printf("Cedula: %s", donation->donation.cedula);
        gotoxy(3,5); printf("Fecha: %s", donation->donation.fecha);
        gotoxy(3,6); printf("Tipo: ");
        if (donation->donation.tipo == 0) printf("Monetaria");
        else if (donation->donation.tipo == 1) printf("Material");
        else if (donation->donation.tipo == 2) printf("Voluntariado");
        gotoxy(3,7); 
        if (donation->donation.tipo == 0) printf("Valor: ");
        else if (donation->donation.tipo == 1) printf("Cantidad: ");
        else if (donation->donation.tipo == 2) printf("Horas: ");
        printf("%s", donation->donation.valor);
        gotoxy(3,8); printf("Descripcion: %s", donation->donation.descriccion);

        if (donation->donation.destino != -1){
            Need need = needList[donation->donation.destino];
            gotoxy(3,10); printf("Nombre: %s", need.name);
            gotoxy(3,11); printf("Objetivo: %d", need.goal);
            gotoxy(3,12); printf("Descripccion: %s", need.description);
        }

        if (user){
            gotoxy(53,4); printf("Nombre: %s", user->nombre);
            gotoxy(53,5); printf("Cedula: %s", user->cedula);
            gotoxy(53,6); printf("Direccion: %s", user->direccion);
            gotoxy(53,7); printf("Telefono: %s", user->telefono);
            gotoxy(53,8); printf("Cantidad de donaciones: %d", countDonationsUser(headDonations, user->cedula));
        }else if (strcmp(actualUser.cedula, donation->donation.cedula) == 0){
            gotoxy(53,4); printf("Nombre: %s", actualUser.nombre);
            gotoxy(53,5); printf("Cedula: %s", actualUser.cedula);
            gotoxy(53,6); printf("Direccion: %s", actualUser.direccion);
            gotoxy(53,7); printf("Telefono: %s", actualUser.telefono);
            gotoxy(53,8); printf("Cantidad de donaciones: %d", countDonationsUser(headDonations, actualUser.cedula));
        }

        printf(f_LRED);
        gotoxy(58, 18); printf("1. Regresar");
        gotoxy(58, 19); printf("0. Salir");
        printf(s_RESET_ALL);
        firstTime = 0;
    }

    cuadrado(80, 18, 40, 2, ' ');
    userInputMenu(80,18);
    
    if(inputMenu == '1'){
        transition();
        firstTime = 1;
        pageIndex = lastPageIndex;
    }
}

int main (){
    just_fix_windows_console();

    makeTXT("./data/DONATIONS.txt");
    makeTXT("./data/USERS.txt");

    int numUsersList = countLines("./data/USERS.txt", 0);
    int numNeedsList = countLines("./data/NEEDS.txt", 5);
    if (numNeedsList > 9) numNeedsList = 9;
    User** UsersList = (User**)malloc(numUsersList * sizeof(User*));
    NodeDonation* headDonations = (NodeDonation*)malloc(sizeof(NodeDonation));
    headDonations->next = NULL;
    Need* needsList = (Need*)malloc(numNeedsList*sizeof(Need));

    if (numUsersList != 0){
        loadUsers(UsersList, "./data/USERS.txt");
        //verUsers(UsersList);
    }
    if (numNeedsList != 0){
        loadNeeds(needsList, "./data/NEEDS.txt", 5);
    }
    loadDonations(headDonations, "./data/DONATIONS.txt");

    User* actualUser = (User*)malloc(sizeof(User));
    /*strcpy(actualUser->nombre, "Daniel");
    strcpy(actualUser->cedula, "cedulaD");
    strcpy(actualUser->telefono, "telefonoD");
    strcpy(actualUser->direccion, "direccionD");*/
    
    char buffer[20];

    actualTime(buffer);
    printf("%s\n", buffer);
    
    ocultarCursor();
    borrarPantalla();
    layer_global();

    imgTreeMain1(2, 13, f_LGREEN);
    startAnimation();
    while (1)
    {   

        if (pageIndex == 0) layer_main();
        if (pageIndex == 1) layer_login(actualUser, UsersList, numUsersList);
        if (pageIndex == 2) layer_register(actualUser,UsersList, numUsersList);
        if (pageIndex == 3) layer_options();
        if (pageIndex == 4) layer_makeDonation(headDonations,*actualUser, needsList, numNeedsList);
        if (pageIndex == 6) layer_listDonations(headDonations);
        if (pageIndex == 7) layer_myDonations(headDonations,*actualUser);
        if (pageIndex == 8) layer_infoDonation(headDonations, UsersList, numUsersList, needsList,*actualUser);

        if (inputMenu == '0'){
            break;
        }
    }

    printf(s_RESET_ALL);
    mostrarCursor();
    borrarPantalla();
    saveDonation(headDonations, "./data/DONATIONS.txt");
    free(actualUser);
    free(needsList);
    freeLinkedDonations(&headDonations);
    freeUsers(UsersList, numUsersList);
    free(UsersList);
    return 0;
}