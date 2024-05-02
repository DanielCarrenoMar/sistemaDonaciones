#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct Donation
{
    char fecha[20];
    char tipo[20];
    char descriccion[100];
    char valor[20]; 
}Donation_t;

typedef struct User
{
    char nombre[20];
    char cedula[30];
    char telefono[30];
    char direccion[30];
    Donation_t** donaciones;
}User_t;



typedef struct ActDonation
{
    int fecha;
    char tipo[20];
    char descriccion[100];
    int valor; 
    struct ActDonation* next;
}ActDonation_t;

typedef struct ActUser
{
    char nombre[20];
    int cedula;
    int telefono;
    char direccion[20];
    ActDonation_t* donaciones;
}ActUser_t;

#endif
