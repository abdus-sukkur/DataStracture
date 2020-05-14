/**
Circular Queue implementation with Array
Code written by Abdus Sukkur
Contact:
    FB: fb.com/abdussukkur85
    mail: abdussukkur73@gmail.com
**/
#include<stdio.h>
#define MAX 6

int CQ[MAX];
int front = 0, rear =  0, count = 0;

int menu();
void insertCQ();
void deleteCQ();
void displayCQ();

void main(){
    int ch;
    do{
        ch = menu();
        switch(ch){
            case 1:
                insertCQ();
                break;

            case 2:
                deleteCQ();
                break;

            case 3:
                displayCQ();
                break;

            case 4:
                exit(0);
        }
    } while(1);
}

/// Menu Function
int menu()
{
    int ch;
    printf("\n \t Circular Queue Operations using ARRAY..");
    printf("\n -----------**********-------------\n");
    printf("\n 1. Insert ");
    printf("\n 2. Delete ");
    printf("\n 3. Display");
    printf("\n 4. Quit ");
    printf("\n Enter Your Choice: ");
    scanf("%d", &ch);
    return ch;
}

/// Enqueue data in Circular Queue
void insertCQ(){
    int data;
    if(count == MAX){
        printf("\nCircular Queue is Full");
        return;
    }else{
        printf("\nEnter a data: ");
        scanf("%d", &data);
        CQ[rear] = data;
        rear = (rear + 1) % MAX;
        count++;
    }
}

/// Dequeue data form Circular Queue
void deleteCQ(){
    if(count == 0){
        printf("\nCircular Queue is Empty...");
        return;
    }else{
        printf("\nDelete element form circular Queue is: %d",CQ[front]);
        front = (front + 1) % MAX;
        count--;
    }
}

/// Display Circular Queue
void displayCQ(){
    if(count == 0){
        printf("\nCircular Queue is Empty");
        return;
    }else{
        int j = count;
        printf("\nElements in Circular Queue are:");
        for(int i=front; j!=0; j--){
            printf("\t%d",CQ[i]);
            i = (i + 1) % MAX;
        }
    }
}

