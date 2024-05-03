#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./library/txtHandler.h"

int numDonationsList = 0;
int numUsersList = 0;
char Tecla_entrada[1];

int main (){
    numDonationsList = countDonations();
    numUsersList = countUsers();
    Donation_t** DonationList = (Donation_t**)malloc(numDonationsList * sizeof(Donation_t*));
    User_t** UsersList = (User_t**)malloc(numUsersList * sizeof(User_t*));

    cargarDonations(DonationList, "./data/DONATIONS.txt");
    cargarUsers(UsersList, "./data/USERS.txt");

    verDonations(DonationList);
    verUsers(UsersList);

    freeDonation(DonationList);
    freeUsers(UsersList);


    return 0;
}


void login_menu(){
    printf("¿Tiene cuenta? S/N \n");
    scanf("%s", Tecla_entrada);
    if (Tecla_entrada == "S" || "s"){
        printf("Ingrese nombre:");
        //Pide los datos, aun no esta listo
    }
    if (Tecla_entrada == "N" || "n")
    {
        printf("Lo llevaremos a crear una cuenta, sera solo un momento");
        //Aqui lo llevaria a la funcion de registro
    }
    else
    {
        printf("Caracter invalido, intente de nuevo \n");
    }
    
    
}

void main_menu(){
    printf("=================================\n");
    printf("======SALVEN A LAS TORTUGAS======\n");
    printf("=================================\n");
    printf("PULSE CUALQUIER TECLA PARA ENTRAR \n");
    scanf("%s", Tecla_entrada);
    if (Tecla_entrada != NULL){
        (login_menu());
    }
}