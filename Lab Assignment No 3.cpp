//PROBLEM STATEMENT: Write a menu driven program in C to implement the basic arithmetic operation
#include<stdio.h>
#include<string.h>

int main(){
    char add[] = "Addition";
    char sub[] = "Subtraction";
    char div[] = "Division";
    char mult[] = "Multiplication";
    int a, b, c, n;
    int uzi = 1;
    do{
        uzi = 1;
    printf("Enter your two numbers you want to do the operation on.\n");
    scanf("%d %d", &a, &b);
    

    printf("Choose the operation you want to do.\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n5.Remainder\n");
    scanf("%d", &n);
    switch(n){
        case 1:
        printf("Your %s of two numbers is %d", add, a+b);
        break;
        case 2:
        printf("Your %s of two numbers is %d", sub, a-b);
        break;
        case 3:
        printf("Your %s of two numbers is %d", mult, a*b);
        break;
        case 4:
        if(b == 0){
            uzi = 0;
            goto exit;
        }
        printf("Your %s of two numbers is %.2f", div, (double)a/b);
        break;
        case 5:
        if(b == 0){
            uzi = 0;
            goto exit;
        }
        printf("Your remainder if a is divided by b is %d", a%b);
    }
    exit:
    if(uzi == 0)
    printf("Your entered number was incorrect.");
    printf("\nPress 1 if you want to try again.\n");
    scanf("%d", &n);
    }while(n == 1);
    return 1;
}