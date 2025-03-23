#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tbtnode {
    char data[100];  
    int rbit, lbit;
    struct tbtnode *rightc, *leftc;
} tbtnode;
//optional
typedef struct tbt {
    tbtnode *head;
} tbt;

void create(tbt *tree);
void inorder(tbt *tree);
void preorder(tbt *tree);
tbtnode* insucc(tbtnode *temp);

tbtnode* new_node(char data[]) {  
    tbtnode* temp = (tbtnode*)malloc(sizeof(tbtnode));
    strcpy(temp->data, data);  
    temp->rbit = 0;
    temp->lbit = 0;
    temp->rightc = NULL;
    temp->leftc = NULL;
    return temp;
}

void init_tbt(tbt *tree) {
    tree->head = new_node("H"); 
    tree->head->rbit = 1;
    tree->head->lbit = 1;
    tree->head->rightc = tree->head;
    tree->head->leftc = tree->head;
}

void create(tbt *tree) {
    tbtnode *root, *temp, *curr;
    char data[100], choice, cont;
    
    printf("Enter data for root node: ");
    scanf(" %s", data);

    root = new_node(data);
    tree->head->lbit = 1;
    root->leftc = tree->head;
    root->rightc = tree->head;
    tree->head->leftc = root;

    do {
        int flag = 0;
        temp = root;
        
        printf("Enter data for new node: ");
        scanf(" %s", data); 
        
        curr = new_node(data);
        
        while (!flag) {
            printf("Insert left (l) or right (r) of %s: ", temp->data); 
            scanf(" %c", &choice);
            
            if (choice == 'l') {
                if (temp->lbit == 0) {
                    curr->rightc = temp;
                    curr->leftc = temp->leftc;
                    temp->leftc = curr;
                    temp->lbit = 1;
                    flag = 1;
                } else {
                    temp = temp->leftc;
                }
            } else if (choice == 'r') {
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
    } while (cont == 'y');
}

void inorder(tbt *tree) {
    tbtnode *temp = tree->head;
    
    while (1) {
        temp = insucc(temp);
        if (temp == tree->head) break;
        printf("%s ", temp->data); 
    }
    printf("\n");
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

void preorder(tbt *tree) {
    tbtnode *temp = tree->head->leftc;
    
    while (temp != tree->head) {
        printf("%s ", temp->data); 
        
        while (temp->lbit != 0) {
            temp = temp->leftc;
            printf("%s ", temp->data);
        }
        
        while (temp->rbit == 0) {
            temp = temp->rightc;
        }
        temp = temp->rightc;
    }
    printf("\n");
}

int main() {
    tbt tree;
    int choice;
    
    init_tbt(&tree);
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Create Threaded Binary Tree\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                create(&tree);
                break;
            case 2:
                printf("Inorder Traversal: ");
                inorder(&tree);
                break;
            case 3:
                printf("Preorder Traversal: ");
                preorder(&tree);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
