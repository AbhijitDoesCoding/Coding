#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Stack for non-recursive traversal
struct Node *stack[100];
int stackTop = -1;

// Stack operations
struct Node *pop() {
    if (stackTop < 0) {
        printf("Stack is empty\n");
        return NULL;
    }
    return stack[stackTop--];
}

void push(struct Node *node) {
    if (stackTop >= 99) {
        printf("Stack is full\n");
    } else {
        stack[++stackTop] = node;
    }
}

int isEmpty() {
    return stackTop < 0;
}

// Recursive Tree Creation
void createTree(struct Node *root) {
    struct Node *temp = root;
    int leftChoice, rightChoice;

    // Create left subtree
    printf("Add data to left of %d? (1 for Yes, 2 for No): ", temp->data);
    scanf("%d", &leftChoice);
    if (leftChoice == 1) {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter left node data: ");
        scanf("%d", &newNode->data);
        temp->left = newNode;
        createTree(newNode);
    }

    // Create right subtree
    printf("Add data to right of %d? (1 for Yes, 2 for No): ", temp->data);
    scanf("%d", &rightChoice);
    if (rightChoice == 1) {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter right node data: ");
        scanf("%d", &newNode->data);
        temp->right = newNode;
        createTree(newNode);
    }
}

// Non-recursive Tree Creation
void createTreeNonRecursive(struct Node *root) {
    int cont;
    do {
        struct Node *temp = root;
        int direction, flag = 0;
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        
        printf("Enter new node data: ");
        scanf("%d", &newNode->data);
        newNode->left = NULL;
        newNode->right = NULL;

        while (!flag) {
            printf("Add node to left(1) or right(2) of %d: ", temp->data);
            scanf("%d", &direction);
            if (direction == 1) {
                if (temp->left == NULL) {
                    temp->left = newNode;
                    flag = 1;
                }
                temp = temp->left;
            } else {
                if (temp->right == NULL) {
                    temp->right = newNode;
                    flag = 1;
                }
                temp = temp->right;
            }
        }
        printf("Do you want to continue? (1 for Yes, 0 for No): ");
        scanf("%d", &cont);
    } while (cont);
}

// Recursive Traversals
void inorderRecursive(struct Node *root) {
    if (root != NULL) {
        inorderRecursive(root->left);
        printf("%d, ", root->data);
        inorderRecursive(root->right);
    }
}

void preorderRecursive(struct Node *root) {
    if (root != NULL) {
        printf("%d, ", root->data);
        preorderRecursive(root->left);
        preorderRecursive(root->right);
    }
}

void postorderRecursive(struct Node *root) {
    if (root != NULL) {
        postorderRecursive(root->left);
        postorderRecursive(root->right);
        printf("%d, ", root->data);
    }
}

// Non-Recursive Traversals
void inorderNonRecursive(struct Node *root) {
    struct Node *curr = root;
    while (1) {
        while (curr != NULL) {
            push(curr);
            curr = curr->left;
        }
        if (isEmpty()) break;
        curr = pop();
        printf("%d, ", curr->data);
        curr = curr->right;
    }
    printf("\n");
}

void preorderNonRecursive(struct Node *root) {
    struct Node *curr = root;
    while (1) {
        while (curr != NULL) {
            printf("%d, ", curr->data);
            push(curr);
            curr = curr->left;
        }
        if (isEmpty()) break;
        curr = pop();
        curr = curr->right;
    }
    printf("\n");
}

void postorderNonRecursive(struct Node *root) {
    struct Node *curr = root;
    while (1) {
        while (curr != NULL) {
            push(curr);
            curr = curr->left;
        }
        if (stack[stackTop]->right == NULL) {
            curr = pop();
            printf("%d, ", curr->data);
        }
        while (!isEmpty() && stack[stackTop]->right == curr) {
            curr = pop();
            printf("%d, ", curr->data);
        }
        if (isEmpty()) break;
        curr = stack[stackTop]->right;
    }
    printf("\n");
}

int main() {
    struct Node *root = (struct Node *)malloc(sizeof(struct Node));
    int displayChoice, creationChoice;

    printf("Enter data for root node: \n");
    scanf("%d", &root->data);

    printf("Create tree recursively(1) or non-recursively(2): ");
    scanf("%d", &creationChoice);
    if (creationChoice == 1) {
        createTree(root);
    } else if (creationChoice == 2) {
        createTreeNonRecursive(root);
    } else {
        printf("Invalid choice\n");
        return 0;
    }

    // Menu to choose traversal type
    do {
        printf("Choose traversal method:\n");
        printf("1. Preorder (Recursive)\n2. Postorder (Recursive)\n3. Inorder (Recursive)\n");
        printf("4. Preorder (Non-Recursive)\n5. Postorder (Non-Recursive)\n6. Inorder (Non-Recursive)\n7. Exit\n");
        scanf("%d", &displayChoice);

        switch (displayChoice) {
            case 1:
                printf("Preorder (Recursive): ");
                preorderRecursive(root);
                printf("\n");
                break;
            case 2:
                printf("Postorder (Recursive): ");
                postorderRecursive(root);
                printf("\n");
                break;
            case 3:
                printf("Inorder (Recursive): ");
                inorderRecursive(root);
                printf("\n");
                break;
            case 4:
                printf("Preorder (Non-Recursive): ");
                preorderNonRecursive(root);
                break;
            case 5:
                printf("Postorder (Non-Recursive): ");
                postorderNonRecursive(root);
                break;
            case 6:
                printf("Inorder (Non-Recursive): ");
                inorderNonRecursive(root);
                break;
            case 7:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (displayChoice != 7);

    return 0;
}
