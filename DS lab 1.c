#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

// structure to store student information
typedef struct {
    char name[MAX]; // student name
    char roll[10];  // roll number
    char address[MAX]; // address
    char phone[15]; // phone number
    char email[MAX];    // email address
    char dob[MAX];  // date of birth
} Student;

// function to add student
void addStudent(Student *s, int *n){    
    printf("Enter student name: ");  
    scanf(" %[^\n]", s[*n].name); 
    printf("Enter student roll: ");
    scanf(" %[^\n]", s[*n].roll);  
    printf("Enter student address: ");  
    scanf(" %[^\n]", s[*n].address);    
    printf("Enter student phone: ");     
    scanf(" %[^\n]", s[*n].phone);  
    printf("Enter student email: ");
    scanf(" %[^\n]", s[*n].email);  
    printf("Enter student date of birth: "); 
    scanf(" %[^\n]", s[*n].dob);    
    (*n)++; // increment number of students
}

// function to display student
void displayStudent(Student *s, int n){  
    for(int i=0; i<n; i++){
        printf("Student %d\n", i+1);
        printf("Name: %s\n", s[i].name);
        printf("Roll: %s\n", s[i].roll);
        printf("Address: %s\n", s[i].address);
        printf("Phone: %s\n", s[i].phone);
        printf("Email: %s\n", s[i].email);
        printf("Date of Birth: %s\n", s[i].dob);
    }
}

// function to sort students using bubble sort by their name
void Bubble_sort_by_name(Student *s, int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(strcmp(s[j].name, s[j+1].name) > 0){
                Student temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }
}

// function to sort students using bubble sort by their roll number
void Bubble_sort_by_roll(Student *s, int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(strcmp(s[j].roll, s[j+1].roll) > 0){
                Student temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }
}

// function to sort students using selection sort by their name
void Selection_sort_by_name(Student *s, int n){
    for(int i=0; i<n-1; i++){
        int min = i;
        for(int j=i+1; j<n; j++){
            if(strcmp(s[j].name, s[min].name) < 0){
                min = j;
            }
        }
        Student temp = s[i];
        s[i] = s[min];
        s[min] = temp;
    }
}

// function to sort students using selection sort by their roll number
void Selection_sort_by_roll(Student *s, int n){
    for(int i=0; i<n-1; i++){
        int min = i;
        for(int j=i+1; j<n; j++){
            if(strcmp(s[j].roll, s[min].roll) < 0){
                min = j;
            }
        }
        Student temp = s[i];
        s[i] = s[min];
        s[min] = temp;
    }
}

// function to sort students using insertion sort by their name
void Insertion_sort_by_name(Student *s, int n){
    for(int i=1; i<n; i++){
        Student key = s[i];
        int j = i-1;
        while(j>=0 && strcmp(s[j].name, key.name) > 0){
            s[j+1] = s[j];
            j--;
        }
        s[j+1] = key;
    }
}

// function to sort students using insertion sort by their roll number
void Insertion_sort_by_roll(Student *s, int n){
    for(int i=1; i<n; i++){
        Student key = s[i];
        int j = i-1;
        while(j>=0 && strcmp(s[j].roll, key.roll) > 0){
            s[j+1] = s[j];
            j--;
        }
        s[j+1] = key;
    }
}

int main(){
    Student s[MAX]; // array of students
    int n = 0;  // number of students
    int choice; // choice of operation
    while(1){
        printf("\n1. Add a single student\n2. Display students\n");
        printf("3. Sort students by name using Bubble sort\n4. Sort students by roll number using Bubble sort\n");
        printf("5. Sort students by name using Selection sort\n6. Sort students by roll number using Selection sort\n");
        printf("7. Sort students by name using Insertion sort\n8. Sort students by roll number using Insertion sort\n");
        printf("9. Add multiple students\n10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                addStudent(s, &n);
                break;
            case 2:
                displayStudent(s, n);
                break;
            case 3:
                Bubble_sort_by_name(s, n);
                printf("Students sorted by name using Bubble sort\n");
                displayStudent(s, n);
                break;
            case 4:
                Bubble_sort_by_roll(s, n);
                printf("Students sorted by roll number using Bubble sort\n");
                displayStudent(s, n);
                break;
            case 5:
                Selection_sort_by_name(s, n);
                printf("Students sorted by name using Selection sort\n");
                displayStudent(s, n);
                break;
            case 6:
                Selection_sort_by_roll(s, n);
                printf("Students sorted by roll number using Selection sort\n");
                displayStudent(s, n);
                break;
            case 7:
                Insertion_sort_by_name(s, n);
                printf("Students sorted by name using Insertion sort\n");
                displayStudent(s, n);
                break;
            case 8:
                Insertion_sort_by_roll(s, n);
                printf("Students sorted by roll number using Insertion sort\n");
                displayStudent(s, n);
                break;
            case 9:
                printf("Enter number of students: ");
                int num;
                scanf("%d", &num);
                for(int i=0; i<num; i++){
                    printf("Enter student %d\n", n+1);
                    addStudent(s, &n);
                }
                break;
            case 10:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
