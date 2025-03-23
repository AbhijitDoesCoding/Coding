#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char keyword[20];
    char meaning[40];
    struct node *left;
    struct node *right;
}node;

void createbst(node *root){
    node *temp = root;
    printf("Enter keyword: ");
    scanf("%s", temp->keyword);
    printf("Enter meaning: ");
    scanf("%s", temp->meaning);
    temp->left = NULL;
    temp->right = NULL;
    char cont = 'y';
    printf("Do you want to insert another node? (y/n): ");
    scanf(" %c", &cont);
    if(cont == 'n'){
        return;
    }
    while(cont == 'y'){
        node *curr = (node*)malloc(sizeof(node));
        printf("Enter keyword: ");
        scanf("%s", curr->keyword);
        printf("Enter meaning: ");
        scanf("%s", curr->meaning);
        curr->left = NULL;
        curr->right = NULL;
        int flag = 0;
        node *temp = root;
        while(!flag){
            int diff = strcmp(curr->keyword, temp->keyword);
            if(diff < 0){
                if(temp->left == NULL){
                    temp->left = curr;
                    flag = 1;
                }
                else{
                    temp = temp->left;
                }
            }
            else{
                if(temp->right == NULL){
                    temp->right = curr;
                    flag = 1;
                }
                else{
                    temp = temp->right;
                }
            }
        }
        printf("Do you want to insert another node? (y/n): ");
        scanf(" %c", &cont);
    }
}

void displayInorderRec(node *root){
    if(root != NULL){
        displayInorder(root->left);
        printf("%s: %s, ", root->keyword, root->meaning);
        displayInorder(root->right);
    }
}

void displayInorderIter(node *root){
    node *temp = root;
    while(1){
        while(temp != NULL){
            ptr_push(temp);
            temp = temp->left;
        }
        if(IsEmpty()){
            break;
        }
        temp = ptr_pop();
        printf("%s: %s, ", temp->keyword, temp->meaning);
        temp = temp->right;
    }
    printf("\n");
}

int main(){
    node *root = (node*)malloc(sizeof(node));
    createbst(root);
    printf("Inorder Traversal by Recursion: ");
    displayInorderRec(root);
    printf("Inorder Traversal by Iteration: ");
    displayInorderIter(root);
    return 0;
}