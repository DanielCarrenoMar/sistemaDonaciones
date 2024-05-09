#include "../structs.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

nodeDonation_t* createNodeDonation(char* cedula, char* fecha, char* tipo, char* descriccion, char* valor){
    nodeDonation_t* newNode = malloc(sizeof(nodeDonation_t));
    strncpy(newNode->donation.cedula, cedula, 30);
    strncpy(newNode->donation.fecha, fecha, 20);
    strncpy(newNode->donation.tipo, tipo, 20);
    strncpy(newNode->donation.descriccion, descriccion, 100);
    strncpy(newNode->donation.valor, valor, 20);
    newNode->next = NULL;
    return newNode;
}

void addNodeDonationStart(nodeDonation_t* head, char* cedula, char* fecha, char* tipo, char* descriccion, char* valor){
    nodeDonation_t* newNode = createNodeDonation(cedula, fecha, tipo, descriccion, valor);

    newNode->next = head->next;

    head->next = newNode;
}

void addNodeDonationEnd(nodeDonation_t* head, char* cedula, char* fecha, char* tipo, char* descriccion, char* valor){
    nodeDonation_t* newNode = createNodeDonation(cedula, fecha, tipo, descriccion, valor);

    while (head){
        head = head->next;
    }
    head->next = newNode;
}

void printNodesDonations(nodeDonation_t* head){
    head = head->next;
    while (head){
        printf("%s-\n", head->donation.cedula);
        head = head->next;
    }
}

void freeLinkedDonations(nodeDonation_t** head){
    nodeDonation_t* temp;
    while (*head != NULL){
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}