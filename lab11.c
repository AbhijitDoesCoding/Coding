// C program to swap two numbers using pointers
#include <stdio.h>
void main() {
    int a, b, temp;
    int *ptr1, *ptr2;
    printf("Enter the value of a and b: \n");
    scanf("%d %d", &a, &b);
    printf("\nBefore swapping a = %d and b = %d", a, b);
    ptr1 = &a;
    ptr2 = &b;
    // Swap the values a and b
    temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
    printf("\nAfter swapping a = %d and b = %d\n", a, b);
}
