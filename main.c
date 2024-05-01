#include <stdio.h>
#include <stdlib.h>
#include "structs.h"

void imprimirDatos(FILE* buffer){
    char c;
    while ((c = fgetc(buffer)) != EOF) {
        putchar(c);
    }
}

void cargarUsers(ActUser_t* user){
    FILE *file;
    char c;
    int count = 0;

    if ((file = fopen("./data/USERS.txt", "r"))) {
        while ((c = fgetc(file)) != EOF) {
            if (c == ' ') count++;

            if (count == 0){
                printf("0\n");
            }else if (count == 1){
                printf("1\n");
            }

        }
        while ((c = fgetc(file)) != EOF) {
            if (c == ' ') count++;

            if (count == 0){
                printf("0\n");
            }else if (count == 1){
                printf("1\n");
            }

        }
        fclose(file);
    } else {
        printf("El archivo no existe.\n");
    }
}

int main (){
    ActUser_t* Users;

    cargarUsers(Users);

    return 0;
}