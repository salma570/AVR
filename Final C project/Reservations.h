#include <stdio.h>
#include "std_types.h"

enum Days {mon, tue, wed, thu, fri, sat, sun};
char slots [][14] = {"2pm to 2:30pm","2:30pm to 3pm", "3pm to 3:30pm","4pm to 4:30pm","4:30pm to 5pm"};



u32 Reservations [7][5] = {{0,0,0,0,0},{0,0,0,0,0},
                        {0,0,0,0,0},{0,0,0,0,0},
                        {0,0,0,0,0},{0,0,0,0,0},
                        {0,0,0,0,0}};


u32 *Reserv_mon = Reservations[0];
u32 *Reserv_tue = Reservations[6];
u32 *Reserv_wed = Reservations[11];
u32 *Reserv_thu = Reservations[16];
u32 *Reserv_fri = Reservations[21];
u32 *Reserv_sat = Reservations[26];
u32 *Reserv_sun = Reservations[31];

void display_current(u32 day[]){
    for(int i =0; i<5;i++){
        printf("%s: %d\n",slots[i],day[i]);
    }
}
void display_Available(u32 day[]){
    for(int i =0; i<5;i++){
        if(day[i]==0){
            printf("%d: %s\n",i+1,slots[i]);
        }
    }
}
void display_ALL_Available(){
    char WeekDays[][4] = {"mon","tue","wed","thu","fri","sat","sun"};

    for(int i =0; i<7;i++){
        printf("\n\n%s: \n",WeekDays[i]);
        display_Available(Reservations[i]);
    }
}
void display_Reserved(u32 day[]){
    u32 Local_flag =0;
    printf("----------------------------");
    for(int i =0; i<5;i++){
        if(day[i]!=0){
            printf("%s: %d\n",slots[i],day[i]);
            Local_flag =1;
        }
    }
    if (Local_flag==0)
    {
        printf("no Reservations for today\n");
    }
    printf("----------------------------");
    
}
void CancelReservation(u32 Find_ID){
    for(int i =0; i<7; i++){
        for(int j =0; j<5; j++){
            if(Reservations[i][j] == Find_ID){
                Reservations[i][j] = 0;
                
            }
        }
    }
    printf("All reservations of this Id are Sucessfully cancelled\n");
}
void Print_AvailableSlots(u32 Today){
    printf("Enter slot number:\n");
    switch(Today){//print reservation slots with the patient ID
        case mon: display_Available(Reserv_mon); break;
        case tue: display_Available(Reserv_tue); break;
        case wed: display_Available(Reserv_wed); break;
        case thu: display_Available(Reserv_thu); break;
        case fri: display_Available(Reserv_fri); break;
        case sat: display_Available(Reserv_sat); break;
        case sun: display_Available(Reserv_sun); break;
        default: printf("invalid action"); break;
    }
}
void ReserveSlot(u32 Find_ID, u32 Today, u32 slot_num){

    slot_num -=1; //slots pointers starts from 0 not 1
                        

    switch(Today){//reserved slot marked not-available
        case mon:
            *(Reserv_mon + slot_num) =Find_ID;
            break;
        case tue:
            *(Reserv_tue + slot_num) =Find_ID;
            break;
        case wed:
            *(Reserv_wed + slot_num) =Find_ID;
            break;
        case thu:
            *(Reserv_thu + slot_num) =Find_ID;
            break;
        case fri:
            *(Reserv_fri + slot_num) =Find_ID;
            break;
        case sat:
            *(Reserv_sat + slot_num) =Find_ID;
            break;
        case sun:
            *(Reserv_sun + slot_num) =Find_ID;
            break;
        default:
            printf("invalid action");
            break;

    }
}
