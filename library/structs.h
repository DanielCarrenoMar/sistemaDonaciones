#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct Donation
{
    char cedula[30];
    char fecha[20];
    char tipo[20];
    char valor[20]; 
    char descriccion[100];
    char destino;
}Donation_t;

typedef struct User
{
    char nombre[20];
    char cedula[30];
    char telefono[30];
    char direccion[30];
}User_t;

typedef struct nodeDonation
{
    Donation_t donation;
    struct nodeDonation* next;
}nodeDonation_t;

typedef struct need
{
    char id;
    char name[20];
    char description[100];
    int goal;
}need_t;

#endif
