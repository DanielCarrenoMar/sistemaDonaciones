#include "../structs.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

void addNodeDonationStart(nodeDonation_t* head, Donation_t donation){
    nodeDonation_t* newNode = malloc(sizeof(nodeDonation_t));
    newNode->donation = donation;

    newNode->next = head->next;

    head->next = newNode;
}

void addNodeDonationEnd(nodeDonation_t* head, Donation_t donation){
    nodeDonation_t* newNode = malloc(sizeof(nodeDonation_t));
    newNode->donation = donation;
    newNode->next = NULL;

    while (head->next != NULL){
        head = head->next;
    }
    head->next = newNode;
}

void printNodesDonations(nodeDonation_t* head){
    while (head!= NULL){
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