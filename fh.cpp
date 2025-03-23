// Problem Statement: 
// Implement file handling and File input output operations in C++  

// Create “BOOK.txt” file.
//  Put some text in the file created above
// Develop an object-oriented program in C++ to writes data to a file, reads it back, and displays the content in other file,Write a function in C++ to count the number of uppercase alphabets,to count letters present in a file, to count digits present in a file, to count white spaces present in a file, to count vowels present in a file using the file pointer concept

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

class Book{
    public:
    void writedata(){
        ofstream file("BOOK.txt");
        if(!file){
            cout<<"\nError in creating file..\n"<<endl;
            return;
        }
        string s;
        cout<<"Enter the text to be written in the file : \n";
        while(getline(cin, s), s!=""){
            file<<s<<endl;
        }
        file.close();
    }

    void readback(){
        ifstream file("BOOK.txt");
        ofstream file2("BOOK2.txt");
        if(!file2){
            cout<<"\nError in creating file..\n"<<endl;
            return;
        }
        if(!file){
            cout<<"\nError in opening the file..\n"<<endl;
            return;
        }
        string s;
        cout<<"\nTransferring contents to BOOK2.txt \n";
        while(getline(file, s)){
            file2<<s<<endl;
        }
    }

    void count_uppercase(){
        ifstream file("BOOK.txt");
        if(!file){
            cout<<"\nError in opening the file..\n"<<endl;
            return;
        }
        char ch;
        int count = 0;

        while(file.get(ch)){
            if(isupper(ch)){
                count++;
            }
        }
        cout<<"\nNumber of uppercase alphabets in the file are : "<<count<<endl;
    }

    void count_letters(){
        ifstream file("BOOK.txt");
        if(!file){
            cout<<"\nError in opening the file..\n"<<endl;
            return;
        }
        char ch;
        int count = 0;

        while(file.get(ch)){
            if(isalpha(ch)){
                count++;
            }
        }
        cout<<"\nNumber of letters in the file are : "<<count<<endl;
    }

    void count_digits(){
        ifstream file("BOOK.txt");
        if(!file){
            cout<<"\nError in opening the file..\n"<<endl;
            return;
        }
        char ch;
        int count = 0;

        while(file.get(ch)){
            if(isdigit(ch)){
                count++;
            }
        }
        cout<<"\nNumber of digits in the file are : "<<count<<endl;
    }

    void count_whitespaces(){
        ifstream file("BOOK.txt");
        if(!file){
            cout<<"\nError in opening the file..\n"<<endl;
            return;
        }
        char ch;
        int count = 0;

        while(file.get(ch)){
            if(isspace(ch)){
                count++;
            }
        }
        cout<<"\nNumber of whitespaces in the file are : "<<count<<endl;
    }

    void count_vowels(){
        ifstream file("BOOK.txt");
        if(!file){
            cout<<"\nError in opening the file..\n"<<endl;
            return;
        }
        char ch;
        int count = 0;

        while(file.get(ch)){
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U'){
                count++;
            }
        }
        cout<<"\nNumber of vowels in the file are : "<<count<<endl;
    }


    void count(){
        count_uppercase();
        count_letters();
        count_digits();
        count_whitespaces();
        count_vowels();
    }

    void display(){
        ifstream file("BOOK2.txt");
        if(!file){
            cout<<"\nError in opening the file..\n"<<endl;
            return;
        }
        string s;
        cout<<"\nContents of the file are: \n";
        while(getline(file, s)){
            cout<<s<<endl;
        }
    }


};

int main(){
    Book b;
    b.writedata();
    b.readback();
    b.display();
    b.count();
    return 0;
}