#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class Student {
private:
    string name;
    int rollNumber;
    string studentClass;
    string dateOfBirth;
    string adharNumber;
    string bloodGroup;
    string telephoneNumber;
    int marksObtained;
    static int studentCount;

public:
    Student() 
    {
        name = "Abhijit";
        rollNumber = 22;
        studentClass = "2nd year";
        dateOfBirth = "01/01/2000";
        adharNumber = "123456789012";
        bloodGroup = "AB+";
        telephoneNumber = "1234567890";
        marksObtained = 90;

        studentCount++;
        cout << "Default constructor called." << endl;
    }

    Student(string name1, int rollNumber1, string studentClass1, 
            string dateOfBirth1, string adharNumber1,
             string bloodGroup1, string telephoneNumber1, 
            int marksObtained1) 
    {
        name = name1;
        rollNumber = rollNumber1;
        studentClass = studentClass1;
        dateOfBirth = dateOfBirth1;
        adharNumber = adharNumber1;
        bloodGroup = bloodGroup1;
        telephoneNumber = telephoneNumber1;
        marksObtained = marksObtained1;

        studentCount++;
        cout << "Parameterized constructor called for " << name << "." << endl;
    }

    Student(const Student& other) 
    {
        name = other.name;
        rollNumber = other.rollNumber;
        studentClass = other.studentClass;
        dateOfBirth = other.dateOfBirth;
        adharNumber = other.adharNumber;
        bloodGroup = other.bloodGroup;
        telephoneNumber = other.telephoneNumber;
        marksObtained = other.marksObtained;

        studentCount++;
        cout << "Copy constructor called for " << name << "." << endl;
    }

    ~Student() {
        studentCount--;
        cout << "Destructor called for " << name << "." << endl;
    }

    void inputDetails() {
        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Roll Number: ";
        cin >> rollNumber;
        cin.ignore();

        cout << "Enter Class: ";
        getline(cin, studentClass);

        cout << "Enter Date of Birth: ";
        getline(cin, dateOfBirth);

        cout << "Enter Adhar Number: ";
        getline(cin, adharNumber);

        cout << "Enter Blood Group: ";
        getline(cin, bloodGroup);

        cout << "Enter Telephone Number: ";
        getline(cin, telephoneNumber);

        cout << "Enter Marks Obtained: ";
        cin >> marksObtained;
        cin.ignore();
    }

    static int getStudentCount() {
        return studentCount;
    }

    friend void displayPercentage(const Student& s);
    friend void displayAllStudentsData(const Student* students, int numStudents);
};

int Student::studentCount = 0;

void displayPercentage(const Student& s) {
    cout << "Percentage of marks obtained by " << s.name << ": " << s.marksObtained << "%" << endl;
}

void displayAllStudentsData(const Student* students, int numStudents) {
    for (int i = 0; i < numStudents; ++i) {
        cout << "Student " << i + 1 << " Details:" << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "Roll Number: " << students[i].rollNumber << endl;
        cout << "Class: " << students[i].studentClass << endl;
        cout << "Date of Birth: " << students[i].dateOfBirth << endl;
        cout << "Adhar Number: " << students[i].adharNumber << endl;
        cout << "Blood Group: " << students[i].bloodGroup << endl;
        cout << "Telephone Number: " << students[i].telephoneNumber << endl;
        cout << "Marks Obtained: " << students[i].marksObtained << endl;
        displayPercentage(students[i]);
        cout << endl;
    }
}

int main() {

    int numStudents;
    cout << "Enter the number of students: ";
    cin >> numStudents;

    Student students[numStudents];

    for (int i = 0; i < numStudents; ++i) {
        cout << "Enter details for student " << i + 1 << ":" << endl;
        students[i].inputDetails();
    }

    cout << "Total number of students: " << Student::getStudentCount() << endl;
    
    if (numStudents > 0) {
        Student copiedStudent(students[0]);
        cout << "Details of the copied student:" << endl;
        displayAllStudentsData(&copiedStudent, 1);
    }

    cout << endl << "Displaying all student data:" << endl;
    displayAllStudentsData(students, numStudents);
    return 0;

}

