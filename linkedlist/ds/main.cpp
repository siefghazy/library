#include<iostream>
#include<fstream>
#include<string>
#include "linkedlist.h"
#include "book.h"
using namespace std ;


int main()
{
    ifstream infile("reading.txt");
    string C;
    string A;
    string T;
    linkedlist ll;
    string numberOfpages;
    string numOfbooks;
    getline(infile,numOfbooks);
    ll.setlength(stoi(numOfbooks));
    for(int i = 0 ; i<stoi(numOfbooks); i++ )
    {
        getline(infile,T);
        getline(infile,A);
        getline(infile,C);
        getline(infile,numberOfpages);
        ll.add(T,A,C,stoi(numberOfpages));
    }
    ll.display();
    cout<<"                 "<<endl;
    cout<<"                  "<<endl;
    ll.add("Outliers","Malcolm Gladwell","Self Help",309);
    ll.sorting();
    ll.display();
    cout<<"                  "<<endl;
    cout<<"                  "<<endl;
    ll.displayCategory("Novels");
    cout<<"                 "<<endl;
    cout<<"                 "<<endl;
    ll.removeAuthor("Paulo Koelho");
    cout<<"                 "<<endl;
    cout<<"                 "<<endl;
    ll.removeAuthor("Paulo Coelho");
    cout<<"                 "<<endl;
    cout<<"                 "<<endl;
    ll.displayCategory("Novels");
    cout<<"                     "<<endl;
    cout<<"                     "<<endl;
    ll.removeTitle("pecoming");
    cout<<"                 "<<endl;
    cout<<"                 "<<endl;
    ll.removeTitle("Becoming");
    cout<<"                 "<<endl;
    cout<<"                 "<<endl;
    ll.displayAutor("Michelle Obama");
    cout<<"                 "<<endl;
    cout<<"                 "<<endl;
    ll.display();
    return 0;
}
