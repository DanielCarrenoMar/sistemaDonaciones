#ifndef linkedDonations_h
#define linkedDonations_h

NodeDonation* createNodeDonation(char* cedula, char* fecha, int tipo, char* valor, char* descriccion, int destino);
void addNodeDonationStart(NodeDonation* head, char* cedula, char* fecha, int tipo, char* valor, char* descriccion, int destino);
void addNodeDonationEnd(NodeDonation* head, char* cedula, char* fecha, int tipo, char* valor, char* descriccion, int destino);
void printNodesDonations(NodeDonation* head);
void freeLinkedDonations(NodeDonation** head);

#include "./code/linkedDonations.c"

#endif