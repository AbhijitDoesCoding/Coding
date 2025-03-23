#include<stdio.h>
//factorial
void main(){
int a;
scanf("%d", &a);
int u = 0, v = 1;
int uv;
printf("0 1 ");
for(int i = 0; i <  a; i++){
	uv = u + v;
	u = v;
	v = uv;
	printf("%d ", uv);
}
printf("\n");
}
