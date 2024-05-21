#ifndef txtHandler_H
#define txtHandler_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

int countUsers();
void loadDonations(NodeDonation* head, char* file_name);
void loadUsers(User** users, char* file_name);
void verUsers(User** users);
void freeUsers(User** users, int size);

#include "./code/txtHandler.c"

#endif