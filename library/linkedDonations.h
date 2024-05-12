#ifndef linkedDonations_h
#define linkedDonations_h

nodeDonation_t* createNodeDonation(char* cedula, char* fecha, char* tipo, char* valor, char* descriccion, char destino);
void addNodeDonationStart(nodeDonation_t* head, char* cedula, char* fecha, char* tipo, char* valor, char* descriccion, char destino);
void addNodeDonationEnd(nodeDonation_t* head, char* cedula, char* fecha, char* tipo, char* valor, char* descriccion, char destino);
void printNodesDonations(nodeDonation_t* head);
void freeLinkedDonations(nodeDonation_t** head);

#include "./code/linkedDonations.c"

#endif