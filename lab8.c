#include<stdio.h>
//factorial
int fact(int x){
if(x == 1){
return 1;
}
return x * fact(x-1);
}
void main(){
int a;
scanf("%d", &a);
int k = fact(a);		
printf("%d\n", k);	
}
