#include<iostream>
#include<string>
using namespace std;

class Student
{
static int count;
string name;
int roll;
string Class;
int div;
int dob;
int adharnum;
string bloodgroup;
string address;
int phonenum;
float marks;

public:
void getdata()
{
cout<<"Enter Name : "<<endl;
cin>>name;
cout<<"Enter Roll Number: "<<endl;
cin>>roll;
cout<<"Enter Class: "<<endl;
cin>>Class;
cout<<"Enter Division: "<<endl;
cin>>div;
cout<<"Enter Date of Birth: "<<endl;
cin>>dob;
cout<<"Enter Adhar Number: "<<endl;
cin>>adharnum;
cout<<"Enter BLood Group: "<<endl;
cin>>bloodgroup;
cout<<"Enter Address: "<<endl;
cin>>address;
cout<<"Enter Phone Number: "<<endl;
cin>>phonenum;
cout<<"Enter Marks of the Student: "<<endl;
cin>>marks;
count=count+1;
}
void display()
{
cout<<"Name: "<<name<<endl;
cout<<"Roll Number: "<<roll<<endl;
cout<<"Class: "<<Class<<endl;
cout<<"Division: "<<div<<endl;
cout<<"Date Of Birth: "<<dob<<endl;
cout<<"Adhar Number: "<<adharnum<<endl;
cout<<"Blood Group: "<<bloodgroup<<endl;
cout<<"Address: "<<address<<endl;
cout<<"Phone Number: "<<phonenum<<endl;
cout<<"Obtained Marks: "<<marks<<endl;
}

friend void calper(Student);

static void total_student()
{
cout<<"Total Student Count: "<<count;
}
};


int Student::count;


void calper(Student st)
{
float per;
per = ((st.marks)/300)*100;
cout<<"Percentage: "<<per<<" %"<<endl;
}

int main()
{
Student st[2];
int i;

for(i=0;i<2;i++)
{
cout<<"Student: "<<i+1<<endl;
cout<<"Get data of the Student: "<<endl;
st[i].getdata();
}

for(i=0;i<2;i++)
{
cout<<"Student: "<<i+1<<endl;
cout<<"Display the data : "<<endl;
st[i].display();
calper(st[i]);
cout<<endl;
}
Student::total_student();

return 0;
}