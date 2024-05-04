#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./library/txtHandler.h"
#include "./library/colorama.h"
#include "./library/graficos.h"
#include "./library/screens.h"

char key;

// Paleta de colores
// Resalte f_RED #AB0000
// Secundarios f_BLUE f_LBLUE #0000AC #5354FC
// Principal f_GREEN #00AB00

void main_menu(){
    imgTextPrincipal(2, 2, f_LMAGENTA);
    gotoxy(2,12); printf(f_LBLUE "Secundario Azul" s_RESET_ALL);

    imageGato(44, 1, f_BLUE);
    imgArbolBuho1(1, 13, f_LGREEN);
    Sleep(1500);
    imgArbolBuho2(1, 13, f_LGREEN);
    Sleep(500);
}

void login_menu(){
    
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

    int page = 0;
    printf(f_GREEN);
    borrarPantalla();
    recuadro(0, 0, 120, 36);
    printf(s_RESET_ALL);

    imgTextPrincipal(2, 2, f_LMAGENTA);
    gotoxy(2,12); printf(f_LBLUE "Secundario Azul" s_RESET_ALL);

    while (1)
    {   
        key = getch();

        imageGato(44, 1, f_BLUE);
        imgArbolBuho1(1, 13, f_LGREEN);
        Sleep(1500);
        imgArbolBuho2(1, 13, f_LGREEN);
        Sleep(500);

        if (key == 'q')break;
    }

    freeDonation(DonationList);
    freeUsers(UsersList);
    printf(s_RESET_ALL);
    return 0;
}