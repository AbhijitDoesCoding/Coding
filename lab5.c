#include<stdio.h>
void main(){
int looper;
int k, l;
int u, y;
do{
int choice;
printf("Enter what operation you want to perform\n");
printf("1. Addition\n2.Subtraction\n");
scanf("%d", &choice);

if(choice == 1){

printf("Enter the number of rows and column you want to add:\n");
scanf("%d %d", &k, &l);
printf("Enter your matrix elements:\n");
int arr1[k][l];
for(int i = 0; i < k; i++){
for(int j = 0; j < l; j++){
scanf("%d", &arr1[i][j]);
}
}
for(int i = 0; i < k; i++){
for(int j = 0; j < l; j++){
printf("%d\t", arr1[i][j]);
}
printf("\n");
}
printf("Enter your rows and column for the second matrix\n");

scanf("%d %d", &u, &y);
if(u != k || y != l){
printf("Your entered rows and column do not match");
return;} 
printf("Enter your second matrix\n");
int arr2[k][l];
for(int i = 0; i < k; i++){
for(int j = 0; j < l; j++){
scanf("%d", &arr2[i][j]);
}
}
for(int i = 0; i < k; i++){
for(int j = 0; j < l; j++){
printf("%d \t", arr2[i][j]);
}
printf("\n");
}
printf("\nYour added matrix is\n");
for(int i = 0; i < k; i++){
for(int j = 0; j < l; j++){
printf("%d \t", arr2[i][j] + arr1[i][j]);
}
printf("\n");
}
}
else if(choice == 2){
int k, l;
printf("Enter the number of rows and column you want to add:\n");
scanf("%d %d", &k, &l);
printf("Enter your matrix elements:\n");
int arr1[k][l];
for(int i = 0; i < k; i++){
for(int j = 0; j < l; j++){
scanf("%d", &arr1[i][j]);
}
}
for(int i = 0; i < k; i++){
for(int j = 0; j < l; j++){
printf("%d\t", arr1[i][j]);
}
printf("\n");
}
printf("Enter your rows and column for the second matrix\n");
int u, y;
scanf("%d %d", &u, &y);
if(u != k || y != l){
printf("Your entered rows and column do not match");
return;} 
printf("Enter your second matrix\n");
int arr2[k][l];
for(int i = 0; i < k; i++){
for(int j = 0; j < l; j++){
scanf("%d", &arr2[i][j]);
}
}
for(int i = 0; i < k; i++){
for(int j = 0; j < l; j++){
printf("%d \t", arr2[i][j]);
}
printf("\n");
}
printf("\nYour added matrix is\n");
for(int i = 0; i < k; i++){
for(int j = 0; j < l; j++){
printf("%d \t", arr2[i][j] - arr1[i][j]);
}
printf("\n");
}
}
else
printf("Invalid choice");
printf("Press 1 if you want to run the code again");
scanf("%d", &looper);
}while(looper == 1);
}
