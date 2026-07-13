#include<iostream>
#include<fstream>
using namespace std;

string bookID[3];
string title[3];
string author[3];
double price[3];
int quantity[3];

int main(){

    ofstream file("books.txt");

    if(!file){
        cout<<"Error: Unable to open file."<<endl;
        return 1;
    }

    cout<<"=========== BOOK RECORD SYSTEM ==========="<<endl;
    cout<<endl;

    for(int i = 0; i < 3; i++){

        cout<<"Book "<<i + 1<<endl;

        cout<<"Enter Book ID: ";
        cin>>bookID[i];

        cin.ignore();

        cout<<"Enter Book Title: ";
        getline(cin,title[i]);

        cout<<"Enter Author: ";
        getline(cin,author[i]);

        cout<<"Enter Price: ";
        cin>>price[i];

        cout<<"Enter Quantity: ";
        cin>>quantity[i];
        cin.ignore();

        try{

            if(bookID[i].empty())
                throw "Book ID cannot be empty.";

            if(title[i].empty())
                throw "Book Title cannot be empty.";

            if(author[i].empty())
                throw "Author cannot be empty.";

            if(price[i] <= 0)
                throw "Price must be greater than zero.";

            if(quantity[i] < 0)
                throw "Quantity cannot be negative.";

            file<<bookID[i]<<endl;
            file<<title[i]<<endl;
            file<<author[i]<<endl;
            file<<price[i]<<endl;
            file<<quantity[i]<<endl;

            cout<<"Book saved successfully!"<<endl<<endl;

        }

        catch(const char* message){
            cout<<"Error: "<<message<<endl<<endl;
        }

    }

    file.close();

    cout<<endl;
    cout<<"========= BOOK RECORDS =========="<<endl<<endl;

    ifstream loadFile("books.txt");

    try{

        if(!loadFile){
            throw "Unable to open file.";
        }

        for(int i = 0; i < 3; i++){

            getline(loadFile,bookID[i]);
            getline(loadFile,title[i]);
            getline(loadFile,author[i]);
            loadFile>>price[i];
            loadFile>>quantity[i];
            loadFile.ignore();

        }

    }

    catch(const char* message){
        cout<<"Error: "<<message<<endl;
        return 1;
    }

    loadFile.close();

    for(int i = 0; i < 3; i++){

        cout<<"Book "<<i + 1<<endl;
        cout<<"Book ID  : "<<bookID[i]<<endl;
        cout<<"Title    : "<<title[i]<<endl;
        cout<<"Author   : "<<author[i]<<endl;
        cout<<"Price    : "<<price[i]<<endl;
        cout<<"Quantity : "<<quantity[i]<<endl;
        cout<<"--------------------------"<<endl;

    }

    return 0;
}