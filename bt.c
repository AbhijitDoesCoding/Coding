#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
} node;

node* stack[15] = {NULL};
int top = -1;

void menu(){
    printf("\n1. Non Recursive\n2. Recursive\n");
}

int isEmpty(){
    return (top == -1);    
}

int isFull(){
    return (top == 15);
}

void push(node *temp){
    if(isFull()){
        printf("Stack is Full");
    } else {
        top++;
        stack[top] = temp; 
    }
}

node* pop(){
    if(isEmpty()){
        printf("Stack is Empty");
        return NULL;
    } else {
        node* temp = stack[top];
        top--;
        return temp;
    }
}

void createnr(node *root){
    int flag = 0, option = 1;
    char s = 'y';
    do {
        node *temp = root;
        node *curr = (node *)malloc(sizeof(node));
        printf("\nEnter the data for the new node\n");
        scanf("%d", &curr->data);
        flag = 0;  // Reset flag
        curr->left = NULL;
        curr->right = NULL;
        while(!flag) {
            printf("\nDo you want to put it to the left(1) or right(0) of %d\n", temp->data);
            scanf("%d", &option);
            if(option == 1) {
                if(temp->left == NULL) {
                    temp->left = curr;
                    flag = 1;
                } else {
                    temp = temp->left;
                }
            } else {
                if(temp->right == NULL) {
                    temp->right = curr;
                    flag = 1;
                } else {
                    temp = temp->right;
                }
            }
        }
        printf("\nDo you want to add another node? (y/n)\n");
        scanf(" %c", &s);  // Clear leading whitespace
    } while(s == 'y');
}

void preordernr(node *root){
    node* temp = root;
    while(1) {
        while(temp != NULL) {
            printf("%d ", temp->data);
            push(temp);
            temp = temp->left;
        }
        if(isEmpty()) break;
        temp = pop();
        temp = temp->right;
    }
    printf("\n");
}

void inordernr(node *root){
    node *temp = root;
    while(1) {
        while(temp != NULL) {
            push(temp);
            temp = temp->left;
        }
        
        if(isEmpty()) break;
        
        temp = pop();
        printf("%d ", temp->data);
        temp = temp->right;
    }
    printf("\n");
}

void postordernr(node *root){
    node *temp = root;
    node *lastVisited = NULL;
    while(1) {
        while(temp != NULL) {
            push(temp);
            temp = temp->left;
        }
        
        if(isEmpty()) break;
        
        temp = stack[top];
        if(temp->right != NULL && temp->right != lastVisited) {
            temp = temp->right;
        } else {
            temp = pop();
            printf("%d ", temp->data);
            lastVisited = temp;
            temp = NULL;
        }
    }
    printf("\n");
}

void creater(node *root){
    node *temp = root;
    int option = 1;
    
    printf("\nDo you want to input data on the left side of %d? (1/0): ", temp->data);
    scanf("%d", &option);
    if(option == 1) {
        node *curr = (node *)malloc(sizeof(node));
        curr->left = NULL;
        curr->right = NULL;
        printf("\nInput data for the node: ");
        scanf("%d", &curr->data);
        temp->left = curr;
        creater(curr);
    }
    printf("\nDo you want to input data on the right side of %d? (1/0): ", temp->data);
    scanf("%d", &option);
    if(option == 1) {
        node *curr = (node *)malloc(sizeof(node));
        curr->left = NULL;
        curr->right = NULL;
        printf("\nInput data for the node: ");
        scanf("%d", &curr->data);
        temp->right = curr;
        creater(curr);
    }   
}

void preorderr(node *temp){
    if(temp != NULL) {
        printf("%d ", temp->data);
        preorderr(temp->left);
        preorderr(temp->right);
    }
}

void inorderr(node *temp){
    if(temp != NULL) {
        inorderr(temp->left);
        printf("%d ", temp->data);
        inorderr(temp->right);
    }
}

void postorderr(node *temp){
    if(temp != NULL) {
        postorderr(temp->left);
        postorderr(temp->right);
        printf("%d ", temp->data);
    }
}

int main(){
    node *root = (node *)malloc(sizeof(node));
    root->data = 0;  // Initialize root data
    root->left = NULL;
    root->right = NULL;
    
    menu();
    int choice;
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            createnr(root);
            printf("Preorder Non-Recursive: ");
            preordernr(root);
            printf("Inorder Non-Recursive: ");
            inordernr(root);
            printf("Postorder Non-Recursive: ");
            postordernr(root);
            break;
        case 2:
            creater(root);
            printf("Preorder Recursive: ");
            preorderr(root);
            printf("\nInorder Recursive: ");
            inorderr(root);
            printf("\nPostorder Recursive: ");
            postorderr(root);
            printf("\n");
            break;
        default:
            printf("INVALID OPTION\n");
    }
    return 0;
}
