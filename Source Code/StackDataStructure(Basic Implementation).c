/**
    Stack Data Structure.
    Implemented by Abdus Sukkur.
    Facebook: facebook.com/abdussukkur85
**/
#include<stdio.h>
#define stackSize 5
int myStack[stackSize], top = -1, MAXSIZE = 5;

int isEmpty(){
    if(top == -1)
        return 1;
    else
        return 0;
}

int isFull(){
    if(top == stackSize)
        return 1;
    else
        return 0;
}

void peek(){
    if(!isEmpty()){
        printf("Top Value is: %d", myStack[top]);
    }else{
         printf("Stack is Empty\n");
    }

}

void push(int value){
    if(!isFull()){
        printf("PUSH: %d\n",value);
        myStack[++top] = value;
    }else{
        printf("Stack is Full!\n");
    }
}

void pop(){
    if(!isEmpty()){
        printf("Poped %d, form stack\n",myStack[top]);
        top--;
    }else{
        printf("Stack is Empty\n");
    }
}

void displayStack(){
    printf("\nPrint the full stact form TOP to BOTTOM:\n");
    int i;
    for(i=top; i>=0; i--){
        printf("%d\n",myStack[i]);
    }
}


int main(){
    push(5);
    push(54);
    push(12);
    push(40);
    push(23);
    push(26);
    displayStack();

    pop();
    pop();
    displayStack();

    peek();
    return 0;
}

