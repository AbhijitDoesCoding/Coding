#include<stdio.h>

void main(){
int a;
scanf("%d", &a);
int total=1;
for(int i = 0; i < a; i++){
total *= (i+1);
}
printf("%d\n", total);
}
