/**
Single Link List implementation
Code written by Abdus Sukkur
Contact:
    FB: fb.com/abdussukkur85
    mail: abdussukkur73@gmail.com
**/
#include<stdio.h>
#include<stdlib.h>

typedef struct slinklist{
    int data;
    struct slinklist *next;
}node;

node *start = NULL, *last = NULL;

int menu();
node *getnode();
void createlist(int n);
int countnode();
void insert_at_beg();
void insert_at_end();
void insert_at_mid();
void delete_at_first();
void delete_at_end();
void delete_at_mid();
void traverse();
void rev_traverse();


int main(){
    int ch, n;
    while(1){
        ch = menu();
        switch(ch){
            case 1:
                if(start == NULL){
                    printf("\nNumber of nodes you want to create: ");
                    scanf("%d", &n);
                    createlist(n);
                }else{
                    printf("\nList is already created");
                }
            break;

            case 2:
                insert_at_beg();
            break;

            case 3:
                insert_at_end();
            break;

            case 4:
                insert_at_mid();
            break;

            case 5:
                delete_at_first();
            break;

            case 6:
                delete_at_end();
            break;

            case 7:
                delete_at_mid();
            break;

            case 8:
                traverse();
            break;

            case 9:
                rev_traverse(start);
            break;

            case 10:
                printf("\nNo of nodes: %d",countnode(start));
            break;

            case 11:
                exit(0);
        }
    }
}

/// Menu Function
int menu(){
    int ch;
    printf("\n\n 1. Create a List");
    printf("\n\n------------------------------");
    printf("\n 2. Insert a node at Beginning");
    printf("\n 3. Insert a node at End");
    printf("\n 4. Insert a node at Middle");
    printf("\n\n----------------------------- ");
    printf("\n 5.Delete a node from Beginning");
    printf("\n 6.Delete a node from End");
    printf("\n 7.Delete a node from Middle");
    printf("\n\n----------------------------- ");
    printf("\n 8. Traverse the list (Left to Right)");
    printf("\n 9. Traverse the list (Right to Left)");
    printf("\n\n------------------------------");
    printf("\n 10. Count nodes");
    printf("\n 11. Exit");
    printf("\n\n Enter your choice:");
    scanf("%d",&ch);
    return ch;
}

/// get node function create a node
node *getnode(){
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    printf("\nEnter a data: ");
    scanf("%d",&newnode->data);
    newnode->next = NULL;
    return newnode;
}

///Count node function count all the node
int countnode(node *ptr){
    int count = 0;
    while(ptr != NULL){
        count++;
        ptr = ptr->next;
    }
    return count;
}

/// Create list function create for node listing
void createlist(int n){
    int i;
    node *newnode;
    node *temp;
    for(i=0; i<n; i++){
        newnode = getnode();
        if(start == NULL){
            start = newnode;
            last = newnode;
        }
        else{
            last->next = newnode;
            last = newnode;
        }
    }
}

/// Insert node at beginning
void insert_at_beg(){
    node *newnode;
    newnode = getnode();
    if(start == NULL){
        start = newnode;
    }else{
        newnode->next = start;
        start = newnode;
    }
}

/// Insert node at end
void insert_at_end(){
    node *newnode;
    newnode = getnode();
    if(start == NULL){
        start = newnode;
        last = newnode;
    }else{
        last->next = newnode;
        last = newnode;
    }
}

/// Insert node at middle
void insert_at_mid(){
    node *newnode, *temp, *prev;
    int pos, nodectr, ctr = 1;
    printf("\nEnter the position: ");
    scanf("%d",&pos);
    nodectr = countnode(start);
    if(pos>1 && pos<nodectr){
        newnode = getnode();
        temp = prev = start;
        while(ctr<pos){
            prev = temp;
            temp = temp->next;
            ctr++;
        }
        prev->next = newnode;
        newnode->next = temp;
    }else{
        printf("\nPosition %d is not a middle position",pos);
    }
}

/// Delete the first node
void delete_at_first(){
    node *temp;
    if(start == NULL){
        printf("\nNo nodes are exits...");
        return;
    }else{
        temp = start;
        start = temp->next;
        free(temp);
        printf("\nNode deleted...");
    }
}

/// Delete the last node
void delete_at_end(){
    node *temp, *prev;
    if(start == NULL){
        printf("\nEmpty list...");
        return;
    }else{
        temp = start;
        prev = start;
        while(temp->next != NULL){
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        last = prev;
        free(temp);
        printf("\nNode deleted...");
    }
}

///Delete node at the middle position
void delete_at_mid(){
    int pos,ctr = 1,nodectr;
    if(start == NULL){
        printf("\nList is empty...");
        return;
    }
    printf("\nEnter the position of node to delete: ");
    scanf("%d", &pos);
    nodectr = countnode(start);
    if(pos>1 && pos<nodectr){
        node *temp, *prev;
        temp = prev = start;
        while(ctr<pos){
            prev = temp;
            temp = temp->next;
            ctr++;
        }
        prev->next = temp->next;
        free(temp);
        printf("\nNode deleted...");

    }else{
        printf("\nInvalid position");
    }

}

/// Traverse List (Left to Right)
void traverse(){
    node *temp;
    temp = start;
    printf("\n The contents of List (Left to Right):\n");
    if(start == NULL){
        printf("\nList is empty...");
        return;
    }else{
        while(temp != NULL){
            printf("%d-->",temp->data);
            temp = temp->next;
        }
        printf("X");
    }
}

/// Reverse Traverse List (Right to Left)
void rev_traverse(node *start){
    if(start == NULL){
        return;
    }else{
        rev_traverse(start->next);
        printf("%d-->",start->data);
    }
}
