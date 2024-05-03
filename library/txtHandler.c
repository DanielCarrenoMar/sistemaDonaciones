#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

int countDonations(){
    FILE *file;
    char c;
    int count = 1;
    if ((file = fopen("./data/DONATIONS.txt", "r"))) {
        while ((c = fgetc(file)) != EOF)
            if (c == '\n') count++;
    }else {
        printf("El archivo no existe.\n");
        return 0;
    }
    return count;
}
int countUsers(){
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

void cargarDonations(Donation_t** users, char* file_name){
    FILE *file;
    char line[1028];
    int count = 0;

    if ((file = fopen(file_name, "r"))) {
        while (fgets(line, sizeof(line), file)) {
            *users = (Donation_t*)malloc(sizeof(Donation_t));
            if (*users == NULL) return;

            count = 0;
            printf("%s",line);
            char* userToken = strtok(line, " ");

            do{ 
                if (count == 0){
                    strcpy((*users)->cedula, userToken);
                    printf("Cedula: %s\n", (*users)->cedula);
                }else if (count == 1){
                    strcpy((*users)->fecha, userToken);
                    printf("Fecha: %s\n", (*users)->fecha);
                }else if (count == 2){
                    strcpy((*users)->tipo, userToken);
                    printf("Tipo: %s\n", (*users)->tipo);
                }else if (count == 3){
                    strcpy((*users)->valor, userToken);
                    printf("Valor: %s\n", (*users)->valor);
                }
                count++;
            }
            while (userToken = strtok(NULL, " "));
            *users++;
        }
        fclose(file);
    }
}

void cargarUsers(User_t** users, char* file_name){
    FILE *file;
    char line[1028];
    int count = 0;

    if ((file = fopen(file_name, "r"))) {
        while (fgets(line, sizeof(line), file)) {
            *users = (User_t*)malloc(sizeof(User_t));
            if (*users == NULL) return;

            count = 0;
            printf("%s",line);
            char* userToken = strtok(line, " ");

            do{ 
                if (count == 0){
                    strcpy((*users)->nombre, userToken);
                    printf("Cedula: %s\n", (*users)->nombre);
                }else if (count == 1){
                    strcpy((*users)->cedula, userToken);
                    printf("Fecha: %s\n", (*users)->cedula);
                }else if (count == 2){
                    strcpy((*users)->telefono, userToken);
                    printf("Tipo: %s\n", (*users)->telefono);
                }else if (count == 3){
                    strcpy((*users)->direccion, userToken);
                    printf("Valor: %s\n", (*users)->direccion);
                }
                count++;
            }
            while (userToken = strtok(NULL, " "));
            *users++;
        }
        fclose(file);
    }
}

void verDonations(Donation_t** users){
    printf("-----\n");
    while (*users != NULL){
        printf("Cedula: %s\n", (*users)->cedula);
        printf("DONACION\n");
        printf("Fecha: %s\n", (*users)->fecha);
        printf("tipo: %s\n", (*users)->tipo);
        printf("valor: %s\n", (*users)->valor);
        printf("-----\n");
        users++;
    }
}

void verUsers(User_t** users){
    printf("-----\n");
    while (*users != NULL){
        printf("Nombre: %s\n", (*users)->nombre);
        printf("Cedula: %s\n", (*users)->cedula);
        printf("Telefono: %s\n", (*users)->telefono);
        printf("Direccion: %s\n", (*users)->direccion);
        printf("-----\n");
        users++;
    }
}
void freeDonation(Donation_t** users){
    while (*users != NULL)
    {
        free(*users);
    }
    free(users);
}
void freeUsers(User_t** users){
    while (*users != NULL)
    {
        free(*users);
    }
    free(users);
}