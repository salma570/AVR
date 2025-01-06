
#include "clinic_int.h"
static node* start= NULL;

u32 count_Nodes(){
    node* start_Copy = start;
    u32 count = 0;
    node* move = start_Copy;
    while(move!=NULL){
        move = move->NEXT;
        count++;
    } 
    return count;
}
node* initialise(){
    node* head= (node*)malloc(sizeof(node));
    head->NEXT = NULL;

    printf("enter name: ");
    scanf("%s",&head->name);

    printf("enter age: ");
    scanf("%d",&head->age);

    printf("enter gender: m or f");
    scanf(" %c",&head->gender);

    printf("enter ID (0 is not accepted):");
    
    u32 Local_ID;
    scanf("%d",&Local_ID);

    while (Local_ID == 0){
        printf("invalid ID try again");
        printf("Enter ID: (0 is not accepted): ");
        scanf("%d",&Local_ID);
    }
    head->ID = Local_ID;

    return head;
}
void addNodeEnd(){
    printf("enter ID (0 is not accepted):  ");
    u32 Local_ID;
    scanf("%d",&Local_ID);

    while (Local_ID ==0){
        printf("invalid ID try again");
        printf("enter ID (0 is not accepted");
        scanf("%d",&Local_ID);
    }

    if(FindId_InDataBase(Local_ID)==0)//not found
    {
        node* newNode = (node*)malloc(sizeof(node));
        node* current= start;
        
        if (current!= NULL)
        while (current->NEXT !=NULL)
        {
            printf("here");
            current = current->NEXT;
        }//current is the last node
        

        current->NEXT = newNode;
        newNode->NEXT = NULL;

        printf("enter name: ");
        scanf("%s",&newNode->name);

        printf("enter age: ");
        scanf("%d",&newNode->age);

        printf("enter gender:  m or f");
        scanf(" %c",&newNode->gender);

        newNode->ID =Local_ID;

    }else{
        printf("Invalid ID");
    }
    
    
}
void printID(u32 Find_ID){
    u16 found = 0;
    printf("-------------------------\n");
    if(start == NULL ){
        found =0;
    }else{
        node * move = start;
        int i=1;
        while(move !=NULL)
        {
            if(move->ID == Find_ID){
                found =1;
                printf("%d name: %s\n",i++,move->name);
                printf("%d age: %d\n",i++,move->age);
                printf("%d gender: %c\n",i++,move->gender);
                break;
            }
            move=move->NEXT;   
        }
    }
    if(!found){
        printf("ID not found");
    }
    printf("-------------------------\n");
}
void printList(){
    node * move = start;
    printf("-------------------------\n");
    if(move == NULL ){
        printf ("List is empty, No data Entered\n");
    }else{
        int i=1;
        while(move !=NULL)
        {
            printf("%d name: %s\n",i++,move->name);
            printf("%d age: %d\n",i++,move->age);
            printf("%d gender: %c\n",i++,move->gender);
            printf("%d ID: %d\n",i++,move->ID);
            move=move->NEXT;   
        }
    }
    printf("-------------------------\n");
}
void RemoveValue(){// middle, end w/duplicates, empty list, value dne
    u32 value;
    printf("enter value to remove: ");
    scanf("%d",&value);  
    node * current = start;
    node * previous = NULL;
    while (current !=NULL){
        if(current->ID == value){
            if (previous == NULL)//remove beginning
            {
                if(start->NEXT==NULL){//has no other values >  empty list        
                    printf("start->NEXT==NULL");
                    start = NULL;
                    break;
                }else{//has other elements in the lists> check others
                    printf("start->NEXT!=NULL");
                    start = start->NEXT;
                    current = start;
                }
            }else if (current->NEXT!=NULL){//remove middle
                previous->NEXT = current->NEXT;
                current=current->NEXT;
            }else{//remove Last
                previous->NEXT= NULL;
                current = previous;
            }
        }else{
            previous=current;
            current=current->NEXT;
        }   
    }
}
void Insert(){
    u32 position; 
    printf("enter position to insert after: ");
    scanf("%d", &position);
    if (position==0){//no negative >> unsined num
        printf("invalid position\n\n");
        return;
    }

    u32 count =1;
    node * current = start;
    
    if (count_Nodes(start)<position)// if index out of bound add at the end of the list
    {
        addNodeEnd();
        //printf("while 0 ");
    }else{
        while (current!=NULL){
            if(position == count){//add node
                //printf("while 1 ");
                node*newNode = (node*)malloc(sizeof(node));
                
                newNode ->NEXT = current->NEXT;
                current->NEXT = newNode;

                printf("enter name: ");
                scanf("%s",&newNode->name);

                printf("enter age: ");
                scanf("%d",&newNode->age);

                printf("enter gender:  m or f");
                scanf(" %c",&newNode->gender);

                printf("enter ID (0 is not accepted)");
                scanf("%d",&newNode->ID);
                break;
            }else{
                //printf("while 2,%d ",current->data);
                count++;
                current=current->NEXT;
            }

        }
    }
}
u32 FindId_InDataBase(u32 Find_ID){
    u16 found =0;
    node * move = start;
    while(move !=NULL)
    {
        if(move->ID == Find_ID){
            found = 1;
            break;
        }
        move=move->NEXT;   
    }
    return found;
}
void Edit_Info(u32 Find_ID){
    node * move = start;
    while(move !=NULL)
    {
        if(move->ID == Find_ID){
            printf("enter name: ");
            scanf("%s",&move->name);
            printf("enter age: ");
            scanf("%d",&move->age);
            printf("enter gender:  m or f");
            scanf(" %c",&move->gender);
            break;
        }
        move=move->NEXT;   
    }
}