# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

typedef struct Datos{
    int cedula;
    char fecha[11];
    int tipo;
    char descripcion[100];
    int monto;
    struct Datos* next;
}Datos;

void fechactual(Datos* entrada){
    time_t fechactual;
    time(&fechactual);
    int dia=localtime(&fechactual)->tm_mday;
    int mes=localtime(&fechactual)->tm_mon + 1;
    int año=localtime(&fechactual)->tm_year + 1900;
    sprintf(entrada->fecha, "%02d/%02d/%d", dia, mes, año);
}

Datos pedirdatos(){
    Datos entrada;
    int parametro;
    printf("Cedula: ");
    scanf("%d", &entrada.cedula);
    fechactual(&entrada);
    printf("\nTipo de donacion\n1.Monetaria\n2.Material\n3.Voluntariado\n");
    scanf("%d", &entrada.tipo);
    printf("\nDesea poner descripcion? 1:si  2:no");
    scanf("%d", &parametro);
    if (parametro==1){
        printf("\nDescripcion:");
        scanf("%s", entrada.descripcion);
    }else{
        strcpy(entrada.descripcion, "Sin descripcion");
    }
    if (entrada.tipo==1){
        printf("\nMonto: ");
        scanf("%d", &entrada.monto);
    }else{
        entrada.monto=0;
    }
    return entrada;
}

Datos* push(Datos* head, int cedula, char fecha[], int tipo, char descripcion[], int monto){
    Datos* bloque=(Datos *)malloc(sizeof(Datos));
    bloque->cedula= cedula;
    strcpy(bloque->fecha, fecha);
    bloque->tipo=tipo;
    strcpy(bloque->descripcion, descripcion);
    bloque->monto=monto;
    bloque->next=head;
    head=bloque;
    return head;
}

void ingresartxt(Datos* head){
    FILE *file = fopen("datos.txt", "w");
    Datos* aux=head;
    while(aux!=NULL){
        fprintf(file, "%s,",aux->fecha);
        switch (aux->tipo){
            case 1:
                fprintf(file, "Tipo de donacion: Monetaria,");
                break;
            case 2:
                fprintf(file, "Tipo de donacion: Material,");
                break;
            case 3:
                fprintf(file, "Tipo de donacion: Voluntariado,");
                break;
        }
        fprintf(file, "%s,",aux->descripcion);
        fprintf(file, "%d\n",aux->monto);
        aux=aux->next;
    }
}