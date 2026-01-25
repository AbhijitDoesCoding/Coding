#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student{
    char name[20];
    int roll_number;
}student;

void addstudent(student *s, int *n){
    printf("\nEnter student name: \n");
    scanf("%s", s[*n].name);
    printf("\nEnter student roll number: \n");
    scanf("%d", &s[*n].roll_number);
    (*n)++;
}

void displaystudent(student *s, int n){
    for(int i = 0; i < n; i++){
        printf("\nName: %s, Roll number: %d\n", s[i].name, s[i].roll_number );
    }    
}

void bubblesortname(student *s, int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n - i - 1; j++){
            int k = strcmp(s[j].name, s[j+1].name);
            if(k > 0){
                student temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }
}

void bubblesortroll(student *s, int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(s[j].roll_number > s[j+1].roll_number){
                student temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }
}

void selectionsortname(student *s, int n){
    for(int i = 0; i < n-1; i++){
        int min = i;
        for(int j = i+1; j < n; j++){
            int k = strcmp(s[j].name, s[min].name);
            if(k > 0){
                min = j;
            }
        }
        student temp = s[min];
        s[min] = s[i];
        s[i] = temp;
    }
}

void selectionsortroll(student *s, int n){
    for(int i = 0; i < n-1; i++){
        int min = i;
        for(int j = i+1; j < n; j++){
            if(s[min].roll_number > s[j].roll_number){
                min = j;
            }
        }
        student temp = s[min];
        s[min] = s[i];
        s[i] = temp;
    }
}

void insertionname(student *s, int n){
    for(int i = 1; i < n; i++){
        student key = s[i];
        int j = i - 1;
        while (j >= 0 && strcmp(s[j].name, key.name) > 0) {
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = key;
    }
}

void insertionroll(student *s, int n){
    for(int i = 1; i < n; i++){
        student key = s[i];
        int j = i - 1;
        while (j >= 0 && s[j].roll_number > key.roll_number) {
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = key;
    }
}

void menu() {
    printf("\n--- Student Management System ---\n");
    printf("1. Add student\n");
    printf("2. Display students\n");
    printf("3. Bubble sort by name\n");
    printf("4. Bubble sort by roll number\n");
    printf("5. Selection sort by name\n");
    printf("6. Selection sort by roll number\n");
    printf("7. Insertion sort by name\n");
    printf("8. Insertion sort by roll number\n");
    printf("9. Exit\n");
    printf("Enter your choice: ");
}

int main(){
    student s[100];
    int n = 0;
    while(1){
        menu();
        int choice;
        scanf("%d", &choice);
        switch(choice){
            case 1:
                addstudent(s, &n);
                break;
            case 2:
                displaystudent(s, n);
                break;
            case 3:
                bubblesortname(s, n);
                break;
            case 4:
                bubblesortroll(s, n);
                break;
            case 5:
                selectionsortname(s, n);
                break;
            case 6:
                selectionsortroll(s, n);
                break;
            case 7:
                insertionname(s,n);
                break;
            case 8:
                insertionroll(s, n);
                break;
            case 9:
                exit(0);
            default:
                printf("\nInvalid choice.\n");
        }
    }
    return 0;
}