#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../structs.h"
#include "../linkedDonations.h"

void makeTXT(char* file_name){
    FILE *file;
    if (file = fopen(file_name, "r")){
        fclose(file);
    }else{
        file = fopen(file_name, "w");
        fclose(file);
    }
}

int countLines(char* file_name){
    FILE *file;
    char c;
    int count = 0;
    if (file = fopen(file_name, "r")) {
        while ((c = fgetc(file)) != EOF)
            if (c == '\n') count++;
    }else {
        printf("El archivo no existe.\n");
        return 0;
    }
    if (count > 0) count++;
    return count;
}

void findCedula(User_t* buffer, char *file_name){
    FILE *file;
    char line[1028];

    if ((file = fopen(file_name, "r"))) {
        int auxiliar=0;
        
        while (fgets(line, sizeof(line), file)) {
            char* userToken = strtok(line, " ");

            do{ 
                if (auxiliar == 1){

                }
                auxiliar+=1;

            }

            while (userToken = strtok(NULL, " "));
                

        }
        fclose(file);
    }else {
        printf("El archivo no existe.\n");
    }
    printf("XD\n");

}
    
void saveUser(User_t* user, char* file_name){
    FILE *file;
    user->nombre[strlen(user->nombre)-1] = '\0';
    user->cedula[strlen(user->cedula)-1] = '\0';
    user->telefono[strlen(user->telefono)-1] = '\0';
    user->direccion[strlen(user->direccion)-1] = '\0';
    if (file = fopen(file_name, "a")) {
        fprintf(file, "%s %s %s %s\n", user->nombre, user->cedula, user->telefono, user->direccion);
        fclose(file);
    }else {
        printf("El archivo no existe.\n");
    }
}
void saveDonation(nodeDonation_t* head, char* file_name){
    FILE *file;
    if (file = fopen(file_name, "w")) {
        head = head->next;
        while (head){
            fprintf(file, "%s %s %s %s %s %c\n", head->donation.cedula, head->donation.fecha, head->donation.tipo, head->donation.valor, head->donation.descriccion, head->donation.destino);
            head = head->next;
        }
        fclose(file);
    }else {
        printf("El archivo no existe.\n");
    }
}

void loadDonations(nodeDonation_t* head, char* file_name){
    FILE *file;
    char line[255];
    int count = 0;

    if ((file = fopen(file_name, "r"))) {
        while (fgets(line, sizeof(line), file)) {
            char cedula[30];
            char fecha[20];
            char tipo[20];
            char valor[20]; 
            char descriccion[100];
            char destino;

            count = 0;
            char* userToken = strtok(line, " ");

            do{ 
                if (count == 0){
                    strcpy(cedula, userToken);
                }else if (count == 1){
                    strcpy(fecha, userToken);
                }else if (count == 2){
                    strcpy(tipo, userToken);
                }else if (count == 3){
                    strcpy(valor, userToken);
                }else if (count == 4){
                    strcpy(descriccion, userToken);
                }else if (count == 5){
                    destino = userToken[0];
                }
                count++;
            }
            while (userToken = strtok(NULL, " "));
            addNodeDonationEnd(head, cedula, fecha, tipo, valor, descriccion, destino);
        }
        fclose(file);
    }else {
        printf("El archivo no existe.\n");
    }
}
void loadUsers(User_t** users, char* file_name){
    FILE *file;
    char line[1028];
    int count = 0;

    if ((file = fopen(file_name, "r"))) {
        while (fgets(line, sizeof(line), file)) {
            *users = (User_t*)malloc(sizeof(User_t));
            if (*users == NULL) return;

            count = 0;
            char* userToken = strtok(line, " ");

            do{ 
                if (count == 0){
                    strcpy((*users)->nombre, userToken);
                }else if (count == 1){
                    strcpy((*users)->cedula, userToken);
                }else if (count == 2){
                    strcpy((*users)->telefono, userToken);
                }else if (count == 3){
                    strcpy((*users)->direccion, userToken);
                }
                count++;
            }
            while (userToken = strtok(NULL, " "));
            *users++;
        }
        fclose(file);
    }else {
        printf("El archivo no existe.\n");
    }
}

void verUsers(User_t** users){
    if(*users == NULL){
        printf("No hay usuarios\n");
        return;
    }
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
void freeUsers(User_t** users){
    while (*users != NULL)
    {
        free(*users);
    }
    free(users);
}