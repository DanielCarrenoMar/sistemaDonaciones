#include "../structs.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

int countDonationsUser(NodeDonation* head, char* id){
    int count = 0;
    while (head->next){
        head = head->next;
        if (strcmp(head->donation.cedula, id) == 0){
            count++;
        }
    }
    return count;
}

int realIndexUserDonation(NodeDonation* head, char* id, int index){
    int realIndex = 0;
    while (head->next){
        head = head->next;
        printf("cedula %s\n", head->donation.cedula);
        if (strcmp(head->donation.cedula, id) == 0) index--;
        realIndex++;
        if (index == 0){
            return realIndex;
        }
    }
    return -1;
}

NodeDonation* findIndexUserDonations(NodeDonation* head, int index){
    head = head->next;
    int i = 0;
    while (head){
        if (i == index){
            return head;
        }
        i++;
        head = head->next;
    }
    return NULL;
}

NodeDonation* createNodeDonation(char* cedula, char* fecha, int tipo, char* valor, char* descriccion, int destino){
    NodeDonation* newNode = malloc(sizeof(NodeDonation));
    if(!newNode){
        printf("Error al asignar memoria\n");
        return NULL;
    }
    strcpy(newNode->donation.cedula, cedula);
    strcpy(newNode->donation.fecha, fecha);
    newNode->donation.tipo = tipo;
    strcpy(newNode->donation.valor, valor);
    strcpy(newNode->donation.descriccion, descriccion);
    newNode->donation.destino = destino;
    newNode->next = NULL;
    return newNode;
}

void addNodeDonationStart(NodeDonation* head, char* cedula, char* fecha, int tipo, char* valor, char* descriccion, int destino){
    if(!head) return;
    NodeDonation* newNode = createNodeDonation(cedula, fecha, tipo, valor, descriccion, destino);

    newNode->next = head->next;
    head->next = newNode;
}

void addNodeDonationEnd(NodeDonation* head, char* cedula, char* fecha, int tipo, char* valor, char* descriccion, int destino){
    if(!head) return;
    NodeDonation* newNode = createNodeDonation(cedula, fecha, tipo, valor, descriccion, destino);
    if (head->next == NULL){
        head->next = newNode;
    } else {
        while (head->next != NULL){
            head = head->next;
        }
        head->next = newNode;
    }
}

void printNodesDonations(NodeDonation* head){
    head = head->next;
    while (head){
        printf("-------------------\n");
        printf("%s\n", head->donation.cedula);
        printf("%s\n", head->donation.fecha);
        if(head->donation.tipo == 0) printf("Monetaria\n");
        else if(head->donation.tipo == 1) printf("Material\n");
        else printf("Voluntariado\n");
        printf("Valor: %s\n", head->donation.valor);
        printf("Descrip: %s\n", head->donation.descriccion);
        printf("Destino: %c\n", head->donation.destino);
        printf("\n");
        head = head->next;
    }
}

void freeLinkedDonations(NodeDonation** head){
    NodeDonation* temp;
    while (*head != NULL){
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    *head = NULL;
    free(*head);
}