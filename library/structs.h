#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct Donation
{
    char cedula[40];
    char fecha[20];
    int tipo;
    char valor[20]; 
    char descriccion[100];
    int destino;
}Donation_t;

typedef struct User
{
    char nombre[40];
    char cedula[40];
    char telefono[40];
    char direccion[40];
}User;

typedef struct nodeDonation
{
    Donation_t donation;
    struct nodeDonation* next;
}NodeDonation;

typedef struct need
{
    char name[40];
    char description[100];
    int goal;
    int type;
}Need;

#endif
