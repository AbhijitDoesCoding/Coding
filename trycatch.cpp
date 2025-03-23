#include <iostream>
#include <string.h>
using namespace std;

#define nline cout<<"\n";

class hotel{

private:
string cust_name;
int cust_id;
int income;
int age;
string city;
string room_type;

public:

hotel(){
    cout<<"Welcome to KH Mahal!"<<endl;
    cout<<"Enter name : ";
    cin>>cust_name;
    cout<<endl;
    cout<<"Enter age : ";
    cin>>age;
    cout<<endl;
    cout<<"Enter customer id : ";
    cin>>cust_id;
    cout<<endl;
    cout<<"Enter income : ";
    cin>>income;
    cout<<endl;
    cout<<"Enter city : ";
    cin>>city;
    cout<<endl;
    cout<<"Enter room type ";
    cin>>room_type;
    cout<<endl;
    cout<<"Thankyou for your response"<<endl;
}



void display(){
cout<<"\nCustomer information : ";
cout<<"\nName : "<<cust_name;
cout<<"\nAge : "<<age;
cout<<"\nIncome : "<<income;
cout<<"\nCity : "<<city;
cout<<"\nRoom type : "<<room_type;
}

void verify_age(){
try{
     if (age<18 || age>55){
        throw(age);
     }
}
catch(int i){
     cout<<"Entered age is invalid.";
}
}

void verifyincome(){
try{
     if (income<50000 || income>100000){
        throw(income);
     }
}
catch(int i){
     cout<<"\nEntered income is invalid.";
}
}

void verifycity(){
try{
     if(city != "Pune" || city!="Mumbai"){
        throw(city);
     }
}
catch(string i){
      cout<<"\nInvalid city";
}

}

void verify_room_type(){
try{
    if(room_type != "Duplex" || room_type !="Super Dulex"){
    throw(room_type);
    }
}
catch(string i){
     cout<<"\nInvalid room type entered."<<endl;
}
}


};

int main(){

hotel h;
h.display();
nline;
h.verify_age();
h.verifyincome();
h.verify_room_type();
h.verifycity();

return 0;

}