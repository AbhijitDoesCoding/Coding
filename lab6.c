#include<stdio.h>
struct student
{
int rollno;
char name[10];
int m1, m2, m3, total;
float per;
}s1[10];

void main()
{
int n;
printf("Enter the number of records you want to create?\n");
scanf("%d", &n);
for(int i = 0; i < n; i++){
printf("Enter the roll no.\n");
scanf("%d", &s1[i].rollno);
printf("Enter the name\n");
scanf("%s", s1[i].name); 
printf("Enter the marks of subject 1\n");
scanf("%d", &s1[i].m1);
printf("Enter the marks of subject 2\n");
scanf("%d", &s1[i].m2);
printf("Enter the marks of subject 3\n");
scanf("%d", &s1[i].m3);
s1[i].total= s1[i].m1 +  s1[i].m2 +  s1[i].m3;
s1[i].per = s1[i].total/3;
}
printf("\nRoll no.\tName\tMarks1\tMarks2\tMarks3\tTotal\tPercentage\n");
for(int i = 0; i < n; i++){
printf("%d\t\t%s\t%d\t%d\t%d\t%d\t%f\n", s1[i].rollno, s1[i].name, s1[i].m1, s1[i].m2, s1[i].m3, s1[i].total, s1[i].per);
}
int req;
printf("Enter the rollno whose data is required.\n");
scanf("%d", &req);
for(int i = 0; i < n; i++){
if(req == s1[i].rollno){
printf("\nRoll no.\tName\tMarks1\tMarks2\tMarks3\tTotal\tPercentage\n");
printf("%d\t\t%s\t%d\t%d\t%d\t%d\t%f\n", s1[i].rollno, s1[i].name, s1[i].m1, s1[i].m2, s1[i].m3, s1[i].total, s1[i].per);
break;
}
}
}
