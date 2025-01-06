#ifndef CLINIC_INT_H_
#define CLINIC_INT_H_

#include <stdio.h>
#include "std_types.h"
#include <stdlib.h>

// struct in interface because of return type node* is defined

typedef struct typenode node;
struct typenode
{
    char name[100];
    u32 age;
    u8 gender; // m or f
    u32 ID;
    node* NEXT;
};

//prgm.h

#define Admin_mode 0
#define User_mode 1

u32 count_Nodes();
node* initialise();
void addNodeEnd();
void printList();
void RemoveValue();
void Insert();

void printID(u32 Find_ID);
u32 FindId_InDataBase(u32 Find_ID);
void Edit_Info(u32 Find_ID);

//Reservations.h
void display_current(u32 day[]);
void display_Available(u32 day[]);
void display_Reserved(u32 day[]);
void display_ALL_Available();
void CancelReservation(u32 Find_ID);
void ReserveSlot(u32 Find_ID, u32 Today, u32 slot_num);
void Print_AvailableSlots(u32 Today);


#endif