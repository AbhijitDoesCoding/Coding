#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

char infixStack[MAX][MAX];
int topInfix = -1;

char prefixStack[MAX][MAX];
int topPrefix = -1;

char postfixStack[MAX][MAX];
int topPostfix = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    if (top == -1) {
        return -1;
    } else {
        return stack[top--];
    }
}

void pushInfix(char *str) {
    strcpy(infixStack[++topInfix], str);
}

char *popInfix() {
    if (topInfix == -1) {
        return NULL;
    } else {
        return infixStack[topInfix--];
    }
}

void pushPrefix(char *str) {
    strcpy(prefixStack[++topPrefix], str);
}

char *popPrefix() {
    if (topPrefix == -1) {
        return NULL;
    } else {
        return prefixStack[topPrefix--];
    }
}

void pushPostfix(char *str) {
    strcpy(postfixStack[++topPostfix], str);
}

char *popPostfix() {
    if (topPostfix == -1) {
        return NULL;
    } else {
        return postfixStack[topPostfix--];
    }
}

int priority(char x) {
    if (x == '(') return 0;
    else if (x == '+' || x == '-') return 1;
    else if (x == '*' || x == '/' || x == '%') return 2;
    else if (x == '^') return 3;
    return 0;
}

int priorityic(char x) {
    if (x == '(') return 5;
    else if (x == '+' || x == '-') return 1;
    else if (x == '*' || x == '/' || x == '%') return 2;
    else if (x == '^') return 4;
    return 0;
}

void infixToPostfix() {
    char exp[MAX];
    char *e, x;
    printf("Enter the infix expression: ");
    scanf("%s", exp);
    printf("\nPostfix expression: ");
    e = exp;

    while (*e != '\0') {
        if (isalnum(*e)) {
            printf("%c", *e);
        } else if (*e == '(') {
            push(*e);
        } else if (*e == ')') {
            while ((x = pop()) != '(') {
                printf("%c", x);
            }
        } else {
            while (top != -1 && priority(stack[top]) >= priorityic(*e)) {
                printf("%c", pop());
            }
            push(*e);
        }
        e++;
    }
    while (top != -1) {
        printf("%c", pop());
    }
    printf("\n");
}

void postfixToInfix() {
    char exp[MAX];
    char *e;
    printf("Enter the postfix expression: ");
    scanf("%s", exp);
    printf("\nInfix expression: ");
    e = exp;

    while (*e != '\0') {
        if (isalnum(*e)) {
            char operand[2] = {*e, '\0'};
            pushInfix(operand);
        } else {
            char s[MAX], t[MAX], exp3[MAX * 2] = "";
            strcpy(s, popInfix());
            strcpy(t, popInfix());
            strcat(exp3, "(");
            strcat(exp3, t);
            char operator[2] = {*e, '\0'};
            strcat(exp3, operator);
            strcat(exp3, s);
            strcat(exp3, ")");
            pushInfix(exp3);
        }
        e++;
    }
    printf("%s\n", popInfix());
}

void postfixToPrefix() {
    char exp[MAX];
    char *e;
    printf("Enter the postfix expression for prefix conversion: ");
    scanf("%s", exp);
    printf("\nPrefix expression: ");
    e = exp;

    while (*e != '\0') {
        if (isalnum(*e)) {
            char operand[2] = {*e, '\0'};
            pushPrefix(operand);
        } else {
            char op1[MAX], op2[MAX], exp4[MAX * 2] = "";
            strcpy(op1, popPrefix());
            strcpy(op2, popPrefix());
            char operator[2] = {*e, '\0'};
            strcat(exp4, operator);
            strcat(exp4, op2);
            strcat(exp4, op1);
            pushPrefix(exp4);
        }
        e++;
    }
    printf("%s\n", popPrefix());
}

void prefixToPostfix() {
    char exp[MAX];
    char *e;
    printf("Enter the prefix expression for postfix conversion: ");
    scanf("%s", exp);
    printf("\nPostfix expression: ");
    e = exp;
    int len = strlen(exp);

    while (len--) {
        if (isalnum(exp[len])) {
            char operand[2] = {exp[len], '\0'};
            pushPostfix(operand);
        } else {
            char op1[MAX], op2[MAX], exp5[MAX * 2] = "";
            strcpy(op1, popPostfix());
            strcpy(op2, popPostfix());
            char operator[2] = {exp[len], '\0'};
            strcat(exp5, op1);
            strcat(exp5, op2);
            strcat(exp5, operator);
            pushPostfix(exp5);
        }
    }
    printf("%s\n", popPostfix());
}

void prefixToInfix() {
    char exp[MAX];
    printf("Enter the prefix expression: ");
    scanf("%s", exp);
    printf("\nInfix expression: ");
    int len = strlen(exp);

    for (int i = len - 1; i >= 0; i--) {
        if (isalnum(exp[i])) {
            char operand[2] = {exp[i], '\0'};
            pushInfix(operand);
        } else {
            char op1[MAX], op2[MAX], temp[MAX * 2] = "";
            strcpy(op1, popInfix());
            strcpy(op2, popInfix());
            strcat(temp, "(");
            strcat(temp, op1);
            char operator[2] = {exp[i], '\0'};
            strcat(temp, operator);
            strcat(temp, op2);
            strcat(temp, ")");
            pushInfix(temp);
        }
    }
    printf("%s\n", popInfix());
}

void infixToPrefix() {
    char exp[MAX], result[MAX];
    char *e, x;
    printf("Enter the infix expression: ");
    scanf("%s", exp);
    int len = strlen(exp);
    char reversed[MAX];
    int j = 0;

    for (int i = len - 1; i >= 0; i--) {
        if (exp[i] == '(') {
            reversed[j++] = ')';
        } else if (exp[i] == ')') {
            reversed[j++] = '(';
        } else {
            reversed[j++] = exp[i];
        }
    }
    reversed[j] = '\0';

    e = reversed;
    top = -1;
    int k = 0;

    while (*e != '\0') {
        if (isalnum(*e)) {
            result[k++] = *e;
        } else if (*e == '(') {
            push(*e);
        } else if (*e == ')') {
            while ((x = pop()) != '(') {
                result[k++] = x;
            }
        } else {
            while (top != -1 && priority(stack[top]) >= priorityic(*e)) {
                result[k++] = pop();
            }
            push(*e);
        }
        e++;
    }
    while (top != -1) {
        result[k++] = pop();
    }
    result[k] = '\0';

    int resultLen = strlen(result);
    for (int i = resultLen - 1; i >= 0; i--) {
        printf("%c", result[i]);
    }
    printf("\n");
}

int main() {
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Infix to Postfix\n");
        printf("2. Postfix to Infix\n");
        printf("3. Postfix to Prefix\n");
        printf("4. Prefix to Postfix\n");
        printf("5. Prefix to Infix\n");
        printf("6. Infix to Prefix\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                infixToPostfix();
                break;
            case 2:
                postfixToInfix();
                break;
            case 3:
                postfixToPrefix();
                break;
            case 4:
                prefixToPostfix();
                break;
            case 5:
                prefixToInfix();
                break;
            case 6:
                infixToPrefix();
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 7.\n");
        }
    } while (choice != 7);

    return 0;
}
