#include "prgrm.h"
#include "Reservations.h"

void main(void){
    u32 mode,action,pass;
    u32 Find_ID,Today,slot_num;

    u8 Continue_flag=1;
    
    while(Continue_flag){        
        //Enter mode
        printf("Enter mode:\n0: Admin_mode\n1: User_mode\n2: Close System\n");
        scanf("%d",&mode);

        if (mode == Admin_mode)
        {
            printf("Enter Password: ");
            for (int i = 0; i < 3; i++) //Enter password > 3 trials
            {
                scanf("%d",&pass);
                if(pass == 1234){
                    printf("------------------------------\n");
                    printf("Successful Login in Admin mode\n");
                    printf("------------------------------\n");

                    //Enter action 

                    printf("Enter action\n"); 
                    printf("0: Add new patient record \n");
                    printf("1: Edit patient record\n");
                    printf("2: Reserve a slot with the doctor\n");
                    printf("3: Cancel reservation \n");
                    printf("4: print All Data\n");

                    scanf("%d",&action);

                    switch (action)
                    {
                        case 0: //Add new patient record, reject the entry if ID exists
                            if(start == NULL){
                                start = initialise();
                            }else{
                                addNodeEnd(start);
                            }
                            break;

                        case 1://1: Edit patient record
                            printf("Enter patient ID \n");
                            scanf("%d",&Find_ID);
                            
                            if(FindId_InDataBase(Find_ID) == 1)//ID exists
                            {
                                // allow the user to edit the patient information
                                printf("-------------------------------\n");
                                printf("Current data: \n");
                                printID(Find_ID);
                                Edit_Info(Find_ID);
                                
                            }else{
                                printf("Incorrect ID\n");
                            }
                            break;
                        
                        case 2: //Reserve a slot with the doctor
                            printf("----------------------------------------------------------------\n");
                            display_ALL_Available(); //display the available slots
                            printf("These are All the available slots of the week\n");
                            printf("----------------------------------------------------------------\n");
                            
                            printf("Enter patient ID \n");
                            scanf("%d",&Find_ID);
                            if (FindId_InDataBase(Find_ID) ==0)
                            {
                                printf("ID not found\n");
                            }else{
                                printf("Enter the Reservation Day: \n");
                                printf("0: monday -> 6: sunday\n");
                                scanf("%d",&Today);
                                Print_AvailableSlots(Today);
                                
                                scanf("%d",&slot_num);
                                
                                ReserveSlot(Find_ID,Today,slot_num);
                                printf("Slot sucessfully reserved\n");
                            }
                            break;

                        case 3: // Cancel reservation 
                            printf("Enter patient ID \n");
                            scanf("%d",&Find_ID);
                            CancelReservation(Find_ID);
                            break;
                        case 4:
                            printList();
                            break;
                        default:
                            printf("invalid Admin feature");
                            break;
                    }
                    
                    
                    
                    break;
                }else{
                    if (i==2) {printf("Incorrect password for 3 times, No more tries");
                    }else{printf("try again: ");}
                }
            }
            
        }else if(mode == User_mode){ 
            printf("Enter action: \n"); 
            printf("0: View patient record \n");
            printf("1: View the reservations of today\n");
            
            scanf("%d",&action);


            switch(action){
                case 0: //View patient record
                    printf("Enter patient ID \n");
                    scanf("%d",&Find_ID);
                    printID(Find_ID); //display basic information for the patient
                    break;
                case 1: //View today’s reservations
                    printf("Enter Day: \n");
                    printf("0: monday -> 6: sunday\n");
                    scanf("%d",&Today);

                    switch(Today){//print reservation slots with the patient ID
                        case mon: display_Reserved(Reserv_mon); break;
                        case tue: display_Reserved(Reserv_tue); break;
                        case wed: display_Reserved(Reserv_wed); break;
                        case thu: display_Reserved(Reserv_thu); break;
                        case fri: display_Reserved(Reserv_fri); break;
                        case sat: display_Reserved(Reserv_sat); break;
                        case sun: display_Reserved(Reserv_sun); break;
                        default: printf("invalid reservation day\n"); break;
                    }
                    break;
                default: 
                    printf("invalid user feature\n");
                    break;
            }
        }else{
            Continue_flag =0;
            break;
        }
    }
}