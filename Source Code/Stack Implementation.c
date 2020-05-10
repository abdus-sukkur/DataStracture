/**
Stack implementation with Array
Code written by Abdus Sukkur
Contact:
    FB: fb.com/abdussukkur85
    mail: abdussukkur73@gmail.com
**/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define MAX 6
int  stack[MAX];
int top = 0;

int menu(){
    int ch;
    printf("\n... Stack operations using ARRAY...");
    printf("\n..........**********..........\n");
    printf("\n 1. Push");
    printf("\n 2. Pop");
    printf("\n 3. Display");
    printf("\n 4. Quit");
    printf("\n Enter your choice:");
    scanf("%d", &ch);
    return ch;
}

void push(){
    int data;
    if(top == MAX){
        printf("\n\nStack Overflow...");
        return;
    }else{
        printf("\n\nEnter data: ");
        scanf("%d",&data);
        stack[top] = data;
        top++;
        printf("\n\nData pushed into the stack\n");
    }
}

void pop(){
    if(top == 0){
        printf("\n\nStack underflow...\n");
        return;
    }else{
        printf("\n\nPopped element is %d\n",stack[--top]);
    }
}

void display(){

    if(top == 0){
        printf("\n\nStack is empty...\n");
        return;
    }else{
        printf("\n\nElements in stack:");
        for(int i=0; i<top; i++){
            printf("\t%d",stack[i]);
        }
        printf("\n");
    }

}

void main(){
    int ch;
    do{
        ch = menu();
        switch(ch){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);

        }
    }while(1);
}