#include<stdio.h>
void fact(int a){
int total=1;
for(int i = 1; i <= a;i++){
total *= (i);
}
printf("%d\n", total);
}
void main(){
int a;
scanf("%d", &a);
fact(a);
}
