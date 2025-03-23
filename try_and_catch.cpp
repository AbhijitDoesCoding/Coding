#include<bits/stdc++.h>
using namespace std;

#define nline cout<<"\n";

bool invalid = false;
int n = 0;

class Hotel{
    
        private:
        string cust_name;
        int cust_id;
        int income;
        int age;
        string city;
        string room_type;
    
        public:

        Hotel(){
            cust_name = "Default";
            cust_id = n;
            n++;
            income = 50000;
            age = 30;
            city = "Mumbai";
            room_type = "Delux";
        }
        void accept(){
            cout<<"\nWelcome to Taj Hotel!"<<endl;
            cout<<"Enter name : ";
            cin>>cust_name;
            nline;
            cout<<"Enter customer id : ";
            cin>>cust_id;
            nline;
            cout<<"Enter age : ";
            cin>>age;
            verify_age();
            nline;
            cout<<"Enter income : ";
            cin>>income;
            
            verify_income();
            nline;
            cout<<"Enter city : ";
            cin>>city;
            verify_city();
            nline;
            cout<<"Enter room type : ";
            cin>>room_type;
            verify_room_type();
            nline;
            cout<<"Thank you for your response"<<endl;
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
            catch(int age){
                cout<<"\nEntered age is invalid.";
                invalid = true;
            }
        }

        void verify_income(){
            try{
                if (income<50000 || income>100000){
                    throw(income);
                }
            }
            catch(int income){
                cout<<"\nEntered income is invalid.";
                invalid = true;
            }
        }

        void verify_city(){
            try{
                if(city != "Pune" && city!="Mumbai"){
                    throw(city);
                }
            }
            catch(string city){
                cout<<"\nInvalid city";
                invalid = true;
            }
        }

        void verify_room_type(){
            try{
                if(room_type != "Delux" && room_type !="Super_Delux"){
                    throw(room_type);
                }
            }
            catch(string room_type){
                cout<<"\nInvalid room type entered."<<endl;
                invalid = true;
            }
        }
};

int main(){
    
    Hotel h;
    h.accept();
    nline;
    
    if(invalid){
        cout<<"\nInvalid data entered. Please enter valid data.";
    }
    else{
        h.display();
    }
    return 0;
}