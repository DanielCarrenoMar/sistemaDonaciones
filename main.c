#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

int numUsersList = 0;

void imprimirDatos(FILE* buffer){
    char c;
    while ((c = fgetc(buffer)) != EOF) {
        putchar(c);
    }
}

int contarUsers(){
    FILE *file;
    char c;
    int count = 1;
    if ((file = fopen("./data/USERS.txt", "r"))) {
        while ((c = fgetc(file)) != EOF)
            if (c == '\n') count++;
    }else {
        printf("El archivo no existe.\n");
        return 0;
    }
    return count;
}

void cargarUsers(User_t** users){
    FILE *file;
    char c;
    int count = 0;
    int countDonation = 0;
    int bufferIndex = 0;

    if ((file = fopen("./data/USERS.txt", "r"))) {
        *users = (User_t*)malloc(sizeof(User_t));
        if (*users == NULL) {
            printf("Error al asignar memoria.\n");
            return;
        }

        (*users)->donaciones = (Donation_t**)malloc(10 * sizeof(Donation_t*));
        if ((*users)->donaciones == NULL) {
            printf("Error al asignar memoria.\n");
            return;
        }

        while ((c = fgetc(file)) != EOF) {
            if (c == '\n') {
                count = 0;
                countDonation = 0;
                bufferIndex = 0;
                *users++;
                
                *users = (User_t*)malloc(sizeof(User_t));
                if (*users == NULL) {
                    printf("Error al asignar memoria.\n");
                    return;
                }
                (*users)->donaciones = (Donation_t**)malloc(10 * sizeof(Donation_t*));
                if ((*users)->donaciones == NULL) {
                    printf("Error al asignar memoria.\n");
                    return;
                }

                continue;
            }
            if (c == ' ') {
                count++;
                bufferIndex = 0;

                if (count >= 4){
                    countDonation = 0;
                    (*(*users)->donaciones) = (Donation_t*)malloc(sizeof(Donation_t));
                    if ((*(*users)->donaciones) == NULL) {
                        printf("Error al asignar memoria.\n");
                        return;
                    }
                }
                continue;    
            }

            if (count == 0){
                (*users)->nombre[bufferIndex] = c;
                (*users)->nombre[bufferIndex+1] = '\0';
            }else if (count == 1){
                (*users)->cedula[bufferIndex] = c;
                (*users)->cedula[bufferIndex+1] = '\0';
            }else if (count == 2){
                (*users)->telefono[bufferIndex] = c;
                (*users)->telefono[bufferIndex+1] = '\0';
            }else if (count == 3){
                (*users)->direccion[bufferIndex] = c;
                (*users)->direccion[bufferIndex+1] = '\0';
            }else if (count >= 4){
                if (c == ',') {
                    countDonation++;
                    bufferIndex = 0;
                    continue;    
                }
                if (countDonation == 0){
                    (*(*users)->donaciones)->fecha[bufferIndex] = c;
                    (*(*users)->donaciones)->fecha[bufferIndex+1] = '\0';
                }else if (countDonation == 1){
                    (*(*users)->donaciones)->tipo[bufferIndex] = c;
                    (*(*users)->donaciones)->tipo[bufferIndex+1] = '\0';
                }else if (countDonation == 2){
                    (*(*users)->donaciones)->valor[bufferIndex] = c;
                    (*(*users)->donaciones)->valor[bufferIndex+1] = '\0';
                }
            }
            bufferIndex++;
        }
        fclose(file);
    } else {
        printf("El archivo no existe.\n");
        return;
    }
}

void descargarUsers(User_t** users){
    for (int i = 0; i < numUsersList; i++){
        for(int j = 0; j < 10; j++){
            if ((*users)->donaciones[j] != NULL)
                free((*users)->donaciones[j]);
        }
        free(*users);
        *users++;
    }
    free(users);
}

void verUsers(User_t** users){
    printf("-----\n");
    for (int i = 0; i < numUsersList; i++){
        if (*users != NULL)
            printf("Nombre: %s\n", (*users)->nombre);
            printf("Cedula: %s\n", (*users)->cedula);
            printf("Telefono: %s\n", (*users)->telefono);
            printf("Direccion: %s\n", (*users)->direccion);
            for(int j = 0; j < 10; j++){
                if ((*users)->donaciones[j] != NULL){
                    printf("-----\n");
                    printf("Donacion %d\n", j+1);
                    printf("Fecha: %s\n", (*(*users)->donaciones)->fecha);
                    printf("Tipo: %s\n", (*(*users)->donaciones)->tipo);
                    printf("Valor: %s\n", (*(*users)->donaciones)->valor);
                    printf("-----\n");
                }
            }
            printf("-----\n");
            users++;
    }
}

int main (){
    numUsersList = contarUsers();
    User_t** UsersList = (User_t**)malloc(numUsersList * sizeof(User_t*));

    cargarUsers(UsersList);

    verUsers(UsersList);

    descargarUsers(UsersList);


    return 0;
}