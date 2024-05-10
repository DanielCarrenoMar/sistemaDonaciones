#ifndef txtHandler_H
#define txtHandler_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

int countUsers();
void loadDonations(nodeDonation_t* head, char* file_name);
void loadUsers(User_t** users, char* file_name);
void verUsers(User_t** users);
void freeUsers(User_t** users);

#include "./code/txtHandler.c"

#endif