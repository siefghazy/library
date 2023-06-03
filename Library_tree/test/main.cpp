#include <bits/stdc++.h>
using namespace std;
#include "book.h"
#include "bst.h"
BST readBooks(ifstream&file, BST&r)
{
    string C;
    string A;
    string T;
    string numberOfpages;
    string numOfbooks;
    getline(file,numOfbooks);
    for(int i = 0 ; i<stoi(numOfbooks); i++ )
    {
        getline(file,T);
        getline(file,A);
        getline(file,C);
        getline(file,numberOfpages);
        r.insert(T,A,C,stoi(numberOfpages));

    }
    return r;
}
int main()
{
    ifstream inFile("reading.txt");
    BST ll;
    BST RR;
    RR=readBooks(inFile,ll);
    bool statues=true;
    int choice;
    string title;
    string author;
    string category;
    int pageNum;
    while(1)
    {
        cout<<"1-Display all books sorted by title ascendingly"<<endl;
        cout<<"2-Display all books sorted by title descendingly"<<endl;
        cout<<"3-Remove a book by title"<<endl;
        cout<<"4-Add a new book"<<endl;
        cout<<"5-Search for a book by title"<<endl;
        cout<<"6-Display certain author's books"<<endl;
        cout<<"7-Display certain category's books"<<endl;
        cout<<"--------------------"<<endl;
        cout<<"enter your choice: ";
        cin>>choice;
        cout<<endl;
        if(choice==1)
        {
            RR.traverseASC();
            continue;
        }
        else if(choice==2)
        {
            RR.traverseDSC();
            continue;
        }
        else if(choice==3)
        {
            cout<<"enter the book title that you want to delete: ";
            cin.ignore();
            getline(cin,title);
            RR.Delete(title);
            cout<<endl;
            continue;
        }
        else if(choice==4)
        {
            cout<<"enter the title of the book: ";
            cin.ignore();
            getline(cin,title);
            cout<<endl;
            cout<<"enter the Author: ";
            cin.ignore();
            getline(cin,author);
            cout<<endl;
            cout<<"enter the category of the book: ";
            cin.ignore();
            getline(cin,category);
            cout<<endl;
            cout<<"enter the page number of the book: ";
           cin>>pageNum;
            cout<<endl;
            RR.insert(title,author,category,pageNum);
            continue;
        }
        else if(choice==5)
        {
            cout<<"enter the title of the book: ";
            cin.ignore();
            getline(cin,title);
            if(RR.searchTitle(title)==true)
            {
                cout<<"found"<<endl;
            }
            else
            {
                cout<<"not found"<<endl;
            }
            continue;
        }
        else if(choice==6)
        {
            cout<<"enter the author: ";
            cin.ignore();
            getline(cin,author);
            cout<<endl;
            RR.searchAuthor(author);
            continue;
        }
        else if(choice==7)
        {
            cout<<"enter the category: ";
            cin.ignore();
            getline(cin,category);
            cout<<endl;
            RR.searchCategory(category);
            continue;
        }
        else
        {
            break;
        }
    }
    return 0;
}
