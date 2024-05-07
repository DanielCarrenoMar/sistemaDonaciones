#ifndef txtHandler_H
#define txtHandler_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

int countDonations();
int countUsers();
void cargarDonations(Donation_t** users, char* file_name);
void cargarUsers(User_t** users, char* file_name);
void verDonations(Donation_t** users);
void verUsers(User_t** users);
void freeDonation(Donation_t** users);
void freeUsers(User_t** users);

#include "./code/txtHandler.c"

#endif