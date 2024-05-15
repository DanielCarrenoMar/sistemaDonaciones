#include "../structs.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

NodeDonation* findIndextDonations(NodeDonation* head, int index){
    head = head->next;
    int i = 0;
    while (head){
        if (i == index){
            return head;
        }
        head = head->next;
        i++;
    }
    return NULL;
}

NodeDonation* createNodeDonation(char* cedula, char* fecha, char* tipo, char* valor, char* descriccion, char destino){
    NodeDonation* newNode = malloc(sizeof(NodeDonation));
    if(!newNode){
        printf("Error al asignar memoria\n");
        return NULL;
    }
    strncpy(newNode->donation.cedula, cedula, 30);
    strncpy(newNode->donation.fecha, fecha, 20);
    strncpy(newNode->donation.tipo, tipo, 20);
    strncpy(newNode->donation.valor, valor, 20);
    strncpy(newNode->donation.descriccion, descriccion, 100);
    newNode->donation.destino = destino;
    newNode->next = NULL;
    return newNode;
}

void addNodeDonationStart(NodeDonation* head, char* cedula, char* fecha, char* tipo, char* valor, char* descriccion, char destino){
    if(!head) return;
    NodeDonation* newNode = createNodeDonation(cedula, fecha, tipo, valor, descriccion, destino);

    newNode->next = head->next;
    head->next = newNode;
}

void addNodeDonationEnd(NodeDonation* head, char* cedula, char* fecha, char* tipo, char* valor, char* descriccion, char destino){
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
        printf("%s\n", head->donation.tipo);
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