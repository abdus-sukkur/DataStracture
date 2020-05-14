/**
Doubly Link List implementation
Code written by Abdus Sukkur
Contact:
    FB: fb.com/abdussukkur85
    mail: abdussukkur73@gmail.com
**/
#include<stdio.h>
#include<stdlib.h>
typedef struct dlinked_list{
    int data;
    struct dlinked_list *next;
    struct dlinked_list *prev;
}node;

node *head = NULL, *tail = NULL;


node* getnode();
int menu();
void createlist(int n);
int countnode(node *head);
void dll_insert_beg();
void dll_insert_end();
void dll_insert_mid();
void dll_delete_beg();
void dll_delete_last();
void traverse_left_to_right();
void traverse_right_to_left();

void main(){
    int ch, n;
    while(1){
        ch = menu();
        switch( ch){
            case 1 :
                if(head == NULL){
                    printf("\n Enter Number of nodes to create: ");
                    scanf("%d", &n);
                    createlist(n);
                    printf("\n List created..");
                }else{
                    printf("\nList is created...");
                }

            break;

            case 2 :
                dll_insert_beg();
            break;

            case 3 :
                dll_insert_end();
            break;

            case 4 :
                dll_insert_mid();
            break;

            case 5 :
                dll_delete_beg();
            break;

            case 6 :
                dll_delete_last();
            break;

            case 7 :
                dll_delete_mid();
            break;

            case 8 :
                traverse_left_to_right();
            break;

            case 9 :
                traverse_right_to_left();
            break;

            case 10 :
                printf("\n Number of nodes: %d", countnode(head));
            break;

            case 11:
                exit(0);
        }
    }
}

///Menu Function
int menu(){
    int ch;
    printf("\n 1.Create List...");
    printf("\n------------------------------");
    printf("\n 2. Insert a node at beginning ");
    printf("\n 3. Insert a node at end");
    printf("\n 4. Insert a node at middle");
    printf("\n------------------------------");
    printf("\n 5. Delete a node from beginning");
    printf("\n 6. Delete a node from Last");
    printf("\n 7. Delete a node from Middle");
    printf("\n------------------------------");
    printf("\n 8. Traverse the list from Left to Right ");
    printf("\n 9. Traverse the list from Right to Left ");
    printf("\n------------------------------");
    printf("\n 10.Count the Number of nodes in the list");
    printf("\n 11.Exit ");
    printf("\n\n Enter your choice: ");
    scanf("%d", &ch);
    return ch;
}
/// getnode function create and return
node* getnode(){
    node *newnode;
    newnode = (node *) malloc(sizeof(node));
    printf("\nEnter a data: ");
    scanf("%d", &newnode->data);
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}

/// Create list function create a list of nodes
void createlist(int n){
    node *newnode, *temp;
    for(int i=0; i<n; i++){
        newnode = getnode();
        if(head == NULL){
            head = newnode;
            tail = newnode;
            temp = newnode;
        }else{
            tail = newnode;
            tail->prev = temp;
            temp->next = tail;
            temp = newnode;
        }
    }
}

///Count all the nodes
int countnode(node *head){
    int count = 0;
    while(head != NULL){
        count ++;
        head = head->next;
    }
    return count;
}

/// Insert node at beginning
void dll_insert_beg(){
    node *newnode;
    newnode = getnode();
    if(head == NULL){
        head = newnode;
        tail = newnode;
    }else{
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}

/// Insert node at end
void dll_insert_end(){
    node *newnode;
    newnode = getnode();
    if(head == NULL){
        head = newnode;
        tail = newnode;
    }else{
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}

/// Insert node at the middle point(selected node point)
void dll_insert_mid(){
    node *newnode, *temp;
    int pos, nodectr, count = 1;
    printf("\nEnter the position: ");
    scanf("%d", &pos);
    nodectr = countnode(head);
    if(pos>1 && pos<nodectr){
        newnode = getnode();
        temp = head;
        while(count<pos){
            temp = temp->next;
            count++;
        }
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next->prev = newnode;
        temp->next = newnode;
    }else{
        printf("\nPosition %d is not a middle position",pos);
    }
}

///Delete node form the beginning
void dll_delete_beg(){
    node *temp;
    if(head == NULL){
        printf("\nEmpty List...");
        return;
    }else{
        temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
    }
}

///Delete node form the end
void dll_delete_last(){
    node *temp;
    if(head == NULL){
        printf("\nEmpty list...");
        return;
    }else{
        temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        free(temp);
    }
}


/// Delete node form the middle(selected position)
void dll_delete_mid(){
    node *temp;
    int pos, nodectr, count = 1;
    if(head == NULL){
        printf("\nEmpty List...");
        return;
    }else{
        printf("\nEnter the position of the node to delete: ");
        scanf("%d", &pos);
        nodectr = countnode(head);

        if(pos>nodectr){
            printf("\nthis node does not exist");
            return;
        }

        if(pos>1 && pos<nodectr){
            temp = head;
            while(count<pos){
                temp = temp->next;
                count++;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp);
            printf("\nNode deleted...");
        }else{
            printf("\nPosition %d is not a middle position\n",pos);
        }
    }
}

///Traverse Left to right
void traverse_left_to_right(){
    node *temp;
    temp = head;
    printf("\nThe contents of list: ");
    if(head == NULL){
        printf("\nEmpty List");
        return;
    }else{
        while(temp != NULL){
            printf("\t%d", temp->data);
            temp = temp->next;
        }
    }

}

///Reverse Traverse Right to left
void traverse_right_to_left(){
    node *temp;
    temp = tail;
    printf("\nThe contents of list: ");
    if(head == NULL || tail == NULL){
        printf("\nList is empty...");
        return;
    }else{
        while(temp != NULL){
            printf("\t%d",temp->data);
            temp = temp->prev;
        }
    }
}
