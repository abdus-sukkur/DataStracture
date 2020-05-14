/**
Queue implementation using Link List
Code written by Abdus Sukkur
Contact:
    FB: fb.com/abdussukkur85
    mail: abdussukkur73@gmail.com
**/
#include<stdio.h>
#include<stdlib.h>

typedef struct queue{
    int data;
    struct queue *next;
}node;

node *front = NULL;
node *rear = NULL;

node *getnode();
void insertQ();
void deleteQ();
void displayQ();


/// Main Function
void main(){
    int ch;
    do{
        ch = menu();
        switch(ch){
            case 1:
                insertQ();
            break;

            case 2:
                deleteQ();
            break;

            case 3:
                displayQ();
            break;

            case 4:
                exit(0);
        }
    }while(1);
}


/// Menu Function
int menu(){
    int ch;
    printf("\n \t..Queue operations using pointers.. ");
    printf("\n\t -----------**********-------------\n");
    printf("\n 1. Insert ");
    printf("\n 2. Delete ");
    printf("\n 3. Display");
    printf("\n 4. Quit ");
    printf("\n Enter your choice: ");
    scanf("%d",&ch);
    return ch;
}

/// getnode function create a new node
node *getnode(){
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    printf("\nEnter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    return newnode;
}

/// Enqueue data in the Queue
void insertQ(){
    node *newnode;
    newnode = getnode();
    if(newnode == NULL){
        printf("\n Queue Full");
        return;
    }

    if(front == NULL){
        front = newnode;
        rear = newnode;
    }else{
        rear->next = newnode;
        rear = newnode;
    }
    printf("\nData inserted in the Queue");
}

/// Dequeue data from the Queue
void deleteQ(){
    node *temp;
    if(front == NULL){
        printf("\nEmpty Queue");
        return;
    }
    temp = front;
    front = front->next;
    printf("\nDeleted element from queue is: %d",temp->data);
    free(temp);
}

/// Display the full queue
void displayQ(){
    node *temp;
    if(front == NULL){
        printf("\nEmpty Queue");
        return;
    }
    temp = front;
    printf("\nElement in the Queue are: ");
    while(temp != NULL){
        printf("\t%d",temp->data);
        temp = temp->next;
    }
}

