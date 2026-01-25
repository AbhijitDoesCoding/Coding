#include <stdio.h>
#include <stdlib.h>

struct node {
    int prn;
    char name[20];
    struct node *next;
};

void create(struct node *head) {
    struct node *temp = head;
    int choice;
    do {
        struct node *curr = (struct node *) malloc(sizeof(struct node));
        printf("ENTER PRN: ");
        scanf("%d", &curr->prn);
        printf("ENTER NAME: ");
        scanf("%s", curr->name);
        curr->next = NULL;
        temp->next = curr;
        temp = curr;
        printf("ENTER 1 TO ADD MORE NODES, 0 TO STOP: ");
        scanf("%d", &choice);
    } while(choice == 1);
}

void display(struct node *head) {
    if (head->next == NULL) {
        printf("LIST IS EMPTY\n");
    } else {
        struct node *curr = head->next;
        int count = 0;
        while(curr != NULL) {
            printf("%d\t%s\n", curr->prn, curr->name);
            curr = curr->next;
            count++;
        }
        printf("LENGTH OF LINKED LIST IS: %d\n", count);
    }
}

void reverse(struct node *head) {
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

int length(struct node *head) {
    if (head->next == NULL) {
        printf("LIST IS EMPTY\n");
        return 0;
    } else {
        int i = 0;
        struct node *curr = head->next;
        while(curr != NULL) {
            i++;
            curr = curr->next;
        }
        printf("LENGTH OF LINKED LIST IS: %d\n", i);
        return i;
    }
}

void insertion(struct node *head) {
    int i = 0, pos;
    struct node *curr = head;
    struct node *nnode = (struct node *) malloc(sizeof(struct node));
    printf("ENTER PRN: ");
    scanf("%d", &nnode->prn);
    printf("ENTER NAME: ");
    scanf("%s", nnode->name);
    nnode->next = NULL;
    printf("ENTER POSITION TO INSERT: ");
    scanf("%d", &pos);
   
    int len = length(head);
    if(pos > len + 1 || pos < 1) {
        printf("CANNOT INSERT AT THIS POSITION\n");
    } else {
        while(curr != NULL && i < pos - 1) {
            i++;
            curr = curr->next;
        }
        nnode->next = curr->next;
        curr->next = nnode;
    }
}

void delete_by_position(struct node *head) {
    int pos, i = 0;
    printf("ENTER POSITION TO DELETE: ");
    scanf("%d", &pos);
   
    int len = length(head);
    if (pos > len || pos < 1) {
        printf("CANNOT DELETE AT THIS POSITION\n");
    } else {
        struct node *curr = head;
        struct node *prev = NULL;

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

void menu() {
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

int main() {
    struct node *head = (struct node *) malloc(sizeof(struct node));
    head->next = NULL;
   
    int choice;
    do {
        menu();
        scanf("%d", &choice);
       
        switch(choice) {
            case 1:
                create(head);
                break;
            case 2:
                display(head);
                break;
            case 3:
                insertion(head);
                break;
            case 4:
                length(head);
                break;
            case 5:
                reverse(head);
                break;
            case 6:
                delete_by_position(head);
                break;
            case 7:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while(choice != 7);
   
    return 0;
}
