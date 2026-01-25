#include<stdio.h>
void main(){
    int *ptr;
    int k; 
    scanf("%d", &k);
    // int k = 4;
    *ptr = k;
    printf("%d", *ptr);
}