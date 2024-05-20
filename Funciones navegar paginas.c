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

typedef struct Indices{
    Datos* indice;
    struct indices* next;
}Indices;

Indices* pushindices(Indices* head, Datos* indice){
    Indices* bloque=(Indices *)malloc(sizeof(Indices));
    bloque->indice=indice;
    bloque->next=head;
    head=bloque;
    return head;    
}

Indices* mostrar(Datos* head, int numdatos, Indices* indices, Datos** actual, Datos** ultimo, int actualizarindice){
    int cedula=1;
    int cont=1;
    Datos* aux=head;
    *actual=head;
    while(aux!=NULL){
        if (aux->cedula==cedula && cont<=numdatos){
            if (cont==1 && actualizarindice==1)
                indices=pushindices(indices, aux);
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
                    printf("Tipo deMáquinas Virtuales donacion: Voluntariado\n");
                    break;
            }
            printf("Descripcion: %s\n", aux->descripcion);
            printf("Monto: %d\n\n", aux->monto);
            aux=aux->next;
            if (cont>numdatos && aux!=NULL){
                *ultimo=aux;
                return indices;
            }
        }
    }
    return indices;
}

void paginas(Datos* head, int numdatos){
    int pregunta=1;
    int pregunta2=1;
    Datos* actual=NULL;
    Datos* ultimo=NULL;
    Indices* indices=mostrar(head, numdatos, indices, &actual, &ultimo, 1);
    while(pregunta==1){
        printf("1.Siguiente pagina\n2.Anteriorpagina\n");
        if (scanf("%d", &pregunta2) != 1){
            printf("Error: La entrada no es valida\n");
            return;
        }
        if (pregunta2==1)
            if (ultimo!=NULL)
                indices=mostrar(ultimo, numdatos, indices, &actual, &ultimo, 1);
            else{  
                indices=mostrar(actual, numdatos, indices, &actual, &ultimo, 1);
            }
        else{
            if (indices!=NULL){
                indices=extraer(indices);
                indices=mostrar(indices->indice, numdatos, indices, &actual, &ultimo, 0);
                indices=extraer(indices);
            }
            else{
                indices=mostrar(actual, numdatos, indices, &actual, &ultimo, 0);
                indices=extraer(indices);
            }
        }
        //printf("Seguir navegando?\n 1.Si\n2.No\n");
        //scanf("%d", &pregunta);
    }
}

//Para mostra los datos tipo paginas, llamar: paginas(cabeza de la lista, cantidad de conjunto de datos a mostrar)