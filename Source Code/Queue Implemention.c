/**
Queue implementation with Array
Code written by Abdus Sukkur
Contact:
    FB: fb.com/abdussukkur85
    mail: abdussukkur73@gmail.com
**/
#include<stdio.h>
#include<stdlib.h>
#define MAX 6

int queue[MAX];
int front = 0, rear = 0;

int menu();
void insertQ();
void deleteQ();
void displayQ();

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

/// Menu function
int menu(){
    int ch;
    printf("\n... Queue operations using ARRAY...");
    printf("\n..........**********..........\n");
    printf("\n 1. Insert");
    printf("\n 2. Delete");
    printf("\n 3. Display");
    printf("\n 4. Quit");
    printf("\n Enter your choice:");
    scanf("%d", &ch);
    return ch;
}

/// Enqueue data in the Queue
void insertQ(){
    int data;
    if(rear == MAX){
        printf("\nLiner Queue is full");
        return;
    }else{
        printf("\nEnter data: ");
        scanf("%d", &data);
        queue[rear] = data;
        rear++;
        printf("\nData inserted in the queue");
    }
}

/// Dequeue data from the Queue
void deleteQ(){
    if(rear == front){
        printf("\nQueue is empty...");
        return;
    }else{
        printf("\nDelete element form queue",queue[front]);
        front++;
    }
}

void displayQ(){
    if(front == rear){
        printf("\nQueue is Empty...");
        return;
    }else{
        printf("\nElements in Queue are:");
        for(int i=front; i<rear; i++){
            printf("\t%d",queue[i]);
        }
    }
}
