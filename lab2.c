#include <stdio.h>
#include <math.h>


int main(){
long long a,b,c;
char uzi;

do{
printf("Enter your numbers:\n");
scanf("%lld %lld",&a,&b);
printf("1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n5.Modulo\nEnter your choice:\n");
scanf("%lld", &c);
float n;
n = a/b;
printf("YOUR ANSWER IS:");
switch(c){
case 1:
printf("%lld\n", a+b);
break;
case 2:
printf("%lld\n", a-b);
break;
case 3:
printf("%lld\n", a*b);
break;
case 4:
	if(b == 0)
{ 
			printf(" infinity\n"); break;
}
else{
	printf("%.2f\n", (double)a/b);
	break;
}
case 5:
printf("%lld\n", a%b);
break;
default:
printf("Enter a valid number\n");
break;
}
printf("Press 1 if you want to do the operations again otherwise press 0\n");
scanf("%c", &uzi);
}while(uzi == 'y' || uzi == 'Y');
return 1;
}
