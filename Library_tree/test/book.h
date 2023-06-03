#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED

class book
{
    string title;
    string author;
    string category;
    int numOfpages;
public:
    book() {}
    book(string t,string a, string c,int n)
    {
        title=t;
        author=a;
        category=c;
        numOfpages=n;
    }
    void setTitle(string t)
    {
        title=t;
    }
    void setAuthor(string a)
    {
        author=a;
    }
    void setCategory(string c)
    {
        category=c;
    }
    void setPagenum(int x )
    {
        numOfpages=x;
    }
    string getTitle()
    {
        return title;
    }
    string getAuthor()
    {
        return author;
    }
    string getCatorgety()
    {
        return category;
    }
    int getNumofpages()
    {
        return numOfpages;
    }
    book operator=(const book&obj)
    {
        book temp;
        temp.title=obj.title;
        temp.category=obj.category;
        temp.author=obj.author;
        temp.numOfpages=obj.numOfpages;
        return temp;
    }
    bool operator<(const book& obj)
    {
        bool statues;
        if(title<=obj.title)
        {
            statues =true;
            return statues;
        }
        else
        {
            statues=false;
            return statues;
        }
    }
    void display()
    {
        cout<<title<<endl;
        cout<<author<<endl;
        cout<<category<<endl;
        cout<<numOfpages<<endl;
        cout<<"_______________"<<endl;
    }
};

#endif // BOOK_H_INCLUDED
