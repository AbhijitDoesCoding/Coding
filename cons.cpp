#include <bits/stdc++.h>
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
    public:
    // Default Constructor
    Student() {
        name = "Unknown";
        rollNumber = 0;
        studentClass = "Unknown";
        dateOfBirth = "01/01/2000";
        adharNumber = "123456789012";
        bloodGroup = "AB+";
        telephoneNumber = "1234567890";
        marksObtained = 0;

        cout << "Default constructor called." << endl;
    }

    // Parameterized Constructor
    
    Student(string n, int r, string c, string d, string a, string b, string t, int m) {
        name = n;
        rollNumber = r;
        studentClass = c;
        dateOfBirth = d;
        adharNumber = a;
        bloodGroup = b;
        telephoneNumber = t;
        marksObtained = m;

        cout << "Parameterized constructor called for " << name << "." << endl;
    }
    // Copy Constructor
    Student(const Student& s) {
        name = s.name;
        rollNumber = s.rollNumber;
        studentClass = s.studentClass;
        dateOfBirth = s.dateOfBirth;
        adharNumber = s.adharNumber;
        bloodGroup = s.bloodGroup;
        telephoneNumber = s.telephoneNumber;
        marksObtained = s.marksObtained;

        cout << "Copy constructor called." << endl;
    }

    ~Student() {
        cout << "Destructor called for student " << name << "." << endl;
    }

    void displayinfo(){
        cout<<"Name: "<<name<<endl;
        cout<<"Roll Number: "<<rollNumber<<endl;
        cout<<"Class: "<<studentClass<<endl;
        cout<<"Date of Birth: "<<dateOfBirth<<endl;
        cout<<"Adhar Number: "<<adharNumber<<endl;
        cout<<"Blood Group: "<<bloodGroup<<endl;
        cout<<"Telephone Number: "<<telephoneNumber<<endl;
        cout<<"Marks Obtained: "<<marksObtained<<endl;

    }

    // void inputDetails() {
    //     cout << "Enter Name: ";
    //     getline(cin, name);

    //     cout << "Enter Roll Number: ";
    //     cin >> rollNumber;
    //     cin.ignore();

    //     cout << "Enter Class: ";
    //     getline(cin, studentClass);

    //     cout << "Enter Date of Birth: ";
    //     getline(cin, dateOfBirth);

    //     cout << "Enter Adhar Number: ";
    //     getline(cin, adharNumber);

    //     cout << "Enter Blood Group: ";
    //     getline(cin, bloodGroup);

    //     cout << "Enter Telephone Number: ";
    //     getline(cin, telephoneNumber);

    //     cout << "Enter Marks Obtained: ";
    //     cin >> marksObtained;
    //     cin.ignore();
    // }

    // static int getStudentCount() {
    //     return studentCount;
    // }
    friend void displayPercentage(const Student& s);
};

int Student::studentCount = 0;

void displayPercentage(const Student& s) {
    cout << "Percentage of marks obtained by " << s.name << ": " << s.marksObtained << "%" << endl;
}

int main() {
    Student s1;
    cout << "Default Constructor" << endl;
    s1.displayinfo();
    displayPercentage(s1);
    cout << endl;

    Student s2("Abhijit", 22, "2nd year", "18/04/2005", "556278391", "O", "987654321", 89);
    cout << "Parameterized Constructor" << endl;
    s2.displayinfo();
    displayPercentage(s2);
    cout << endl;

    Student s3(s2);
    cout << "Copy Constructor" << endl;
    s3.displayinfo();
    displayPercentage(s3);
    cout << endl;

    return 0;
}
