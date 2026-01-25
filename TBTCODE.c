#include <stdio.h>
#include <stdlib.h>

typedef struct tbtnode {
    int data;
    int rbit, lbit;
    struct tbtnode *rightc; 
    struct tbtnode *leftc;  
} tbtnode;

void create(tbtnode *head) {
    tbtnode *root = (tbtnode *)malloc(sizeof(tbtnode));
    printf("Enter data for root node: ");
    scanf("%d", &root->data);
    head->lbit = 1;
    head->leftc = root;
    root->leftc = head;
    root->rightc = head;
    root->lbit = 0;
    root->rbit = 0;

    char cont = 'y';

    while (cont == 'y') {
        int flag = 0;
        tbtnode *temp = root;
        int data;
        printf("Enter data for new node: ");
        scanf("%d", &data);
        tbtnode *curr = (tbtnode *)malloc(sizeof(tbtnode));
        curr->data = data;
        curr->lbit = 0;
        curr->rbit = 0;

        while (!flag) {
            char opt;
            printf("Left child (l), right (r) of %d: ", temp->data);
            scanf(" %c", &opt);
            if (opt == 'l {
                if (temp->lbit == 0) {
                    curr->rightc = temp;
                    curr->leftc = temp->leftc;
                    temp->leftc = curr;
                    temp->lbit = 1;
                    flag = 1;
                } else {
                    temp = temp->leftc;
                }
            } 
            else if (opt == 'r') {
                if (temp->rbit == 0) {
                    curr->leftc = temp;
                    curr->rightc = temp->rightc;
                    temp->rightc = curr;
                    temp->rbit = 1;
                    flag = 1;
                } else {
                    temp = temp->rightc;
                }
            }
        }

        printf("Do you want to insert another node? (y/n): ");
        scanf(" %c", &cont);
    }
}



int main() {
    tbtnode *head = (tbtnode *)malloc(sizeof(tbtnode));
    head->data = 0;
    head->rbit = 1;
    head->lbit = 0;
    head->rightc = head;
    head->leftc = head;
    create(head);
    inorder(head); 
    preorder(head);
    postorder(head);
    return 0;
}
void inorder(tbtnode *head) {
    tbtnode *temp = head;
    printf("\nInorder Traversal: ");
    while (1) {
        temp = insucc(temp);
        if (temp == head) break;
        printf("%d ", temp->data);
    }
}

tbtnode* insucc(tbtnode *temp) {
    tbtnode *x = temp->rightc;
    if (temp->rbit == 1) {
        while (x->lbit == 1) {
            x = x->leftc;
        }
    }
    return x;
}

void preorder(tbtnode *head) {
    tbtnode *temp = head->leftc;
    printf("\nPreorder Traversal: ");
    while (1) {
        temp = presucc(temp);
        if (temp == head) break;
        printf("%d ", temp->data);
    }
}

tbtnode* presucc(tbtnode *temp) {
    tbtnode *x = temp->leftc;
    if (temp->lbit == 1) {
        while (x->rbit == 1) {
            x = x->rightc;
        }
    }
    return x;
}

void postorder(tbtnode *head) {
    tbtnode *temp = head->leftc;
    printf("\nPostorder Traversal: ");
    while (1) {
        temp = postsucc(temp);
        if (temp == head) break;
        printf("%d ", temp->data);
    }
}

tbtnode* postsucc(tbtnode *temp) {
    tbtnode *x = temp->rightc;
    if (temp->rbit == 1) {
        while (x->lbit == 1) {
            x = x->leftc;
        }
    }
    return x;
}
tbtnode* insucc(tbtnode *temp);
tbtnode* presucc(tbtnode *temp);
tbtnode* postsucc(tbtnode *temp);
