/**
Stack Implementation using Link list
Code written by Abdus Sukkur
Contact:
    FB: fb.com/abdussukkur85
    mail: abdussukkur73@gmail.com
**/
#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
    int data;
    struct stack *next;
}node;

node *start = NULL, *top = NULL;

node *getnode();
int menu();
void push(node *newnode);
void pop();
void display();

/// Main Function
void main(){
    int ch;
    node *newnode;
    do{
        ch = menu();
        switch(ch){
            case 1:
                newnode = getnode();
                push(newnode);
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

/// Main menu
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

/// get node function will create a new node
node *getnode(){
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    printf("\nEnter a data: ");
    scanf("%d",&newnode->data);
    newnode->next = NULL;
    return newnode;
}

/// Push data in stack
void push(node *newnode){
    node *temp;
    if(newnode == NULL){
        printf("\nStack overflow...");
        return;
    }

    if(start == NULL){
        start = newnode;
        top = newnode;
    }else{
        temp = start;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
        top = newnode;
        temp = newnode;
    }
    printf("\n\nData pushed into stack");
}

/// Pop data from stack
void pop(){
    node *temp;
    if(top == NULL){
        printf("\n\nStack underflow");
        return;
    }
    temp = start;
    if(start->next == NULL){
        printf("\n\nPopped element is %d",top);
        start = NULL;
        free(top);
        top = NULL;
    }else{
        while(temp->next != top){
            temp = temp->next;
        }
        temp->next = NULL;
        printf("\n\nPopped element is %d",top->data);
        free(top);
        top = temp;
    }
}

void display(){
    node *temp;
    if(top == NULL){
        printf("\n\nStack is empty");
        return;
    }else{
        temp = start;
        printf("\n\nElements in the stack:");
        printf("\t%d", temp->data);
        while(temp != top){
            temp = temp->next;
            printf("\t%d", temp->data);

        }
    }
}

