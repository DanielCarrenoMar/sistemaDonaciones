# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct Datos{
    int cedula;
    char fecha[11];
    int tipo;
    char descripcion[100];
    int monto;
    struct Datos* anterior;
    struct Datos* next;
}Datos;

Datos* push(Datos* head, int cedula, char fecha[], int tipo, char descripcion[], int monto, Datos** primero){
    Datos* bloque=(Datos *)malloc(sizeof(Datos));
    bloque->cedula= cedula;
    strcpy(bloque->fecha, fecha);
    bloque->tipo=tipo;
    strcpy(bloque->descripcion, descripcion);
    bloque->monto=monto;
    if (head==NULL){
        *primero=bloque;
    }else{
        bloque->next=head;
        head->anterior=bloque;
        (*primero)->next=bloque;
        ((*primero)->next)->anterior=*primero;
    }
    head=bloque;
    return head;
}

Datos* mostrar(Datos* head, int numdatos, Datos** actual){
    int cedula=1;
    int cont=1;
    Datos* ultimo=NULL;
    Datos* aux=head;
    *actual=head;
    while(aux!=NULL){
        if (aux->cedula==cedula && cont<=numdatos){
            cont++;
            printf("Fecha: %s\n", aux->fecha);
            switch (aux->tipo){
                case 1:
                    printf("Tipo de donacion: Monetaria\n");
                    break;
                case 2:
                    printf("Tipo de donacion: Material\n");
                    break;
                case 3:
                    printf("Tipo de donacion: Voluntariado\n");
                    break;
            }
            printf("Descripcion: %s\n", aux->descripcion);
            printf("Monto: %d\n\n", aux->monto);
            aux=aux->next;
            if (cont>numdatos && aux!=NULL){
                ultimo=aux;
                return ultimo;
            }
        }
    }
    return ultimo;
}

Datos* anterior(Datos* ultimo, int numdatos){
    int cont=0;
    while (cont<=numdatos+1 && ultimo!=NULL){
        cont++;
        ultimo=ultimo->anterior;
    }
    return ultimo;
}

void paginas(Datos* head, int numdatos){
    int pregunta=1;
    Datos* actual=NULL;
    Datos* ultimo=mostrar(head, numdatos, &actual);
    while(pregunta==1){
        printf("1.Siguiente pagina\n2.Anteriorpagina\n");
        scanf("%d", &pregunta);
        if (pregunta==1)
            if (ultimo!=NULL)
                ultimo=mostrar(ultimo, numdatos, &actual);
            else   
                ultimo=mostrar(actual, numdatos, &actual);
        else
            ultimo=mostrar(anterior(ultimo, numdatos), numdatos, &actual);
        printf("Seguir navegando?\n 1.Si\n2.No\n");
        scanf("%d", &pregunta);
    }
}

//Para mostrar la pagina 
//llamar "paginas(cabeza de lista doble y circular, numero de conjunto de datos a mostrar)"