#include<stdio.h>
#include<string.h>

int main(){
int z;
z = 1;
char s1[99], s2[99];
do{

printf("\n1.Length of your string\n2.To copy your string\n3.To concatenate your string\n4.To compare your string\n");

int uzi;
printf("Enter your choice: ");
scanf("%d",&uzi);
switch(uzi){
case 1:
printf("Enter your string: ");
scanf("%s",s1);
int l; l = strlen(s1);
printf("Your length of string is: %d", l);
break;
case 2:
printf("Enter your string: ");
scanf("%s",s1);
strcpy(s2, s1);
printf("Your copied string is: %s", s2); break;
case 3:
printf("Enter your 1st string: ");
scanf("%s",s1);
printf("Enter your 2nd string: ");
scanf("%s",s2);
strcat(s2, s1);
printf("Your Concatenated string is: %s", s2);
break;
case 4:

printf("Enter your 1st string: ");
scanf("%s",s1);
printf("Enter your 2nd string: ");
scanf("%s",s2);
int uzi;
uzi = strcmp(s2, s1);
if(uzi == 0) printf("\nYour strings are the same.\n");
else if( uzi > 0) printf("\nYour second entered string is greater than the first one.\n");
else printf("\nYour first entered string is greater than the second one.\n");

break;
default:
printf("\nYour entered the wrong number!\n");

}
printf("\nDo you want to repeat the loop?(Press 1 if yes)\n");
scanf("%d", &z);
}while(z == 1);

return 0;
}

