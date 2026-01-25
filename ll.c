#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Write functions to: a) Add and delete the
members as well as president or even secretary. b) Compute total number of members of club c)
Display members d) sorting of two linked list e) merging of two linked list f) Reversing using
three pointers*/

typedef struct node{
    int prn;
    char name[20];
    struct node *next;
}node;
int length(node *head);
void menu(){
    printf("\nDo you want to insert another node?\n");
}

void menu1(node *curr){
        printf("\nEnter the prn number:\n");    
        scanf("%d", &curr->prn);
        printf("\nEnter the name:\n");
        scanf("%s", curr->name);
}

void menu2(){
    printf("\n-----MENU-----\n");
    printf("1. Create Linked List\n");
    printf("2. Display Linked List\n");
    printf("3. Insert Node\n");
    printf("4. Length of Linked List\n");
    printf("5. Reverse Linked List\n");
    printf("6. Delete Node by Position\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
}

void create(node *head){
    node *temp = head;
    menu();
    char choice = 'y';
    scanf(" %c", &choice);
    while(choice == 'y'){
        node *curr = (node *)malloc(sizeof(node));
        menu1(curr);
        curr->next = NULL;
        temp->next = curr;
        temp = curr;
        menu();
        scanf(" %c", &choice);
    }
}

void display(node *head){
    if(head->next == NULL){
        printf("\nThe list is empty.\n");
    }
    else{
        node *curr = head->next;
        int count = 0;
        while(curr != NULL){
            printf("\n%d\t%s\n", curr->prn, curr->name);
            count++;
            curr = curr->next;
        }
        printf("\nLength of the linked list is: %d\n", count);
    }
}

void insert(node *head) {
    int i = 0, pos = 0;
    printf("\nAt what position do you want to insert the new node?\n");
    scanf("%d", &pos);
    int len = length(head);
    
    // Check if the position is within the valid range
    if (pos > len + 1 || pos < 1) {
        printf("\nInvalid position to enter the node.\n");
        return;
    }
    
    // Create the new node and take user input
    node *nnode = (node *)malloc(sizeof(node));
    if (nnode == NULL) {
        printf("\nMemory allocation failed.\n");
        return;
    }
    menu1(nnode);
    nnode->next = NULL;

    // Insert at the beginning (position 1)
    if (pos == 1) {
        nnode->next = head->next;
        head->next = nnode;
        return;
    }

    // Traverse to the node just before the insertion point
    node *curr = head;
    for (i = 1; i < pos - 1 && curr != NULL; i++) {
        curr = curr->next;
    }

    // Insert the new node at the specified position
    if (curr != NULL) {
        nnode->next = curr->next;
        curr->next = nnode;
    }
}

int length(node *head){
    if(head->next == NULL){
        printf("\nThe list is empty.\n");
        return 0;
    }
    else{
        node *curr = head->next;
        int count = 0;
        while(curr != NULL){
            // printf("\n%d\t%s\n", curr->prn, curr->name);
            count++;
            curr = curr->next;
        }
        return count;

    }
}

void reverse(node *head){
    if (head->next == NULL) {
        printf("LIST IS EMPTY\n");
        return;
    }
    struct node *prev = NULL;
    struct node *curr = head->next;
    struct node *next = NULL;
    
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head->next = prev;
    printf("LINKED LIST REVERSED\n");
}

void delete(node *head){
    int pos = 0, i = 0;
    printf("ENTER POSITION TO DELETE: ");
    scanf("%d", &pos);
    int len = length(head);
    if (pos > len || pos < 1) {
        printf("CANNOT DELETE AT THIS POSITION\n");
    }
    else{
        node *curr = head;
        node *prev = NULL;
        
        while (curr != NULL && i < pos) {
            prev = curr;
            curr = curr->next;
            i++;
        }
        if (curr != NULL) {
            prev->next = curr->next;
            free(curr);
            printf("NODE AT POSITION %d DELETED\n", pos);
        }
    }
    
}

int main(){
    node *head = (node *)malloc(sizeof(node));
    head->next = NULL;
    
    int choice;
    do{
        menu2();
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                create(head);
                break;
            case 2:
                display(head);
                break;
            case 3:
                insert(head);
                break;
            case 4:
                int count = length(head);
                printf("\nLength of the linked list is: %d\n", count);
                break;
            case 5:
                reverse(head);
                break;
            case 6:
                delete(head);
                break;
            case 7:
                printf("\nExiting Program\n");
                break;
            default:
                printf("\nInvalid choice, please try again.\n");
        }
        
    }while(choice != 7);
}