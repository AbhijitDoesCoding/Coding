#include<stdio.h>
int main(){
int n;
int a[n];
printf("Enter no of students: \n");
scanf("%d", &n);
printf("Enter your roll numbers: \n");
for(int i = 0; i < n; i++){
scanf("%d", &a[i]);
}
printf("You have entered the roll numbers\n");
for(int  i = 0; i < n; i++){
printf("rollno[%d]=%d\n", i, a[i]);
}
return 0;
}
